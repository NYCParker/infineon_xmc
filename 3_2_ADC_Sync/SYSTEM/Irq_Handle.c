
/*
中断处理函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"
#include "Var_Init.h"

void VADC0_G0_0_IRQHandler(void)
{
	Iu_ADC_Value = ((VADC_G0->RESD[0])&0x0000FFFF); 
	Iv_ADC_Value = ((VADC_G2->RESD[0])&0x0000FFFF);
	Vbus_ADC_Value = ((VADC_G0->RESD[3])&0x0000FFFF);
	Force_ADC_Value = ((VADC_G0->RESD[5])&0x0000FFFF);
	
	Iu = Iu_ADC_Value - Iu_ADC_Value_Ref;
	Iv = Iv_ADC_Value - Iv_ADC_Value_Ref;
	Vbus = Vbus_ADC_Value - Vbus_ADC_Value_Ref;
	Force = Force_ADC_Value - Force_ADC_Value_Ref; 
	
	
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV0_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV3_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV5_Pos);	
	SET_BIT(VADC_G2->REFCLR, VADC_G_REFLAG_REV0_Pos);
}

void IRQ_Enable()
{
  NVIC_SetPriority(VADC0_G0_0_IRQn, 1);	
  NVIC_EnableIRQ(VADC0_G0_0_IRQn);
}

