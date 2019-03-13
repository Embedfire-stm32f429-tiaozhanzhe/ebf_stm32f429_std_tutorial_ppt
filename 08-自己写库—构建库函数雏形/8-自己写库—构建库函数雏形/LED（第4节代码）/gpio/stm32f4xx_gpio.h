#ifndef __STM32F4XX_GPIO_H
#define __STM32F4XX_GPIO_H

#include "stm32f4xx.h"

#define GPIO_Pin_0            ((uint16_t)(0x0001))
#define GPIO_Pin_1            ((uint16_t)(0x0002))
#define GPIO_Pin_2            ((uint16_t)(0x0004))
#define GPIO_Pin_3            ((uint16_t)(0x0008))

#define GPIO_Pin_4            ((uint16_t)(0x0010))
#define GPIO_Pin_5            ((uint16_t)(0x0020))
#define GPIO_Pin_6            ((uint16_t)(0x0040))
#define GPIO_Pin_7            ((uint16_t)(0x0080))

#define GPIO_Pin_8            ((uint16_t)(0x0100))
#define GPIO_Pin_9            ((uint16_t)(0x0200))
#define GPIO_Pin_10           ((uint16_t)(0x0400))
#define GPIO_Pin_11           ((uint16_t)(0x0800))

#define GPIO_Pin_12            ((uint16_t)(0x1000))
#define GPIO_Pin_13            ((uint16_t)(0x2000))
#define GPIO_Pin_14            ((uint16_t)(0x4000))
#define GPIO_Pin_15            ((uint16_t)(0x8000))
#define GPIO_Pin_ALL           ((uint16_t)(0xFFFF))

typedef unsigned char uint8_t;

typedef enum
{
	GPIO_Mode_IN  =  0x00,   /* 输入 */
	GPIO_Mode_OUT =  0x01,   /* 输出 */
	GPIO_Mode_AF  =  0x02,   /* 复用功能 */
	GPIO_Mode_AN  =  0x03,   /* 模拟 */
}GPIOMode_TypeDef;

// 推挽：Push pull
// 开漏：Open drain
typedef enum
{
	GPIO_OType_PP   =  0x00,   /* 推挽输出 */
	GPIO_OType_OD   =  0x01,   /* 开漏输出 */
}GPIOOType_TypeDef;

typedef enum
{
	GPIO_Speed_2MHZ   =  0x00,   /* 2MHZ */
	GPIO_Speed_25MHZ  =  0x01,   /* 25MHZ */
	GPIO_Speed_50MHZ  =  0x02,   /* 50MHZ */
	GPIO_Speed_100MHZ =  0x03,   /* 100MHZ */
}GPIOSpeed_TypeDef;

typedef enum
{
	GPIO_PuPd_NOPULL   =  0x00,   /* 浮空 */
	GPIO_PuPd_UP       =  0x01,   /* 上拉 */
  GPIO_PuPd_DOWN     =  0x02,   /* 下拉 */
}GPIOPuPd_TypeDef;


typedef struct
{
	uint32_t GPIO_Pin;
	GPIOMode_TypeDef     GPIO_Mode;
	GPIOOType_TypeDef    GPIO_OType;
	GPIOSpeed_TypeDef    GPIO_Speed;
  GPIOPuPd_TypeDef     GPIO_PuPd;	
}GPIO_InitTypeDef;




void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_InitStruct );

#endif  /* __STM32F4XX_GPIO_H */
