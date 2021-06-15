
/*************
Author:Yunchuan Ni 
Description: ADC同步采样
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "GPIO.h"
#include "ADC.h"
#include "Var_Init.h"
#include "Irq_Handle.h"

int main(void)
{
	ADC_Init();
	CCU80_Init();
	CCU80_Start();
	IRQ_Enable();
	delay_Xms(200);
	Cur_Calibration();
	
	while(1)
	{
	}
}


