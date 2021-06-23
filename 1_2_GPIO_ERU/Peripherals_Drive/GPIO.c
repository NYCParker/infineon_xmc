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
	XMC_GPIO_Init(Test_Output, &config);             //P1.2普通输出
	
	config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;        
	XMC_GPIO_Init(U_P, &config);                 
	XMC_GPIO_Init(V_P, &config);                
	XMC_GPIO_Init(W_P, &config);            
	XMC_GPIO_Init(B_P, &config);           
	
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
