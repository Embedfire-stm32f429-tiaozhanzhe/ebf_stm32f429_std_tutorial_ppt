#include "bsp_key.h"

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// 打开KEY_GPIO的时钟
	RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
	// 选定KEY_GPIO，就是具体的引脚号
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	// 配置为输入
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;	
	// 配置下拉
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;	
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);
	
		// 打开KEY_GPIO的时钟
	RCC_AHB1PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);
	// 选定KEY_GPIO，就是具体的引脚号
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	// 配置为输入
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;	
	// 配置下拉
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;	
	GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStruct);
	
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if ( (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)) == KEY_ON )
	{
		while( (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)) == KEY_ON );
		// 做相应的动作
		return KEY_ON;		
	}
	else 
	return KEY_OFF;
}

