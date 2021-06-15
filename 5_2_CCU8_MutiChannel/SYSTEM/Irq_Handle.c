
/*
中断处理函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"
#include "Var_Init.h"

void CCU80_0_IRQHandler(void)
{	

	CCU80_CC80->CR1S	=	2000;
	CCU80_CC81->CR1S	=	3000;
	CCU80_CC82->CR1S	=	4000;
	CCU80->GCSS |=0x00001111;

	SET_BIT(CCU80_CC80->SWR, CCU8_CC8_SWR_ROM_Pos);	 
}

void IRQ_Enable()
{
  NVIC_SetPriority(CCU80_0_IRQn, 0);
  NVIC_EnableIRQ(CCU80_0_IRQn);
}

