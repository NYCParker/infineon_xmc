
/*************
Author:Yunchuan Ni 
Description:GPIO口的DEMO裸机操作，作为FREERTOS系统移植的基础文件
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"
#include "GPIO.h"
#include "Var_Init.h"

int main(void)
{
	SysTick_Config(SystemCoreClock/1000);
	GPIO_Init();
	IRQ_Enable();
	
	while(1)
	{
	}
}


