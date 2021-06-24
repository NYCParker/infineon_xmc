
/*************
Author:Yunchuan Ni 
Description: ADC,CCU8,POSIF 硬件测试 
高压电路 死区3us PWM周期10k
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "GPIO.h"
#include "ADC.h"
#include "Var_Init.h"
#include "Irq_Handle.h"
#include <xmc_gpio.h>

int main(void)
{
	GPIO_Init();
	ADC_Init();
	CCU80_Init();
	POSIF0_Init();
	
	delay_Xms(200);
	Cur_Calibration();
	
	XMC_GPIO_SetOutputHigh(MOS_Enable);
	XMC_GPIO_SetOutputLow(BRAKE);
	
	CCU80_Start();
	IRQ_Enable();
	
	
	Switch_on();
	
	while(1)
	{
	}
}


