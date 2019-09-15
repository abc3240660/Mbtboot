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

static MD5_CTX g_ftp_md5_ctx;
static u8 gs_ftp_res_md5[LEN_COMMON_USE] = "";

void delay_ms(unsigned long val)
{
    u32 i = 0;
    u32 j = 0;

    for (i=0; i<val; i++) {
        for (j=0; j<1150; j++) {
            // NOP
        }
    }
}

void MD5Update(u8* buf, u16 len)
{
    GAgent_MD5Update(&g_ftp_md5_ctx, buf, len);
}

void FlashSectionMove_Test(void)
{
    u16 i = 0;
    u32 test_cnt = 0;
    OneInstruction_t dat[1024];
    unsigned char sTestBuf20000[1024]={0};

    printf("9876543--\n");

//    FlashErase_LargePage(2);
    FlashErase_LargePage(3);
    FlashErase_LargePage(4);
    FlashErase_LargePage(5);

    printf("8765432--\n");

    delay_ms(3000);

    while(1)
    {
        if (100 == test_cnt++) {
            // DataRecord_WriteBytesArray(1, 0x100, u16 index, u8 *data, u16 length)
        }

        if (100 == test_cnt++) {
            FlashRead_InstructionWordsToByteArray(2,0,1024/4,sTestBuf20000);

            for(i=0;i<256;i++)
            {
                //dat[i].HighLowUINT16s.HighWord=i+i*256;
                dat[i].HighLowUINT16s.HighWord=sTestBuf20000[3*i+2];
                dat[i].HighLowUINT16s.LowWord=sTestBuf20000[3*i+0]+(sTestBuf20000[3*i+1])*256;
            }            
            FlashWrite_InstructionWords(3,0,dat,1024/4);
            printf("8880888--\n");
            FlashWrite_InstructionWords(1,0x7800,dat,1024/4);
        }
        
        if (0 == test_cnt%10) {
            printf("7654321--\n");
        }
        
        delay_ms(100);
    }
}

bool CheckIapRequest(void)
{
    u8 strs_array[LEN_BYTE_SZ64+1] = "";

    if (FOR_DEBUG_USE) {
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

u32 GetIapBinSize(void)
{
    u16 i = 0;
    u32 size = 0;
    u8 strs_array[LEN_BYTE_SZ64+1] = "";
    
    FlashRead_SysParams(PARAM_ID_RSVD_U1, strs_array, LEN_BYTE_SZ64);

    for (i=0; i<8; i++) {
        if ((strs_array[i]<'0') && (strs_array[i]>'9')) {
            return 0;
        }
    }
    
    for (i=0; i<strlen((const char*)strs_array); i++) {
        size *= 10;
        size += strs_array[i] - '0';
    }

    return size;
}

bool CheckIapMd5(u8 *calc_md5)
{
    u8 strs_array[LEN_BYTE_SZ64+1] = "";
    
    FlashRead_SysParams(PARAM_ID_IAP_MD5, strs_array, LEN_BYTE_SZ64);
    
    if (0 == strncmp((const char*)calc_md5, (const char*)strs_array, LEN_BYTE_SZ32)) {
        return true;
    } else {
        return false;
    }
}

int main()
{ 
    u16 i = 0;
    u16 j = 0;
    u16 flash_page = FLASH_PAGE_APP;
    u16 flash_offset = 0;
    static u16 wraddr=0;
    static u8 sTestBuf20000[1024]={0};
    static u8 gFlashBuf[1500]={0};
    static  OneInstruction_t dat[1024];

    System_Config();
    Uart1_Init();

    delay_ms(3000);

//    SCISendDataOnISR((u8*)"9876543--",9);

    printf("Bootloader running...\n");

#if 0
    delay_ms(3000);

    wraddr=1*0x200;  
    FlashRead_InstructionWordsToByteArray(0,0x5000,1024/4,gFlashBuf);                        
    for(i=0;i<256;i++)
    {
        dat[i].HighLowUINT16s.HighWord=gFlashBuf[3*i+2];
        dat[i].HighLowUINT16s.LowWord=gFlashBuf[3*i+0]+(gFlashBuf[3*i+1])*256;
    }            
    FlashWrite_InstructionWords(2,0x2000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(2,0x3000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(2,0x4000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(2,0x8000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(2,0xA000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(2,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(3,0x0000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(3,0x8000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(3,0x9000+wraddr,dat,1024/4); 
    delay_ms(1000);
    FlashWrite_InstructionWords(3,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654350",9);
    FlashWrite_InstructionWords(4,0x0000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654354",9);
    FlashWrite_InstructionWords(4,0x4000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654355",9);
    FlashWrite_InstructionWords(4,0x5000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654554",9);
    FlashWrite_InstructionWords(4,0x5400+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654556",9);
    FlashWrite_InstructionWords(4,0x5600+wraddr,dat,1024/4); 
    delay_ms(1000);
//    SCISendDataOnISR("987654558",9);
//    DataRecord_WriteDataArray(5,0x5800+wraddr,dat,1024/4); 

    SCISendDataOnISR("876666210",9);
#endif

#if 0
    delay_ms(3000);

    wraddr=1*0x200;  
    DataRecord_ReadData(0,0x5000,1024/4,gFlashBuf);                        
    for(i=0;i<256;i++)
    {
        dat[i].HighLowUINT16s.HighWord=gFlashBuf[4*i+2]+(gFlashBuf[4*i+3])*256;
        dat[i].HighLowUINT16s.LowWord=gFlashBuf[4*i+0]+(gFlashBuf[4*i+1])*256;
    }            
    DataRecord_WriteDataArray(1,0x0000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(1,0x1000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(1,0x4000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(1,0x8000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(1,0xA000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(1,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(2,0x0000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(2,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(3,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    DataRecord_WriteDataArray(4,0xF000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654350",9);
    DataRecord_WriteDataArray(5,0x0000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654354",9);
    DataRecord_WriteDataArray(5,0x4000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654355",9);
    DataRecord_WriteDataArray(5,0x5000+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654554",9);
    DataRecord_WriteDataArray(5,0x5400+wraddr,dat,1024/4); 
    delay_ms(1000);
    SCISendDataOnISR("987654556",9);
    DataRecord_WriteDataArray(5,0x5600+wraddr,dat,1024/4); 
    delay_ms(1000);
//    SCISendDataOnISR("987654558",9);
//    DataRecord_WriteDataArray(5,0x5800+wraddr,dat,1024/4); 

    SCISendDataOnISR("876555210",9);
#endif

#if 0
    printf("Before delay\n");

    delay_ms(3000);
    
    printf("After delay\n");

    printf("before jump\n");
    (*((void(*)(void))0x30000))(); 
    printf("after jump\n");
        
    if (false == CheckIapRequest()) {// Need Move BAK into APP
        u32 bin_size = GetIapBinSize();// In Bytes
        u32 in_word_count = ((bin_size+2)/3);
        u32 page_count = ((in_word_count+1023)/1024);

        u32 md5_len = 1024*3;

        u8 bytes_array[1024*3]={0};
        OneInstruction_t dat[1024];
        
        printf("bin_size = %ld, page_count=%ld\n", bin_size, page_count);
#if 1
        GAgent_MD5Init(&g_ftp_md5_ctx);
        
        for (i=0; i<page_count; i++) {
            if (0 == (i%1024)) {
                flash_page = FLASH_PAGE_BOT + page_count/1024;
            }
            
            flash_offset = (i * 0x800) % 0x10000;

            FlashRead_InstructionWordsToByteArray(flash_page, flash_offset, 1024, bytes_array);
            
            if (i == (page_count-1)) {
                md5_len = bin_size % (1024*3);
            }
            
            GAgent_MD5Update(&g_ftp_md5_ctx, bytes_array, md5_len);
        }
        
        GAgent_MD5Final(&g_ftp_md5_ctx, gs_ftp_res_md5);

        CheckIapMd5(gs_ftp_res_md5);

        // Erase APP
        FlashErase_LargePage(FLASH_PAGE_APP);
        FlashErase_LargePage(FLASH_PAGE_APP+1);

        printf("after erase\n");

        delay_ms(3000);
        
        printf("before write\n");

#if 1
        // BAK -> APP
        for (i=0; i<page_count; i++) {
            if (0 == (i%1024)) {
                flash_page = FLASH_PAGE_BOT + page_count/1024;
            }
            
            flash_offset = (i * 0x800) % 0x10000;

            FlashRead_InstructionWordsToByteArray(flash_page, flash_offset, 1024, bytes_array);

            for(j=0; j<1024; j++)
            {
                dat[j].HighLowUINT16s.HighWord=bytes_array[3*j+2];
                dat[j].HighLowUINT16s.LowWord=bytes_array[3*j+0]+(bytes_array[3*j+1])*256;
            }

            printf("WR flash_address = 0x%X-%.4X\n", (flash_page-2), flash_offset);
            FlashWrite_InstructionWords(flash_page-2, flash_offset, dat, 1024);
            
            delay_ms(100);
        }
#endif

        printf("after write\n");
#endif
    } else {// Jump into APP
        printf("before jump\n");
        (*((void(*)(void))0x30000))(); 
        printf("after jump\n");
    }
#endif

//    (*((void(*)(void))0x2000))();

    while (1) {
        printf("7688821--\n");
        delay_ms(1000);
    }

    SCISendDataOnISR((u8*)"9876543--",9);

    SCISendDataOnISR((u8*)"8765432--",9);

#if 0            
    while(1)
    {
        if (300000 == test_cnt++) {
            FlashRead_InstructionWordsToByteArray(2,0,1024/4,sTestBuf20000);

            for(i=0;i<256;i++)
            {
                //dat[i].HighLowUINT16s.HighWord=i+i*256;
                //dat[i].HighLowUINT16s.LowWord=i+i*256;
                dat[i].HighLowUINT16s.HighWord=sTestBuf20000[4*i+2]+(sTestBuf20000[4*i+3])*256;
                dat[i].HighLowUINT16s.LowWord=sTestBuf20000[4*i+0]+(sTestBuf20000[4*i+1])*256;
            }            
            FlashWrite_InstructionWords(3,0,dat,1024/4);
            SCISendDataOnISR((u8*)"8888888--",9);
            FlashWrite_InstructionWords(1,0x5000,dat,1024/4);
        }
        
        if (0 == test_cnt%30000) {
            SCISendDataOnISR((u8*)"7654321--",9);
        }
    }
#endif

    return 0;
}