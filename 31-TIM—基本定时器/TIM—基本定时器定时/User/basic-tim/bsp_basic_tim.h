#ifndef __BASIC_TIM_H
#define	__BASIC_TIM_H

#include "stm32f4xx.h"


#define BASIC_TIMx           		TIM6
#define BASIC_TIMx_CLK       		RCC_APB1Periph_TIM6

#define BASIC_TIMx_IRQn					TIM6_DAC_IRQn
#define BASIC_TIMx_IRQHandler   TIM6_DAC_IRQHandler

void BASIC_TIMx_Config(void);

#endif /* __BASIC_TIM_H */

