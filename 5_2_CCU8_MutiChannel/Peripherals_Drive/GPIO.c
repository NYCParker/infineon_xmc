/*
GPIO 
*/

#include <XMC4400.h>
#include "GPIO.h"
#include <xmc_gpio.h>

void GPIO_Init(void)
{
	XMC_GPIO_CONFIG_t config;
	
    config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;   //ÁùÂ·PWMÊä³ö
    config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
    config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE;		
    XMC_GPIO_Init(PWM_UH, &config);
	XMC_GPIO_Init(PWM_VH, &config);	
    XMC_GPIO_Init(PWM_WH, &config);	
	XMC_GPIO_Init(PWM_UL, &config);	
    XMC_GPIO_Init(PWM_VL, &config);	
	XMC_GPIO_Init(PWM_WL, &config);  
}
