
/*
中断处理函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"
#include "Var_Init.h"
#include "ADC.h"

void VADC0_G0_0_IRQHandler(void)
{
	Iu_ADC_Value = ((VADC_G0->RESD[0])&0x0000FFFF); 
	Iv_ADC_Value = ((VADC_G2->RESD[0])&0x0000FFFF);
	Vbus_ADC_Value = ((VADC_G0->RESD[3])&0x0000FFFF);
	Force_ADC_Value = ((VADC_G0->RESD[5])&0x0000FFFF);
	
	Iu = Iu_ADC_Value - Iu_ADC_Value_Ref;
	Iv = Iv_ADC_Value - Iv_ADC_Value_Ref;
	Vbus = Vbus_ADC_Value - 0;
	Force = Force_ADC_Value - Force_ADC_Value_Ref; 
	
	if(Vbus > 1700)
	{
		Switch_off();
	}
	
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV0_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV3_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV5_Pos);	
	SET_BIT(VADC_G2->REFCLR, VADC_G_REFLAG_REV0_Pos);
}

void CCU80_0_IRQHandler(void)
{	

	CCU80_CC80->CR1S	=	1000;
	CCU80_CC81->CR1S	=	2000;
	CCU80_CC82->CR1S	=	3000;
	CCU80->GCSS |=0x00001111;

	SET_BIT(CCU80_CC80->SWR, CCU8_CC8_SWR_ROM_Pos);	 
}


void IRQ_Enable()
{
  NVIC_SetPriority(VADC0_G0_0_IRQn, 1);	
  NVIC_EnableIRQ(VADC0_G0_0_IRQn);
	
  NVIC_SetPriority(CCU80_0_IRQn, 0);
  NVIC_EnableIRQ(CCU80_0_IRQn);
	
  NVIC_ClearPendingIRQ(ERU0_0_IRQn);		//This function clears node 1 pending status
  NVIC_EnableIRQ(ERU0_0_IRQn);			//This function enables node 1 for interrupt request generation
	
}

void ERU0_0_IRQHandler(void)
{
	if(RD_REG(ERU0->EXICON[3],ERU_EXICON_FL_Msk,ERU_EXICON_FL_Pos) == 1)
	{
		Switch_off();
		protect_flag += 1;
		CLR_BIT(ERU0->EXICON[3], ERU_EXICON_FL_Pos);
	}
	
	if(RD_REG(ERU0->EXICON[2],ERU_EXICON_FL_Msk,ERU_EXICON_FL_Pos) == 1)
	{
		Switch_off();
		protect_flag += 2;
		CLR_BIT(ERU0->EXICON[2], ERU_EXICON_FL_Pos);
	}
}
