
/*
中断处理函数
*/

#include <XMC1300.h>
#include "Irq_Handle.h"
#include "GPIO.h"
#include "stdio.h"
#include "Var_Init.h"

void IRQ_Enable(void)
{
	NVIC_EnableIRQ(CCU40_0_IRQn);
	NVIC_EnableIRQ(VADC0_G0_0_IRQn);
    NVIC_EnableIRQ(USIC0_0_IRQn);
	
	NVIC_SetPriority(VADC0_G0_0_IRQn, 1);
    NVIC_SetPriority(CCU40_0_IRQn, 3);	
	NVIC_SetPriority(USIC0_0_IRQn, 2);
}

void CCU40_0_IRQHandler(void)
{
	if(RD_REG(CCU40_CC40->INTS, CCU4_CC4_INTS_CMUS_Msk, CCU4_CC4_INTS_CMUS_Pos)==1)   //可加可不加 进来只有一种情况
	{
		XMC_GPIO_ToggleOutput(GPIO_LED4); 
		XMC_GPIO_ToggleOutput(GPIO_LED5); 
		XMC_GPIO_ToggleOutput(GPIO_LED6);	
		SET_BIT(CCU40_CC40->SWR, CCU4_CC4_SWR_RCMU_Pos);
	}
}


void VADC0_G0_0_IRQHandler(void)
{
	uint8_t i=0;
	
	XMC_GPIO_ToggleOutput(GPIO_LED1);
	XMC_GPIO_ToggleOutput(GPIO_LED2); 
	XMC_GPIO_ToggleOutput(GPIO_LED3); 
	
	for( i=0 ; i<8 ; i++)
	{
		Pressure_Sensor_Data[i] = ((VADC_G0->RESD[i])&0x0000FFFF);
	}
	
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV0_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV1_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV2_Pos);	
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV3_Pos);
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV4_Pos); 
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV5_Pos); 
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV6_Pos); 
	SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV7_Pos); 
}


void USIC0_0_IRQHandler(void)
{
	if(RD_REG(USIC0_CH1->PSR, USIC_CH_PSR_RIF_Msk, USIC_CH_PSR_RIF_Pos) == 1)		              //判断接收中断标志
	{	
		SET_BIT(USIC0_CH1->PSCR, USIC_CH_PSCR_CRIF_Pos);
		XMC_GPIO_ToggleOutput(GPIO_LED1);
		
		Receive_Data[Receive_Count] = USIC0_CH1->RBUF;     //Receive_Data for debug 
		USIC0_CH1->TBUF[0] = Receive_Data[Receive_Count];
		
		Receive_Count++;
		if(Receive_Count == REC_LENGTH)
		{
			Receive_Count = 0;
		}	
	}
	
	if(RD_REG(USIC0_CH1->PSR, USIC_CH_PSR_AIF_Msk, USIC_CH_PSR_AIF_Pos) == 1)		              //判断备选接收中断标志
	{	
		SET_BIT(USIC0_CH1->PSCR, USIC_CH_PSCR_CAIF_Pos);
		XMC_GPIO_ToggleOutput(GPIO_LED2);
	}	
}
