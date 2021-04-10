
/*************
Author:Yunchuan Ni 
Description:CCU4模块的一个基本的定时器功能，定时时长由CCU4外设时钟（120M/分频系数）和周期值决定
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "CCU4.h"
#include "Irq_Handle.h"

int main(void)
{
	CCU4_Init();
	CCU40_CC40_Start();
	IRQ_Enable();
	
	while(1)
	{
	}
}


