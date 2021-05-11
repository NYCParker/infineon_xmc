
/*************
Author:Yunchuan Ni 
Description:CCU4模块实现对外部事件捕获，这里用引脚自身的拉高拉低模拟外部输入，并用CCU40 CC41对其两个上升沿之间进行捕获
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
		//获取捕获的值一般在捕获中断中进行处理
	}
}


