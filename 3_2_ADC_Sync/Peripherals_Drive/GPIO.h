#ifndef _GPIO_h
#define _GPIO_h

#include <XMC4400.h>

#define Iu_ADC  P14_0  //G0CH0
#define Iv_ADC  P14_4  //G2CH0
#define Vbus_ADC P14_3 //G0CH3
#define Force_ADC P14_5 //G0CH5

extern void GPIO_Init(void);
	
#endif
