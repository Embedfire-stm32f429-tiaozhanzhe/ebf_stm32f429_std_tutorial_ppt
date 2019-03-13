#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f4xx_gpio.h"

void LED_GPIO_Config(void);

#define LED_R_GPIO_PIN     GPIO_Pin_10
#define LED_R_GPIO_PORT    GPIOH

#define LED_G_GPIO_PIN     GPIO_Pin_11
#define LED_G_GPIO_PORT    GPIOH

#define LED_B_GPIO_PIN     GPIO_Pin_12
#define LED_B_GPIO_PORT    GPIOH

#endif  /* __BSP_LED_H */

