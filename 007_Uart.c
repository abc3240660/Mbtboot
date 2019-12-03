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

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <p24fxxxx.h>

#include "007_Uart.h"


// 115200
void Uart1_Init(void)
{
#ifndef OSC_20M_USE
#if 0
    _RP22R = 3;// RD3
    _U1RXR = 23;// RD2

    _LATD3 = 1;
    _TRISD2 = 1;
    _TRISD3 = 0;
#else
    _RP22R = 3;// RD3
    _U1RXR = 24;// RD1

    _LATD3 = 1;
    _TRISD1 = 1;
    _TRISD3 = 0;
#endif

    U1MODE = 0X8808;
    U1STA = 0X2400;
    // 4M/(34+1) = 114285
    U1BRG = 34;
#else
    _RP22R = 3;// RD3
    _U1RXR = 24;// RD1

    _LATD3 = 1;
    _TRISD1 = 1;
    _TRISD3 = 0;

    U1MODE = 0X8808;
    U1STA = 0X2400;
    // 4M/(34+1) = 114285
    U1BRG = 34;
#endif

    _U1TXIP = 3;
    _U1RXIP = 7;
    _U1TXIF = 0;
    _U1RXIF = 0;
    _U1TXIE = 0;
    _U1RXIE = 1;
}

int fputc(int ch,FILE * f)
{
    U1TXREG = ch;
    while(_U1TXIF == 0);
    _U1TXIF = 0;
    return ch;
}

int Uart1_Putc(char ch)
{
    U1TXREG = ch;
    while(_U1TXIF == 0);
    _U1TXIF = 0;
    return ch;
}

u8 SCISendDataOnISR(u8 *sendbuf,u16 size)
{ 

	while(size--)
	{     
           Uart1_Putc(*sendbuf);
 		sendbuf++;
	} 	
 	
    return (1) ;  
}

void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{
    char temp = 0;

    do {
        temp = U1RXREG;
        // Uart1_Putc(temp);
        _U1RXIF = 0;
        if (U1STAbits.OERR) {
            U1STAbits.OERR = 0;
        } else {
            // printf("%.2X\n", temp);
            // ringbuffer_write_byte(&tmp_rbuf,temp);
            // printf("recv len = %d\n", IsTmpRingBufferAvailable());
        }
    } while (U1STAbits.URXDA);
}