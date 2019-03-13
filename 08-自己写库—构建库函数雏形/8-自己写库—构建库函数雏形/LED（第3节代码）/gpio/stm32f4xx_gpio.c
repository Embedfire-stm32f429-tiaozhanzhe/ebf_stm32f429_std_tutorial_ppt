#include "stm32f4xx_gpio.h"

/* 
 * 函数功能：设置引脚为高电平
 * 参数说明：GPIOx：该参数为GPIO_TypeDef类型的结构体指针，指向GPIO端口的地址
 *           GPIO_Pin：表示某个端口的引脚号
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRL |= (1<<GPIO_Pin);
}


/* 
 * 函数功能：设置引脚为低电平
 * 参数说明：GPIOx：该参数为GPIO_TypeDef类型的结构体指针，指向GPIO端口的地址
 *           GPIO_Pin：表示某个端口的引脚号
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH |= (1<<GPIO_Pin);
}
