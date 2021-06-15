
/*
DAC ≈‰÷√
14.8  DAC0    
14.9  DAC1
data_type signed unsigned -2048~2047  0~4095
*/

#include <XMC4400.h>
#include <xmc_dac.h>
#include "DAC.h"

XMC_DAC_CH_CONFIG_t const ch_config0=
{
  .output_offset	= 0U,
  .data_type 		= XMC_DAC_CH_DATA_TYPE_UNSIGNED,
  .output_scale 	= XMC_DAC_CH_OUTPUT_SCALE_NONE,
  .output_negation  = XMC_DAC_CH_OUTPUT_NEGATION_DISABLED,
};

XMC_DAC_CH_CONFIG_t const ch_config1=
{
  .output_offset	= 0U,
  .data_type 		= XMC_DAC_CH_DATA_TYPE_UNSIGNED,
  .output_scale 	= XMC_DAC_CH_OUTPUT_SCALE_NONE,
  .output_negation  = XMC_DAC_CH_OUTPUT_NEGATION_DISABLED,
};

void DAC_Init(void)
{
  XMC_DAC_CH_Init(XMC_DAC0, 0U, &ch_config0);
  XMC_DAC_CH_StartSingleValueMode(XMC_DAC0, 0U);
  XMC_DAC_CH_Init(XMC_DAC0, 1U, &ch_config1);
  XMC_DAC_CH_StartSingleValueMode(XMC_DAC0, 1U);	
}

void DAC_Output0(int16_t dat)
{
  XMC_DAC_CH_Write(XMC_DAC0,0U,dat);
}

void DAC_Output1(int16_t dat)
{
  XMC_DAC_CH_Write(XMC_DAC0,1U,dat);
}
