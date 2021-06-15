
/*************
Author:Yunchuan Ni 
Description: CCU8 POSIF多通道封波
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "GPIO.h"
#include "CCU8.h"
#include "Var_Init.h"
#include "Irq_Handle.h"

int main(void)
{
	GPIO_Init();
	CCU80_Init();
	POSIF0_Init();
	
	CCU80_Start();
	IRQ_Enable();

	Switch_on();
	//Switch_off();
	
	while(1)
	{
	}
}


