/*
GPIO 
*/

#include <XMC4400.h>
#include "GPIO.h"
#include <xmc_gpio.h>

void GPIO_Init(void)
{
	XMC_GPIO_CONFIG_t config;
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;        
	XMC_GPIO_Init(GPIO_LED1, &config);             
	XMC_GPIO_Init(GPIO_LED2, &config);            
	
	config.mode = XMC_GPIO_MODE_INPUT_SAMPLING;        
	XMC_GPIO_Init(Iu_ADC, &config); 
	XMC_GPIO_Init(Iv_ADC, &config);
	XMC_GPIO_Init(Vbus_ADC, &config);
	XMC_GPIO_Init(Force_ADC, &config);   
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;   //六路PWM输出
    config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
    config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE;		
    XMC_GPIO_Init(PWM_UH, &config);
	XMC_GPIO_Init(PWM_VH, &config);	
    XMC_GPIO_Init(PWM_WH, &config);	
	XMC_GPIO_Init(PWM_UL, &config);	
    XMC_GPIO_Init(PWM_VL, &config);	
	XMC_GPIO_Init(PWM_WL, &config);  
	
	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;        //使能
	XMC_GPIO_Init(MOS_Enable, &config);		

	config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;        //使能
	XMC_GPIO_Init(BRAKE, &config);		

	config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;        
	XMC_GPIO_Init(U_P, &config);                 
	XMC_GPIO_Init(V_P, &config);                
	XMC_GPIO_Init(W_P, &config);            
	XMC_GPIO_Init(B_P, &config);  
	
	//暂时不用的引脚
	config.mode = XMC_GPIO_MODE_INPUT_SAMPLING; 
	XMC_GPIO_Init(P0_9, &config); 
	XMC_GPIO_Init(P0_10, &config);
	XMC_GPIO_Init(P14_14, &config);
	XMC_GPIO_Init(P14_7, &config); 
	XMC_GPIO_Init(P14_6, &config); 
	XMC_GPIO_Init(P2_8, &config);
	XMC_GPIO_Init(P2_9, &config);
	XMC_GPIO_Init(P2_6, &config);
	XMC_GPIO_Init(P2_7, &config); 
	XMC_GPIO_Init(P1_8, &config);
	XMC_GPIO_Init(P1_9, &config);
	
	XMC_GPIO_SetOutputLow(GPIO_LED1);
	XMC_GPIO_SetOutputLow(GPIO_LED2);
}

void ERU0_Init(void)
{
	WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS3B_Msk, ERU_EXISEL_EXS3B_Pos, 2);   //0.6 3B2
	WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS3A_Msk, ERU_EXISEL_EXS3A_Pos, 2);   //0.11 3A2
	WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS2B_Msk, ERU_EXISEL_EXS2B_Pos, 1);   //0.7 2B1
	WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS2A_Msk, ERU_EXISEL_EXS2A_Pos, 1);   //0.8 2A1
	
	WR_REG(ERU0->EXICON[3], ERU_EXICON_SS_Msk, ERU_EXICON_SS_Pos, 2);  //A||B   U V
	WR_REG(ERU0->EXICON[3], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, 1);  
	WR_REG(ERU0->EXICON[3], ERU_EXICON_RE_Msk, ERU_EXICON_RE_Pos, 1);
	WR_REG(ERU0->EXICON[3], ERU_EXICON_FE_Msk, ERU_EXICON_FE_Pos, 1);
	WR_REG(ERU0->EXICON[3], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, 0);  //OGU0 触发脉冲
	
	WR_REG(ERU0->EXICON[2], ERU_EXICON_SS_Msk, ERU_EXICON_SS_Pos, 2);  //A||B  W B
	WR_REG(ERU0->EXICON[2], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, 1);  
	WR_REG(ERU0->EXICON[2], ERU_EXICON_RE_Msk, ERU_EXICON_RE_Pos, 1);
	WR_REG(ERU0->EXICON[2], ERU_EXICON_FE_Msk, ERU_EXICON_FE_Pos, 1);
	WR_REG(ERU0->EXICON[2], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, 0);  //OGU0  触发脉冲
	
	//使能OGU0上的中断
	WR_REG(ERU0->EXOCON[0], ERU_EXOCON_GP_Msk, ERU_EXOCON_GP_Pos, 1);
}
