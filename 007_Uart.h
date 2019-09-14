
//       10        20        30        40        50        60        70
//--*----*----*----*----*----*----*----*----*----*----*----*----*----*----*----*

/******************************************************************************
 * A library for PIC24F UART1(for debug) & UART2(for BG96)
 * This file is about the UART API of PIC24
 *
 * Copyright (c) 2019 Mobit technology inc.
 * @Author       : Damon
 * @Create time  : 03/11/2019
******************************************************************************/

#ifndef MUART_H
#define MUART_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "015_Common.h"
    
// for debug
void Uart1_Init(void);

u8 SCISendDataOnISR(u8 *sendbuf,u16 size);

#ifdef __cplusplus
}
#endif

#endif /* MUART_H */
