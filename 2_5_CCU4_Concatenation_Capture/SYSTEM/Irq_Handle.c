
/*
中断处理函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"
#include <xmc_gpio.h>
#include "GPIO.h"
#include "Var_Init.h"

void IRQ_Enable(void)
{
    NVIC_ClearPendingIRQ(CCU40_0_IRQn);	
	NVIC_EnableIRQ(CCU40_0_IRQn);
	
	NVIC_ClearPendingIRQ(CCU40_1_IRQn);	
	NVIC_EnableIRQ(CCU40_1_IRQn);	
}

void CCU40_0_IRQHandler(void)
{
	if(RD_REG(CCU40_CC40->INTS, CCU4_CC4_INTS_PMUS_Msk, CCU4_CC4_INTS_PMUS_Pos)==1)
	{
		XMC_GPIO_ToggleOutput(Test_Output);               //翻转
		SET_BIT(CCU40_CC40->SWR, CCU4_CC4_SWR_RPM_Pos);
	}
}

void CCU40_1_IRQHandler(void)   //捕获中断
{
	if(RD_REG(CCU40_CC41->INTS, CCU4_CC4_INTS_E0AS_Msk, CCU4_CC4_INTS_E0AS_Pos)==1)
	{
		Rising_Edge_Capture = (CCU40_CC41->CV[0]&0x0000FFFF)+(CCU40_CC42->CV[0]&0x0000FFFF)*65536;
		
		SET_BIT(CCU40_CC41->SWR, CCU4_CC4_SWR_RE0A_Pos);
	}
}
