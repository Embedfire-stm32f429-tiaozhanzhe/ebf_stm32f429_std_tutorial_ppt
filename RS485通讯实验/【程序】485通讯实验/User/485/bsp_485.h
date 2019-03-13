#ifndef __485_H
#define	__485_H

#include "stm32f4xx.h"
#include <stdio.h>


//���Ŷ���
/*******************************************************/
#define __485_USART                             USART2
#define __485_USART_CLK                         RCC_APB1Periph_USART2
#define __485_USART_BAUDRATE                    115200  //���ڲ�����

#define __485_USART_RX_GPIO_PORT                GPIOD
#define __485_USART_RX_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define __485_USART_RX_PIN                      GPIO_Pin_6
#define __485_USART_RX_AF                       GPIO_AF_USART2
#define __485_USART_RX_SOURCE                   GPIO_PinSource6

#define __485_USART_TX_GPIO_PORT                GPIOD
#define __485_USART_TX_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define __485_USART_TX_PIN                      GPIO_Pin_5
#define __485_USART_TX_AF                       GPIO_AF_USART2
#define __485_USART_TX_SOURCE                   GPIO_PinSource5

#define __485_USART_IRQHandler                  USART2_IRQHandler
#define __485_USART_IRQ                 				USART2_IRQn



#define __485_CS__PIN                  GPIO_Pin_11                 
#define __485_CS_GPIO_PORT            GPIOD                    
#define __485_CS_GPIO_CLK             RCC_AHB1Periph_GPIOD


//�ȴ��շ�������ʱ
static void __485_delay(__IO u32 nCount)
{

	for(; nCount != 0; nCount--);
}


//����485�������ݣ�CS����Ϊ�ߵ�ƽ
#define __485_CS_TX_EN      __485_delay(3000); GPIO_SetBits(__485_CS_GPIO_PORT,__485_CS__PIN); __485_delay(3000);

//����485�������ݣ�CS����Ϊ�͵�ƽ
#define __485_CS_RX_EN      __485_delay(3000); GPIO_ResetBits(__485_CS_GPIO_PORT,__485_CS__PIN);__485_delay(3000);

/************************************************************/

void __485_USART_Config(void);
void __485_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);


#endif /* __485_H */
