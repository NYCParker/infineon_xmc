
/*************
Author:Yunchuan Ni 
Description:在Capture基础上实现级联Capture 两次高电平时间捕获的更加精准（这一点在某些应用（例如电机低速测速）上很重要）
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
	CCU40_CC42_Start();
	CCU40_CC41_Start();
	CCU40_CC40_Start();
	IRQ_Enable();
	
	while(1)
	{
		//获取捕获的值一般在捕获中断中进行处理
	}
}


