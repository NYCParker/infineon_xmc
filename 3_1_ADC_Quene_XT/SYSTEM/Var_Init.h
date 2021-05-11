#ifndef _Var_Init_h
#define _Var_Init_h

#include <XMC1300.h>
#define REC_LENGTH  			200 

extern uint16_t Pressure_Sensor_Data[8];


extern uint16_t Receive_Data[REC_LENGTH];
extern uint8_t Receive_Count;
extern void Variable_Init(void);


	
#endif
