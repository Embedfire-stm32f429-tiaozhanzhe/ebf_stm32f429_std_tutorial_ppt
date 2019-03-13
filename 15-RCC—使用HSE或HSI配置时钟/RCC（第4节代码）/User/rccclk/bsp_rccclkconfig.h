#ifndef  __BSP_RCCCLKCONFIG_H
#define  __BSP_RCCCLKCONFIG_H

#include "stm32f4xx_rcc.h"

void HSE_SetSysClk(uint32_t m,uint32_t n,uint32_t p,uint32_t q);

void HSI_SetSysClk(uint32_t m,uint32_t n,uint32_t p,uint32_t q);
#endif  /*__BSP_RCCCLKCONFIG_H*/
