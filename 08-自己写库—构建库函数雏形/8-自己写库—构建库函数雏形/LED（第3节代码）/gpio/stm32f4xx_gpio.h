#ifndef __STM32F4XX_GPIO_H
#define __STM32F4XX_GPIO_H

#include "stm32f4xx.h"

void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#endif  /* __STM32F4XX_GPIO_H */
