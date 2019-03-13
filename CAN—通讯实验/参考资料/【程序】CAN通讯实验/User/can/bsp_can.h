#ifndef __CAN_H
#define	__CAN_H

#include "stm32f4xx.h"


#define MESSAGE_EXID1  0x1234
#define MESSAGE_EXID2  0x4321


//Òý½Å¶¨Òå
/*******************************************************/
#define CAN_NUM                     CAN1
#define CAN_APB_CLK                 RCC_APB1Periph_CAN1


#define CAN_TX_PIN                  GPIO_Pin_9                 
#define CAN_TX_GPIO_PORT            GPIOB                     
#define CAN_TX_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define CAN_TX_AF                    GPIO_AF_CAN1
#define CAN_TX_SOURCE                GPIO_PinSource9


#define CAN_RX_PIN                  GPIO_Pin_8                 
#define CAN_RX_GPIO_PORT            GPIOB                     
#define CAN_RX_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define CAN_RX_AF                    GPIO_AF_CAN1
#define CAN_RX_SOURCE                GPIO_PinSource8

//NVIC

#define CAN_IRQ_Channel             CAN1_RX0_IRQn
#define CAN_TEST_IRQHandler         CAN1_RX0_IRQHandler   

/*******************************************************/


void CAN_Test_Init(void);



#endif /* __CAN_H */

