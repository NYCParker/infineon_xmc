#ifndef _USIC_h
#define _USIC_h

#include <XMC1300.h>

//#define FDR_STEP	290
//#define BRG_PDIV	58
//#define BRG_DCTQ	15
//#define BRG_PCTQ	0    //9600

//#define FDR_STEP	590
//#define BRG_PDIV	19
//#define BRG_DCTQ	15
//#define BRG_PCTQ	0    //57600

//#define FDR_STEP	177
//#define BRG_PDIV	2
//#define BRG_DCTQ	15
//#define BRG_PCTQ	0    //115200

extern void UART_Init(void);
extern void UART_SendData(uint16_t Send_Data);

#endif
