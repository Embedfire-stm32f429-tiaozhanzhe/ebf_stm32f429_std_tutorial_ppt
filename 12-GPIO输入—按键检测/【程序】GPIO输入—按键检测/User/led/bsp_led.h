#ifndef  __BSP_LED_H
#define  __BSP_LED_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void LED_GPIO_Config(void);

#define LED_R_GPIO_PIN        GPIO_Pin_10
#define LED_R_GPIO_PORT       GPIOH
#define LED_R_GPIO_CLK        RCC_AHB1Periph_GPIOH

#define LED_R_TOGGLE          {LED_R_GPIO_PORT->ODR ^= LED_R_GPIO_PIN;}

/*
 * ^ �������C���������һ�������Ƶ������
 * 1����1��򣬸ı�
 * 0����0��򣬲���
 */


#endif  /*__BSP_LED_H*/
