
/*************
Author:Yunchuan Ni 
Description: DAC 输出 常用于DEBUG或者运放电路的失调电压输出
//DAC基本需要输入一个恒定的电压即可，直接用XMC的库函数配置
*************/

/*
main函数
*/

#include <XMC4400.h>
#include "DAC.h"
#include "Irq_Handle.h"

int main(void)
{
	DAC_Init();
	
	DAC_Output0(4095);
	DAC_Output1(2000);
	
	while(1)
	{
	}
}


