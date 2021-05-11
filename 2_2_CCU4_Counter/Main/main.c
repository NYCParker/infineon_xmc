
/*************
Author:Yunchuan Ni 
Description:CCU4模块实现对外部事件计数，这里用引脚自身的拉高拉低模拟外部输入，并用CCU40 CC41对其上升沿计数
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "CCU4.h"
#include "Irq_Handle.h"
#include "GPIO.h"
#include "Var_Init.h"

int main(void)
{
	GPIO_Init();
	CCU4_Init();
	CCU40_CC40_Start();
	CCU40_CC41_Start();
	IRQ_Enable();
	
	while(1)
	{
		Rising_Edge_Count = (CCU40_CC41->TIMER)&0x0000FFFF;    //上升沿计数的个数
	}
}


