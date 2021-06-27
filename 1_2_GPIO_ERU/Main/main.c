
/*************
Author:Yunchuan Ni 
Description:GPIO 利用 ERU事件请求实现中断 GPIO.C中
用产生PWM的管脚连接ERU的四个引脚 产生ERU中断
常用于快速保护，如IPM的故障信号引脚（如果没有硬件保护电路）
//实测发现 英飞凌的ERU 配置为与 作用为或 配置为或 作用为与 
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
	ERU0_Init();
	IRQ_Enable();
	
	while(1)
	{
		Rising_Edge_Count = (CCU40_CC41->TIMER)&0x0000FFFF;    //指示程序正在运行
	}
}


