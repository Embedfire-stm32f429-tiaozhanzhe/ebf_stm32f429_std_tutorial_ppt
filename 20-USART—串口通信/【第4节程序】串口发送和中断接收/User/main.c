/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ƶ����ˮ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "bsp_debug_usart.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	Debug_USART_Config();
	//Usart_SendByte( DEBUG_USART, 'A');
	//Usart_SendHalfWord( DEBUG_USART, 65535);
	
	//Usart_SendString( DEBUG_USART, "Ұ��STM32F429����ͨ������");
	
	printf("\r\n ����ͨ��printf�������� \r\n");
	while (1)
	{		
	}
}


// ��ҵ

// 1- ��η���һ������



/*********************************************END OF FILE**********************/

