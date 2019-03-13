/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ڽӷ����ԣ����ڽ��յ����ݺ����ϻش���
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
#include "bsp_led.h"
#include "bsp_usart_dma.h"

static void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}

extern uint8_t SendBuff[SENDBUFF_SIZE];

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  uint16_t i;
	
	LED_GPIO_Config();
	
	/*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
	  /*��佫Ҫ���͵�����*/
  for(i=0;i<SENDBUFF_SIZE;i++)
  {
    SendBuff[i]	 = 'A';
    
  }
	
	MtoP_DMA_Config();
	
	USART_DMACmd(DEBUG_USART, USART_DMAReq_Tx, ENABLE);

  while(1)
	{	
		LED1_TOGGLE
    Delay(0xFFFFF);
	}	
}



/*********************************************END OF FILE**********************/

