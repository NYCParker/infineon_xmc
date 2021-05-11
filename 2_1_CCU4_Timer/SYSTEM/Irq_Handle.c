
/*
中断处理函数
*/

#include <XMC4400.h>
#include "Irq_Handle.h"

void IRQ_Enable(void)
{
    NVIC_ClearPendingIRQ(CCU40_0_IRQn);	
	NVIC_EnableIRQ(CCU40_0_IRQn);	
}

void CCU40_0_IRQHandler(void)
{
	if(RD_REG(CCU40_CC40->INTS, CCU4_CC4_INTS_PMUS_Msk, CCU4_CC4_INTS_PMUS_Pos)==1)
	{
		//周期匹配中断里做的事情
		SET_BIT(CCU40_CC40->SWR, CCU4_CC4_SWR_RPM_Pos);
	}
}
