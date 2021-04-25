#include "Sys_Task.h"
#include "GPIO.h"
#include <xmc_gpio.h>
#include "Var_Init.h"
#include "portmacro.h"
#include "FreeRTOS.h"

//定义任务栈
#define TASK1_STACK_SIZE 128    
StackType_t Task1Stack[TASK1_STACK_SIZE];   //512个字节 FreeRTOS推荐的最小的任务栈 为任务堆栈开辟的内存 首位地址在数组第一个元素 栈空时 栈顶在最后一个元素的位置

#define TASK2_STACK_SIZE 128
StackType_t Task1Stack[TASK2_STACK_SIZE];

//定义任务控制块
TCB_t Task1TCB;
TCB_t Task2TCB;

//software delay
void delay_Xms(uint16_t ticx)        //误差 0us
{
	uint16_t tici;
    unsigned char tica,ticb,ticc;
	
	for(tici=0; tici<ticx; tici++)
    {
	   for(ticc=1;ticc>0;ticc--)
         for(ticb=98;ticb>0;ticb--)
           for(tica=230;tica>0;tica--);
	}
}

//Task1
void Task1_Entry(void *p_arg)
{	
	for( ;; )
	{
		delay_Xms(500);
		XMC_GPIO_ToggleOutput(GPIO_LED1);
	}
}

//Task2
void Task2_Entry(void *p_arg)
{	
	for( ;; )
	{
		delay_Xms(500);
		XMC_GPIO_ToggleOutput(GPIO_LED2);
	}
}
