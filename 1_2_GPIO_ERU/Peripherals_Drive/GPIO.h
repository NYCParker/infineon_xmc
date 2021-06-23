#ifndef _GPIO_h
#define _GPIO_h

#include <XMC4400.h>

#define Test_Output  P1_2

#define U_P  P0_6
#define V_P  P0_11
#define W_P  P0_7
#define B_P  P0_8


extern void GPIO_Init(void);
extern void ERU0_Init(void);
#endif
