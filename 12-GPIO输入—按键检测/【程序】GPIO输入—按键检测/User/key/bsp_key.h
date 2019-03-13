#ifndef __BSP_KEY_H

#include "stm32f4xx_gpio.h"

#define KEY_ON     1
#define KEY_OFF    0

#define KEY1_GPIO_PIN        GPIO_Pin_0
#define KEY1_GPIO_PORT       GPIOA
#define KEY1_GPIO_CLK        RCC_AHB1Periph_GPIOA

#define KEY2_GPIO_PIN        GPIO_Pin_13
#define KEY2_GPIO_PORT       GPIOC
#define KEY2_GPIO_CLK        RCC_AHB1Periph_GPIOC



void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#define  __BSP_KEY_H
#endif  /* __BSP_KEY_H */

