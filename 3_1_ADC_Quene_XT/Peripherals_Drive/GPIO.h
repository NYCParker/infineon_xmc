#ifndef _GPIO_h
#define _GPIO_h

#include <XMC1300.h>
#include <xmc_gpio.h>

#define GPIO_LED1  P0_0
#define GPIO_LED2  P0_1
#define GPIO_LED3  P0_6
#define GPIO_LED4  P0_7
#define GPIO_LED5  P0_8
#define GPIO_LED6  P0_9

#define GPIO_RX  P1_3
#define GPIO_TX  P1_2

extern void GPIO_Init(void);

#endif
