
/*
GPIO 
*/

#include <XMC1300.h>
#include "GPIO.h"

void GPIO_Init(void)
{
	XMC_GPIO_CONFIG_t config;
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;        
	XMC_GPIO_Init(GPIO_LED1, &config);             
	XMC_GPIO_Init(GPIO_LED2, &config);
	XMC_GPIO_Init(GPIO_LED3, &config);             
	XMC_GPIO_Init(GPIO_LED4, &config); 
	XMC_GPIO_Init(GPIO_LED5, &config);             
	XMC_GPIO_Init(GPIO_LED6, &config); 
	
	config.mode = XMC_GPIO_MODE_INPUT_PULL_UP;           //RX上拉输入
	XMC_GPIO_Init(GPIO_RX, &config);
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT7;   //TX复用UART输出U0CH1(要推挽）
	XMC_GPIO_Init(GPIO_TX, &config);	
	
	//硬件测试
	XMC_GPIO_SetOutputLow(GPIO_LED1);
	XMC_GPIO_SetOutputLow(GPIO_LED2);
	XMC_GPIO_SetOutputLow(GPIO_LED3);
	XMC_GPIO_SetOutputLow(GPIO_LED4);
	XMC_GPIO_SetOutputLow(GPIO_LED5);
	XMC_GPIO_SetOutputLow(GPIO_LED6);
}


