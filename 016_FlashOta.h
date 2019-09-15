#ifndef _MCU_DRIVERS_DATARECORD_H_
#define _MCU_DRIVERS_DATARECORD_H_
 
#include "015_Common.h" 
#include "017_InnerFlash.h"
 
void FlashErase_LargePage(u16 pageIndex, u16 start_addr);
void FlashErase_OnePage(u16 flash_page, u16 flash_offset);

u16 FlashRead_InstructionWordsToByteArray(u16 flash_page, u16 flash_offset, u16 len, u8 *pdata);
u16 FlashWrite_InstructionWords(u16 flash_base, u16 flash_offset, OneInstruction_t *data, u16 length);

u16 FlashRead_SysParams(PARAM_ID params_id, u8 *data, u8 length);
u16 FlashWrite_SysParams(PARAM_ID params_id, u8 *data, u16 length);

void FlashWriteRead_ParamsTest(void);

#endif
