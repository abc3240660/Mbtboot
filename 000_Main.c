//       10        20        30        40        50        60        70
//--*----*----*----*----*----*----*----*----*----*----*----*----*----*----*----*

/******************************************************************************
 * Entrance of Application
 * This file is entrance of APP
 *
 * Copyright (c) 2019 Mobit technology inc.
 * @Author       : Damon
 * @Create time  : 03/11/2019
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <p24fxxxx.h>

#include "006_Gpio.h"
#include "007_Uart.h"
#include "009_System.h"
#include "014_md5.h"
#include "016_FlashOta.h"
#include "017_InnerFlash.h"

void delay_ms(unsigned long val)
{
    u32 i = 0;
    u32 j = 0;

    for (i=0; i<val; i++) {
        for (j=0; j<718; j++) {
            // NOP
        }
    }
}

static bool CheckIapRequest(void)
{
    u8 strs_array[LEN_BYTE_SZ64+1] = "";

    if (FOR_FAKE_USE) {
        FlashWrite_SysParams(PARAM_ID_IAP_FLAG, (u8*)IAP_REQ_ON, 4);
        FlashWrite_SysParams(PARAM_ID_IAP_MD5, (u8*)"11112222333344445555666677778888", 32);
        FlashWrite_SysParams(PARAM_ID_RSVD_U1, (u8*)"121348", 6);
    }

    FlashRead_SysParams(PARAM_ID_IAP_FLAG, strs_array, LEN_BYTE_SZ64);

    if (0 == strncmp((const char*)strs_array, (const char*)IAP_REQ_ON, strlen(IAP_REQ_ON))) {
        return true;
    } else {
        return false;
    }
}

static u32 GetIapBinSize(void)
{
    u16 i = 0;
    u32 size = 0;
    u8 strs_array[LEN_BYTE_SZ64+1] = "";

    FlashRead_SysParams(PARAM_ID_RSVD_U1, strs_array, LEN_BYTE_SZ64);

    for (i=0; i<8; i++) {
        if ((strs_array[i]<'0') || (strs_array[i]>'9')) {// Invalid Data In "BIN SIZE" Flash Section
            strs_array[i] = 0;
            break;
        }
    }

    for (i=0; i<strlen((const char*)strs_array); i++) {
        size *= 10;
        size += strs_array[i] - '0';
    }

    return size;
}

static bool CheckIapMd5(u32 bin_size, u32 inwd_count)
{
    u16 i = 0;
    u32 data_len = 0;
    u32 page_count = 0;
    u16 flash_page = 0;
    u32 flash_offset = 0;
    u8 strs_array[LEN_BYTE_SZ64 + 1] = "";
    u8 bytes_array[CNTR_INWD_PER_PAGE * BYTE_DATA_PER_INWD] = {0};

    MD5_CTX iapbin_md5_ctx;
    u8 iapbin_res_md5[LEN_COMMON_USE] = "";

    if ((0==bin_size) || (0==inwd_count)) {
        return false;
    }

    GAgent_MD5Init(&iapbin_md5_ctx);

    data_len = CNTR_INWD_PER_PAGE * BYTE_DATA_PER_INWD;
    page_count = ((inwd_count+CNTR_INWD_PER_PAGE-1) / CNTR_INWD_PER_PAGE);

    for (i=0; i<page_count; i++) {
        flash_offset = FLASH_BASE_BAK + (i * BYTE_ADDR_PER_PAGE_SML);

        // if (0 == (flash_offset % BYTE_ADDR_PER_PAGE_LRG)) {
            flash_page = FLASH_PAGE_BAK + (flash_offset / BYTE_ADDR_PER_PAGE_LRG);
        // }

        flash_offset %= BYTE_ADDR_PER_PAGE_LRG;
        FlashRead_InstructionWordsToByteArray(flash_page, flash_offset, CNTR_INWD_PER_PAGE, bytes_array);

        if (i == (page_count-1)) {
            data_len = (bin_size - CNTR_INWD_PER_BLK*BYTE_DATA_PER_INWD) % (CNTR_INWD_PER_PAGE*BYTE_DATA_PER_INWD);
        }

        GAgent_MD5Update(&iapbin_md5_ctx, bytes_array, data_len);
    }

    GAgent_MD5Final(&iapbin_md5_ctx, iapbin_res_md5);

    FlashRead_SysParams(PARAM_ID_IAP_MD5, strs_array, LEN_BYTE_SZ64);

    if (0 == strncmp((const char*)iapbin_res_md5, (const char*)strs_array, LEN_BYTE_SZ32)) {
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    u32 i = 0;
    u32 j = 0;
    u32 flash_page = 0;
    u32 flash_offset = 0;

    System_Config();
    Uart1_Init();

    delay_ms(3000);

    printf("Bootloader running...\n");

#if 0
    for (i=0; i<44; i++) {
        flash_offset = FLASH_BASE_BAK + (i * BYTE_ADDR_PER_PAGE_SML);
        flash_page = FLASH_PAGE_BAK + (flash_offset / BYTE_ADDR_PER_PAGE_LRG);
        
        printf("WR flash_address = 0x%X-%.4X\n", (u16)(flash_page-2), (u16)flash_offset);
        
        delay_ms(1000);
    }
    
    while(1);
#endif

    if (true == CheckIapRequest()) {// IAP BIN Existing, Need Do IAP...
        // In Bytes, BIN File will not contain 1B dummy data
        u32 bin_size = 0;
        u32 inwd_count = 0;
        u32 page_count = 0;

        OneInstruction_t dat[CNTR_INWD_PER_PAGE];

        // to store all of the byte data of One Whole Page
        u8 bytes_array[CNTR_INWD_PER_PAGE * BYTE_DATA_PER_INWD] = {0};

        bin_size = GetIapBinSize();
        inwd_count = ((bin_size+BYTE_DATA_PER_INWD-1) / BYTE_DATA_PER_INWD);

#ifdef PRINT_DBG_ENABLE
        printf("bin_size = %ld, inwd_count = %ld\n", bin_size, inwd_count);
#endif

        flash_page = FLASH_PAGE_BAK;// 0x2,2000

        // ----------------
        // --------
        // First calc the md5 of IAP BIN file in the BAK partition
        // And then compare with the SIZE Params from TCP Info in APP
        if (false == CheckIapMd5(bin_size, inwd_count)) {
            // Erase APP
            FlashErase_LargePage(FLASH_PAGE_APP, FLASH_BASE_APP);// SIZE: 0xE000
            FlashErase_LargePage(FLASH_PAGE_APP+1, 0);// SIZE: 0x10000

            delay_ms(3000);

            printf("Ready to IAP...\n");

            // ----------------
            // --------
            // Update IVT, don't change RST

            // Do not Modify two RST InstructionWords from 0x00000
            // So backup these two InstructionWords firstly
            FlashRead_InstructionWordsToByteArray(FLASH_PAGE_APP, 0, CNTR_INWD_PER_PAGE, bytes_array);
            for (j=0; j<2; j++) {
                dat[j].HighLowUINT16s.HighWord = bytes_array[3*j + 2];
                dat[j].HighLowUINT16s.LowWord  = bytes_array[3*j + 0] + (bytes_array[3*j + 1] * 256);

#ifdef PRINT_DBG_ENABLE
                printf("RST INWD[%d] = 0x%.2X%.2X%.2X\n", (u16)j, bytes_array[3*j+2], bytes_array[3*j+0], bytes_array[3*j+1]);
#endif
            }

            FlashRead_InstructionWordsToByteArray(FLASH_PAGE_BAK, 0, CNTR_INWD_PER_PAGE, bytes_array);
            for (j=0; j<CNTR_INWD_PER_PAGE; j++) {
                if (j > 1) {// Skip 2 * Non-Change Reset InstructionWords, Use the Old Data
                    dat[j].HighLowUINT16s.HighWord = bytes_array[3*j + 2];
                    dat[j].HighLowUINT16s.LowWord  = bytes_array[3*j + 0] + (bytes_array[3*j + 1] * 256);
                }
            }

#ifdef PRINT_DBG_ENABLE
            for (j=0; j<2; j++) {
                printf("RST INWD[%d] = 0x%.4X%.4X\n", (u16)j, dat[j].HighLowUINT16s.HighWord, dat[j].HighLowUINT16s.LowWord);
            }
#endif

            // In the first page, only 128 INWDs used for RST+IVT, (1024-128) INWDs unused
            FlashEraseWrite_InstructionWords(FLASH_PAGE_APP, 0, dat, CNTR_INWD_PER_PAGE);

            // ----------------
            // --------
            // Update Code Data

            // CNTR_INWD_PER_BLK: Skip RST+IVT Section(0x0000-0x0100)
            page_count = ((inwd_count-CNTR_INWD_PER_BLK+CNTR_INWD_PER_PAGE-1) / CNTR_INWD_PER_PAGE);

#ifdef PRINT_DBG_ENABLE
            printf("page_count = %ld\n", page_count);
#endif

            // BAK -> APP
            for (i=0; i<page_count; i++) {
                flash_offset = FLASH_BASE_BAK + (i * BYTE_ADDR_PER_PAGE_SML);

                // if (0 == (flash_offset % BYTE_ADDR_PER_PAGE_LRG)) {
                    flash_page = FLASH_PAGE_BAK + (flash_offset / BYTE_ADDR_PER_PAGE_LRG);
                // }

                flash_offset %= BYTE_ADDR_PER_PAGE_LRG;
                FlashRead_InstructionWordsToByteArray(flash_page, flash_offset, CNTR_INWD_PER_PAGE, bytes_array);

                for (j=0; j<CNTR_INWD_PER_PAGE; j++) {
                    dat[j].HighLowUINT16s.HighWord = bytes_array[3*j + 2];
                    dat[j].HighLowUINT16s.LowWord  = bytes_array[3*j + 0] + (bytes_array[3*j + 1] * 256);
                }

#ifdef PRINT_DBG_ENABLE
                printf("WR flash_address = 0x%X-%.4X\n", (u16)(flash_page-2), (u16)flash_offset);
#endif

                FlashWrite_InstructionWords(flash_page-2, flash_offset, dat, CNTR_INWD_PER_PAGE);

                delay_ms(100);
            }

            FlashWrite_SysParams(PARAM_ID_IAP_FLAG, (u8*)IAP_REQ_OK, 4);

            printf("IAP Success.\n");
        } else {
            FlashWrite_SysParams(PARAM_ID_IAP_FLAG, (u8*)IAP_REQ_NG, 4);
        }
    }

    // Jump into APP
    printf("Ready to Jump APP...\n");
    (*((void(*)(void))0x2000))();
    printf("Jump APP Failed.\n");

    return 0;
}
