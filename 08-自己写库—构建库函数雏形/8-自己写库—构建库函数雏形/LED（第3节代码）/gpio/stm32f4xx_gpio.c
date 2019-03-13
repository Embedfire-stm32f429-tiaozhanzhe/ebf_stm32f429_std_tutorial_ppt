#include "stm32f4xx_gpio.h"

/* 
 * �������ܣ���������Ϊ�ߵ�ƽ
 * ����˵����GPIOx���ò���ΪGPIO_TypeDef���͵Ľṹ��ָ�룬ָ��GPIO�˿ڵĵ�ַ
 *           GPIO_Pin����ʾĳ���˿ڵ����ź�
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRL |= (1<<GPIO_Pin);
}


/* 
 * �������ܣ���������Ϊ�͵�ƽ
 * ����˵����GPIOx���ò���ΪGPIO_TypeDef���͵Ľṹ��ָ�룬ָ��GPIO�˿ڵĵ�ַ
 *           GPIO_Pin����ʾĳ���˿ڵ����ź�
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH |= (1<<GPIO_Pin);
}
