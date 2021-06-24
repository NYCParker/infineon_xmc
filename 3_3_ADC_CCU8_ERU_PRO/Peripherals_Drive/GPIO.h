#ifndef _GPIO_h
#define _GPIO_h

#include <XMC4400.h>

#define Iu_ADC  P14_0  //G0CH0
#define Iv_ADC  P14_4  //G2CH0
#define Vbus_ADC P14_3 //G0CH3
#define Force_ADC P14_5 //G0CH5

#define GPIO_LED1  P2_0
#define GPIO_LED2  P2_1

//ÁùÂ·PWM
#define PWM_UH	P0_5
#define PWM_UL 	P0_2
#define PWM_VH 	P0_4
#define PWM_VL 	P0_1
#define PWM_WH 	P0_3
#define PWM_WL 	P0_0

#define MOS_Enable P0_9

#define BRAKE P2_4

#define U_P  P0_6
#define V_P  P0_11
#define W_P  P0_7
#define B_P  P0_8

extern void GPIO_Init(void);
extern void ERU0_Init(void);
#endif
