#include "bsp_led.h"

// 0- ����Ҫ��GPIO�˿ڵ�ʱ��

// 1- Ҫ��ȷ�����ź�

// 2- Ҫȷ�������뻹����� MODER

// 3- ������������ô�����컹�ǿ�©��� OTYPER

// 4- ����������������

// 5- ��ô������ٶ��Ƕ�����

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


