#ifndef __LED_H
#define	__LED_H

#include "stm32f4xx.h"

/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1


#define LED1_PIN                  GPIO_Pin_1                 
#define LED1_GPIO_PORT            GPIOI                      
#define LED1_GPIO_CLK             RCC_AHB1Periph_GPIOI


#define LED2_PIN                  GPIO_Pin_8                 
#define LED2_GPIO_PORT            GPIOI                      
#define LED2_GPIO_CLK             RCC_AHB1Periph_GPIOI

#define LED3_PIN                  GPIO_Pin_11                  
#define LED3_GPIO_PORT            GPIOI                       
#define LED3_GPIO_CLK             RCC_AHB1Periph_GPIOI

/* ���κ꣬��������������һ��ʹ�� */
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_PIN)


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)			{p->BSRRL=i;}			  //����Ϊ�ߵ�ƽ		
#define digitalLo(p,i)			{p->BSRRH=i;}				//����͵�ƽ
#define digitalToggle(p,i)		{p->ODR ^=i;}			//�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF		digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON			digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF		digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON			digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF		digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON			digitalLo(LED3_GPIO_PORT,LED3_PIN)

void LED_GPIO_Config(void);

#endif /* __LED_H */
