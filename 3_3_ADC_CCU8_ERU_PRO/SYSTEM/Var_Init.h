#ifndef _Var_Init_h
#define _Var_Init_h

#include <XMC4400.h>

extern uint16_t Iu_ADC_Value;
extern uint16_t Iv_ADC_Value;
extern uint16_t Vbus_ADC_Value;
extern uint16_t Force_ADC_Value;

extern uint16_t Iu_ADC_Value_Ref;
extern uint16_t Iv_ADC_Value_Ref;
extern uint16_t Vbus_ADC_Value_Ref;
extern uint16_t Force_ADC_Value_Ref; 

extern int16_t Iu;
extern int16_t Iv;
extern int16_t Vbus;
extern int16_t Force; 

extern void delay_Xms(uint16_t ticx);
extern void Cur_Calibration(void);

extern uint8_t protect_flag;

#endif
