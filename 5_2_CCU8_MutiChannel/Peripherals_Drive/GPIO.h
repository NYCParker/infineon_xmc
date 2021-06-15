#ifndef _GPIO_h
#define _GPIO_h

#include <XMC4400.h>

//ÁùÂ·PWM
#define PWM_UH	P0_5
#define PWM_UL 	P0_2
#define PWM_VH 	P0_4
#define PWM_VL 	P0_1
#define PWM_WH 	P0_3
#define PWM_WL 	P0_0

extern void GPIO_Init(void);
	
#endif
