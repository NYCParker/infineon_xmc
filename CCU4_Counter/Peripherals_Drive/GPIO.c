/*
GPIO 计数用
CCU40 CC40 每隔一段时间翻转P1.2脚
CCU40 CC41 对P1.2脚的上升沿事件进行计数 
*/

#include <XMC4400.h>
#include "GPIO.h"
#include <xmc_gpio.h>

void GPIO_Init(void)
{
	XMC_GPIO_CONFIG_t config;
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;        
	XMC_GPIO_Init(Test_Output, &config);             //P1.2普通输出
}
