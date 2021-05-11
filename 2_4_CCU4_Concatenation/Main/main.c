
/*************
Author:Yunchuan Ni 
Description:此程序在Counter的基础上 实现定时器级联功能 40 41级联定时器 中断内翻转P1.1  42对P1.1上升沿计数
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
		Rising_Edge_Count = (CCU40_CC42->TIMER)&0x0000FFFF;    //上升沿计数的个数
	}
}


