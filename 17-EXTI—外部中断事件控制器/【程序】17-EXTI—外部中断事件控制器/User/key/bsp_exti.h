#ifndef __BSE_EXTI_H 
#define	__BSE_EXTI_H 

#include "stm32f4xx.h"

#define KEY1_GPIO_PIN             GPIO_Pin_0                 
#define KEY1_GPIO_PORT            GPIOA                      
#define KEY1_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define KEY1_INT_EXTI_LINE        EXTI_Line0

#define KEY1_INT_EXTI_PORTSOURCE  EXTI_PortSourceGPIOA
#define KEY1_INT_EXTI_PINSOURCE   EXTI_PinSource0
#define KEY1_INT_EXTI_IRQ         EXTI0_IRQn

#define KEY1_INT_EXTI_IRQHANDLER  EXTI0_IRQHandler



#define KEY2_GPIO_PIN             GPIO_Pin_13                 
#define KEY2_GPIO_PORT            GPIOC                      
#define KEY2_GPIO_CLK             RCC_AHB1Periph_GPIOC


void EXTI_Key_Config(void);

#endif /* __BSE_EXTI_H */
