#include "stm32f4xx_gpio.h"

/* 
 * �������ܣ���������Ϊ�ߵ�ƽ
 * ����˵����GPIOx���ò���ΪGPIO_TypeDef���͵Ľṹ��ָ�룬ָ��GPIO�˿ڵĵ�ַ
 *           GPIO_Pin����ʾĳ���˿ڵ����ź�
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRL = GPIO_Pin;
}


/* 
 * �������ܣ���������Ϊ�͵�ƽ
 * ����˵����GPIOx���ò���ΪGPIO_TypeDef���͵Ľṹ��ָ�룬ָ��GPIO�˿ڵĵ�ַ
 *           GPIO_Pin����ʾĳ���˿ڵ����ź�
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH = GPIO_Pin;
}

// GPIO��ʼ������
void GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_InitStruct )
{
	uint32_t pinpos =0, pos=0, currentpos=0;
	// ����Ҫ�ҵ����ź�
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
