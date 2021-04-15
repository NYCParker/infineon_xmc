
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
  NVIC_SetPriority(CCU40_1_IRQn, 4);
  NVIC_SetPriority(POSIF0_0_IRQn,2); 

  NVIC_EnableIRQ(CCU40_1_IRQn);
  NVIC_EnableIRQ(POSIF0_0_IRQn);
}

void POSIF0_0_IRQHandler(void)
{
	SET_BIT(POSIF0->RPFLG, POSIF_RPFLG_RINDX_Pos); 	
}

void CCU40_1_IRQHandler(void)
{
	//m法测速
	SET_BIT(CCU40_CC43->SWR, CCU4_CC4_SWR_RE1A_Pos); 	
}

