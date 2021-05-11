
#include <XMC1300.h>
#include "VADC.h"

void VADC_Init(void)
{
	WR_REG(VADC->CLC, VADC_CLC_DISR_Msk, VADC_CLC_DISR_Pos, 0);
	while((RD_REG(VADC->CLC, VADC_CLC_DISS_Msk, VADC_CLC_DISS_Pos))!= 0);
	
	WR_REG(VADC->GLOBCFG, VADC_GLOBCFG_DIVA_Msk, VADC_GLOBCFG_DIVA_Pos, 1);    //fADC=16Mhz
	
	/*************************************队列设置****************************************/
	VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
		        ((0x0 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk)|
		        ((0x1 << VADC_G_QINR0_EXTR_Pos) & VADC_G_QINR0_EXTR_Msk);		  //组0通道0 自动重填 外部触发 
	
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x1 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道1 自动重填 
	
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x2 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道2 自动重填 
	
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x3 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道3 自动重填 
				
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x4 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道4 自动重填 
				
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x5 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道5 自动重填 
				
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x6 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道6 自动重填 
				
    VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
				((0x7 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //组0通道7 自动重填 
				
	WR_REG(VADC_G0->CHCTR[0], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 0);
	WR_REG(VADC_G0->CHCTR[1], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 1);
	WR_REG(VADC_G0->CHCTR[2], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 2);
	WR_REG(VADC_G0->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 3);
	WR_REG(VADC_G0->CHCTR[4], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 4);
	WR_REG(VADC_G0->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 5);
	WR_REG(VADC_G0->CHCTR[6], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 6);
	WR_REG(VADC_G0->CHCTR[7], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 7);
	
	/*************************************队列设置****************************************/
	
	VADC_G0->QCTRL0 =
				((0x1 << VADC_G_QCTRL0_XTWC_Pos) & VADC_G_QCTRL0_XTWC_Msk) |        //可以写XTSEL和XTMODE
				((0x0 << VADC_G_QCTRL0_XTSEL_Pos) & VADC_G_QCTRL0_XTSEL_Msk) |      //外部触发源：CCU40_SR2
				((0x2 << VADC_G_QCTRL0_XTMODE_Pos) & VADC_G_QCTRL0_XTMODE_Msk); 	//上升沿有效	
    WR_REG(VADC_G0->QMR0, VADC_G_QMR0_ENGT_Msk, VADC_G_QMR0_ENGT_Pos, 1);           //使能门控
	WR_REG(VADC_G0->QMR0, VADC_G_QMR0_ENTR_Msk, VADC_G_QMR0_ENTR_Pos, 1);           //使能外部触发
	
	WR_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_ANONC_Msk, VADC_G_ARBCFG_ANONC_Pos, 3);   //正常工作
	WR_REG(VADC_G0->ARBPR, VADC_G_ARBPR_ASEN0_Msk, VADC_G_ARBPR_ASEN0_Pos, 1);      //启用仲裁时隙0
	
	WR_REG(VADC->GLOBCFG, VADC_GLOBCFG_SUCAL_Msk, VADC_GLOBCFG_SUCAL_Pos, 1);       //启动初始校准阶段	
	while((RD_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_CAL_Msk, VADC_G_ARBCFG_CAL_Pos))!= 0){};
		
	WR_REG(VADC_G0->RCR[7], VADC_G_RCR_SRGEN_Msk, VADC_G_RCR_SRGEN_Pos, 1);          //发生组0结果事件7后发出服务请求
	WR_REG(VADC_G0->REVNP0, VADC_G_REVNP0_REV7NP_Msk, VADC_G_REVNP0_REV7NP_Pos, 0);  //选择组0的7通道结果事件的服务请求线0	
}

