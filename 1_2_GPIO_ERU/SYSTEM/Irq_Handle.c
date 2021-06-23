
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
	
	NVIC_ClearPendingIRQ(ERU0_0_IRQn);		//This function clears node 1 pending status
	NVIC_EnableIRQ(ERU0_0_IRQn);			//This function enables node 1 for interrupt request generation
}

void CCU40_0_IRQHandler(void)
{
	static int i = 0;
	
	if(RD_REG(CCU40_CC40->INTS, CCU4_CC4_INTS_PMUS_Msk, CCU4_CC4_INTS_PMUS_Pos)==1)
	{
		i++;
		
		if(i == 10)
		{
			XMC_GPIO_ToggleOutput(Test_Output);               //翻转
			i=0;
		}
		
		SET_BIT(CCU40_CC40->SWR, CCU4_CC4_SWR_RPM_Pos);
	}
}

void CCU40_1_IRQHandler(void)
{
	if(RD_REG(CCU40_CC41->INTS, CCU4_CC4_INTS_PMUS_Msk, CCU4_CC4_INTS_PMUS_Pos)==1)
	{
		SET_BIT(CCU40_CC41->SWR, CCU4_CC4_SWR_RPM_Pos);
	}
}

void ERU0_0_IRQHandler(void)
{
	if(RD_REG(ERU0->EXICON[3],ERU_EXICON_FL_Msk,ERU_EXICON_FL_Pos) == 1)
	{
		protect_flag = 1;
		CLR_BIT(ERU0->EXICON[3], ERU_EXICON_FL_Pos);
	}
	
	if(RD_REG(ERU0->EXICON[2],ERU_EXICON_FL_Msk,ERU_EXICON_FL_Pos) == 1)
	{
		protect_flag = 2;
		CLR_BIT(ERU0->EXICON[2], ERU_EXICON_FL_Pos);
	}
}


