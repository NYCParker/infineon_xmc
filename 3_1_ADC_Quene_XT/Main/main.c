
/*
main函数
MCLK=32MHz，PCLK=64MHz 乱入一个XMC1300 定时器触发AD采样 串口发出（通信协议未定）
*/

#include <XMC1300.h>
#include "SCU.h"
#include "GPIO.h"
#include "CCU4.h"
#include "VADC.h"
#include "USIC.h"
#include "Irq_Handle.h"
#include "stdio.h"

int main(void)
{	
    SCU_Init();
	GPIO_Init();
	CCU4_Init();
	VADC_Init();
	UART_Init();
	IRQ_Enable();
	CCU40_CC40_Start();
    
	printf("开始运行：\n");
	
	while(1)
	{
		
    }
}

int fputc(int ch,FILE *f)
{
	UART_SendData(ch);
	return ch;
}