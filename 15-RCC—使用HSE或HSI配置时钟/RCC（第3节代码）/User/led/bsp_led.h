#ifndef  __BSP_LED_H
#define  __BSP_LED_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void LED_GPIO_Config(void);

#define LED_R_GPIO_PIN        GPIO_Pin_10
#define LED_R_GPIO_PORT       GPIOH
#define LED_R_GPIO_CLK        RCC_AHB1Periph_GPIOH


/** ����LED������ĺ꣬
	* LED�͵�ƽ��������ON=0��OFF=1
	* ��LED�ߵ�ƽ�����Ѻ����ó�ON=1 ��OFF=0 ����
	*/
#define ON  0
#define OFF 1

/* ���κ꣬��������������һ��ʹ�� */
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED_R_GPIO_PORT ,LED_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_R_GPIO_PORT ,LED_R_GPIO_PIN)




#endif  /*__BSP_LED_H*/
