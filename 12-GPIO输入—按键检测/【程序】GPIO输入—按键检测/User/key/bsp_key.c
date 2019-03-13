#include "bsp_key.h"

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// ��KEY_GPIO��ʱ��
	RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
	// ѡ��KEY_GPIO�����Ǿ�������ź�
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	// ����Ϊ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;	
	// ��������
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;	
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);
	
		// ��KEY_GPIO��ʱ��
	RCC_AHB1PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);
	// ѡ��KEY_GPIO�����Ǿ�������ź�
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	// ����Ϊ����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;	
	// ��������
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;	
	GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStruct);
	
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if ( (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)) == KEY_ON )
	{
		while( (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)) == KEY_ON );
		// ����Ӧ�Ķ���
		return KEY_ON;		
	}
	else 
	return KEY_OFF;
}

