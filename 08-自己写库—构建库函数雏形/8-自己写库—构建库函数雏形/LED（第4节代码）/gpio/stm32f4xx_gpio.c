#include "stm32f4xx_gpio.h"

/* 
 * 函数功能：设置引脚为高电平
 * 参数说明：GPIOx：该参数为GPIO_TypeDef类型的结构体指针，指向GPIO端口的地址
 *           GPIO_Pin：表示某个端口的引脚号
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRL = GPIO_Pin;
}


/* 
 * 函数功能：设置引脚为低电平
 * 参数说明：GPIOx：该参数为GPIO_TypeDef类型的结构体指针，指向GPIO端口的地址
 *           GPIO_Pin：表示某个端口的引脚号
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH = GPIO_Pin;
}

// GPIO初始化函数
void GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_InitStruct )
{
	uint32_t pinpos =0, pos=0, currentpos=0;
	// 首先要找到引脚号
 for( pinpos = 0x00; pinpos < 16; pinpos++ )
 {
	 pos = ((uint16_t)0x01) << pinpos;
	 
	 currentpos = pos & GPIO_InitStruct->GPIO_Pin;
	 
	 if ( currentpos == pos )
	 {
		GPIOx->MODER &= ~(3 << (2*pinpos));
		GPIOx->MODER |= ( ((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2*pinpos) );

		GPIOx->PUPDR &= ~(3<<2*pinpos);
		GPIOx->PUPDR |= ( ((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (2*pinpos));

		if( (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF) )
		{
			GPIOx->OSPEEDR &= ~(3<<2*pinpos);
			GPIOx->OSPEEDR |= (((uint32_t)GPIO_InitStruct->GPIO_Speed) << (2*pinpos));
		}

		GPIOx->OTYPER &= ~(1<<pinpos);
		GPIOx->OTYPER |= (((uint16_t)GPIO_InitStruct->GPIO_OType)<<pinpos);			
	 }
 }
}
