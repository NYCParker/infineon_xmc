
/*
系统参数设置
*/

#include <XMC4400.h>
#include "Var_Init.h"

uint16_t Iu_ADC_Value = 0;
uint16_t Iv_ADC_Value = 0;
uint16_t Vbus_ADC_Value = 0;
uint16_t Force_ADC_Value = 0; 

uint16_t Iu_ADC_Value_Ref = 0;
uint16_t Iv_ADC_Value_Ref = 0;
uint16_t Vbus_ADC_Value_Ref = 0;
uint16_t Force_ADC_Value_Ref = 0; 

int16_t Iu = 0;
int16_t Iv = 0;
int16_t Vbus = 0;
int16_t Force = 0; 

//Delay函数
void delay_Xms(uint16_t ticx)        //误差 0us
{
	uint16_t tici;
    unsigned char tica,ticb,ticc;
	
	for(tici=0; tici<ticx; tici++)
    {
	   for(ticc=1;ticc>0;ticc--)
         for(ticb=98;ticb>0;ticb--)
           for(tica=230;tica>0;tica--);
	}
}

void Cur_Calibration(void)        //校正零偏电流ADC值
{
	int Cur_Calibration_i;
	int Cur_Calibration_Count = 200;
	
	int Cur_Calibration_Iu_sum = 0;
	int Cur_Calibration_Iv_sum = 0;
	int Cur_Calibration_Vbus_sum = 0;
	int Cur_Calibration_Force_sum = 0;
	
	for(Cur_Calibration_i=0;Cur_Calibration_i<Cur_Calibration_Count;Cur_Calibration_i++)
	{
		WR_REG(VADC_G0->QMR0, VADC_G_QMR0_TREV_Msk, VADC_G_QMR0_TREV_Pos, 1);
		delay_Xms(2);
		while((RD_REG(VADC_G0->REFLAG, VADC_G_REFLAG_REV0_Msk, VADC_G_REFLAG_REV0_Pos) == 0)&&
			  (RD_REG(VADC_G2->REFLAG, VADC_G_REFLAG_REV0_Msk, VADC_G_REFLAG_REV0_Pos) == 0)&&
			  (RD_REG(VADC_G0->REFLAG, VADC_G_REFLAG_REV3_Msk, VADC_G_REFLAG_REV3_Pos) == 0)&&
               RD_REG(VADC_G0->REFLAG, VADC_G_REFLAG_REV5_Msk, VADC_G_REFLAG_REV5_Pos) == 0){};
				   
		Cur_Calibration_Iu_sum = Cur_Calibration_Iu_sum + ((VADC_G0->RESD[0])&0x0000FFFF);		  
		Cur_Calibration_Iv_sum = Cur_Calibration_Iv_sum + ((VADC_G2->RESD[0])&0x0000FFFF);
		Cur_Calibration_Vbus_sum = Cur_Calibration_Vbus_sum + ((VADC_G0->RESD[3])&0x0000FFFF);
		Cur_Calibration_Force_sum = Cur_Calibration_Force_sum + ((VADC_G0->RESD[5])&0x0000FFFF);
				   
		SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV0_Pos);
		SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV3_Pos);
		SET_BIT(VADC_G0->REFCLR, VADC_G_REFLAG_REV5_Pos);	
		SET_BIT(VADC_G2->REFCLR, VADC_G_REFLAG_REV0_Pos);	  
	}
	
	
	Iu_ADC_Value_Ref = Cur_Calibration_Iu_sum/(Cur_Calibration_Count);
	Iv_ADC_Value_Ref = Cur_Calibration_Iv_sum/(Cur_Calibration_Count);
	Vbus_ADC_Value_Ref = Cur_Calibration_Vbus_sum/(Cur_Calibration_Count);
	Force_ADC_Value_Ref = Cur_Calibration_Force_sum/(Cur_Calibration_Count);	
}
