/*
GPIO 
*/

#include <XMC4400.h>
#include "GPIO.h"
#include <xmc_gpio.h>

void GPIO_Init(void)
{
	XMC_GPIO_CONFIG_t config;
	
	config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;        
	XMC_GPIO_Init(Iu_ADC, &config); 
	XMC_GPIO_Init(Iv_ADC, &config);
	XMC_GPIO_Init(Vbus_ADC, &config);
	XMC_GPIO_Init(Force_ADC, &config);   
}
