
/*
ADC����
14.0 14.4 G0CH0  G2CH0  SYNC
G0CH3 G0CH5 ���в���
*/

#include <XMC4400.h>
#include "ADC.h"

void CCU80_Init(void)
{
	uint16_t PWM_Period=6000;    //50us
    uint16_t PWM_Compare = 6001;	
	
	WR_REG(SCU_RESET->PRSET0, SCU_RESET_PRSET0_CCU80RS_Msk, SCU_RESET_PRSET0_CCU80RS_Pos, 1);
	WR_REG(SCU_RESET->PRCLR0, SCU_RESET_PRCLR0_CCU80RS_Msk, SCU_RESET_PRCLR0_CCU80RS_Pos, 1);	
	WR_REG(SCU_CLK->CLKSET, SCU_CLK_CLKSET_CCUCEN_Msk, SCU_CLK_CLKSET_CCUCEN_Pos, 1);		
	WR_REG(CCU80->GIDLC, CCU8_GIDLC_SPRB_Msk, CCU8_GIDLC_SPRB_Pos, 1);

	WR_REG(CCU80_CC83->PSC, CCU8_CC8_PSC_PSIV_Msk, CCU8_CC8_PSC_PSIV_Pos, 0);		     
	WR_REG(CCU80_CC83->FPC, CCU8_CC8_FPC_PVAL_Pos, CCU8_CC8_FPC_PVAL_Pos, 0);	         
	WR_REG(CCU80_CC83->INS, CCU8_CC8_INS_EV0IS_Msk, CCU8_CC8_INS_EV0IS_Pos, 7);	          
	WR_REG(CCU80_CC83->INS, CCU8_CC8_INS_EV0EM_Msk, CCU8_CC8_INS_EV0EM_Pos, 1);	          
	WR_REG(CCU80_CC83->CMC, CCU8_CC8_CMC_STRTS_Msk, CCU8_CC8_CMC_STRTS_Pos, 1);	            		
	WR_REG(CCU80_CC83->TC, CCU8_CC8_TC_TCM_Msk, CCU8_CC8_TC_TCM_Pos, 1);        		
	WR_REG(CCU80_CC83->TC, CCU8_CC8_TC_STRM_Msk, CCU8_CC8_TC_STRM_Pos, 1);
	WR_REG(CCU80_CC83->PRS, CCU8_CC8_PRS_PRS_Msk, CCU8_CC8_PRS_PRS_Pos, PWM_Period);
	WR_REG(CCU80_CC83->CR1S, CCU8_CC8_CR1S_CR1S_Msk, CCU8_CC8_CR1S_CR1S_Pos, PWM_Compare);
	
   	WR_REG(CCU80_CC83->INTE, CCU8_CC8_INTE_PME_Msk, CCU8_CC8_INTE_PME_Pos, 1);
	WR_REG(CCU80_CC83->SRS, CCU8_CC8_SRS_POSR_Msk, CCU8_CC8_SRS_POSR_Pos, 2);     //����ƥ�䴥��AD����

	WR_REG(CCU80->GCSS, CCU8_GCSS_S3SE_Msk, CCU8_GCSS_S3SE_Pos, 1);	
	WR_REG(CCU80->GIDLC, CCU8_GIDLC_CS3I_Msk, CCU8_GIDLC_CS3I_Pos, 1);
}

void CCU80_Start(void)
{
	WR_REG(SCU_GENERAL->CCUCON, SCU_GENERAL_CCUCON_GSC80_Msk, SCU_GENERAL_CCUCON_GSC80_Pos, 1);
}

void ADC_Init(void)
{
    WR_REG(SCU_RESET->PRSET0, SCU_RESET_PRSET0_VADCRS_Msk, SCU_RESET_PRSET0_VADCRS_Pos, 1);
	WR_REG(SCU_RESET->PRCLR0, SCU_RESET_PRCLR0_VADCRS_Msk, SCU_RESET_PRCLR0_VADCRS_Pos, 1);	
	VADC->CLC	&=	0xfffffffe;                                                   //����ģ��ʱ��
	while(VADC->CLC!=0){}	                                                      //�ȴ�ʱ���ȶ�  
	VADC->GLOBCFG=0x00008007;			                                          //fADCI = fADC/8 = 15Mhz	
		
	VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
		        ((0x0 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk)|
		        ((0x1 << VADC_G_QINR0_EXTR_Pos) & VADC_G_QINR0_EXTR_Msk);		  //��0ͨ��0 �ⲿ���� �Զ����� 
	VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
		        ((0x3 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //��0ͨ��3 �Զ�����
		
	VADC_G0->QINR0 =
				((0x1 << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk) |
		        ((0x5 << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk);   //��0ͨ��5 �Զ�����
		
	//�������Ĵ�������
	WR_REG(VADC_G0->CHCTR[0], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 0);	
	WR_REG(VADC_G0->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 3);
    WR_REG(VADC_G0->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 5);

	//�������Ĵ�������
    WR_REG(VADC_G2->CHCTR[0], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos, 0);
	
	WR_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_ARBRND_Msk, VADC_G_ARBCFG_ARBRND_Pos, 0);
	WR_REG(VADC_G2->ARBCFG, VADC_G_ARBCFG_ARBRND_Msk, VADC_G_ARBCFG_ARBRND_Pos, 0);
	
	WR_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_ANONC_Msk, VADC_G_ARBCFG_ANONC_Pos, 0);
	WR_REG(VADC_G2->ARBCFG, VADC_G_ARBCFG_ANONC_Msk, VADC_G_ARBCFG_ANONC_Pos, 0);	 
	
    //G2���ں�����
	WR_REG(VADC_G2->SYNCTR, VADC_G_SYNCTR_STSEL_Msk, VADC_G_SYNCTR_STSEL_Pos, 1);  //��ϢԴΪCI1
	WR_REG(VADC_G2->ARBCFG, VADC_G_ARBCFG_ARBM_Msk, VADC_G_ARBCFG_ARBM_Pos, 0);    //����ģʽ
	WR_REG(VADC_G2->SYNCTR, VADC_G_SYNCTR_EVALR1_Msk, VADC_G_SYNCTR_EVALR1_Pos, 1);//ʹ��slave�����ź�
		
	//G0���ں�����
	WR_REG(VADC_G0->SYNCTR, VADC_G_SYNCTR_STSEL_Msk, VADC_G_SYNCTR_STSEL_Pos, 0);  //��ϢԴ�Լ�
	WR_REG(VADC_G0->CHCTR[0], VADC_G_CHCTR_SYNC_Msk, VADC_G_CHCTR_SYNC_Pos, 1);    //ͨ��0����ͬ������
    WR_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_ANONC_Msk, VADC_G_ARBCFG_ANONC_Pos, 3);  //��������

    //�����е��ⲿ�����ź�����CCU8.SR2
	VADC_G0->QCTRL0 =
				((0x1 << VADC_G_QCTRL0_XTWC_Pos) & VADC_G_QCTRL0_XTWC_Msk) |        //����дXTSEL��XTMODE
				((0x8 << VADC_G_QCTRL0_XTSEL_Pos) & VADC_G_QCTRL0_XTSEL_Msk) |      //ʹ���ſش���
				((0x2 << VADC_G_QCTRL0_XTMODE_Pos) & VADC_G_QCTRL0_XTMODE_Msk); 	//��������Ч
				
    WR_REG(VADC_G0->QMR0, VADC_G_QMR0_ENGT_Msk, VADC_G_QMR0_ENGT_Pos, 1);           //ʹ���ſ�
	WR_REG(VADC_G0->QMR0, VADC_G_QMR0_ENTR_Msk, VADC_G_QMR0_ENTR_Pos, 1);           //ʹ���ⲿ����

    //������������ٲ�ʱ϶0
	WR_REG(VADC_G0->ARBPR, VADC_G_ARBPR_ASEN0_Msk, VADC_G_ARBPR_ASEN0_Pos, 1);
	WR_REG(VADC_G2->ARBPR, VADC_G_ARBPR_ASEN0_Msk, VADC_G_ARBPR_ASEN0_Pos, 1);
	
	WR_REG(VADC->GLOBCFG, VADC_GLOBCFG_SUCAL_Msk, VADC_GLOBCFG_SUCAL_Pos, 1);        //������ʼУ׼�׶�	
	while((RD_REG(VADC_G0->ARBCFG, VADC_G_ARBCFG_CAL_Msk, VADC_G_ARBCFG_CAL_Pos))!= 0){};
	while((RD_REG(VADC_G2->ARBCFG, VADC_G_ARBCFG_CAL_Msk, VADC_G_ARBCFG_CAL_Pos))!= 0){};
		
	WR_REG(VADC_G0->RCR[5], VADC_G_RCR_SRGEN_Msk, VADC_G_RCR_SRGEN_Pos, 1);          //������0����¼�5�󷢳���������
	WR_REG(VADC_G0->REVNP0, VADC_G_REVNP0_REV5NP_Msk, VADC_G_REVNP0_REV5NP_Pos, 0);  //ѡ����0��5ͨ������¼��ķ���������0
}