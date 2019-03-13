#include "bsp_led.h"

// 0- 首先要开GPIO端口的时钟

// 1- 要先确定引脚号

// 2- 要确定是输入还是输出 MODER

// 3- 如果是输出，那么是推挽还是开漏输出 OTYPER

// 4- 是是上拉还是下拉

// 5- 那么输出的速度是多少呢

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_AHB1PeriphClockCmd(LED_R_GPIO_CLK,ENABLE);

	GPIO_InitStruct.GPIO_Pin = LED_R_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;	
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;	
	GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
	
	GPIO_Init(LED_R_GPIO_PORT,&GPIO_InitStruct);
}


