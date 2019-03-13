/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDIO SD����ֲ����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"


//��ֲ�ٷ����ӵĲ���

//1.�ҵ�Ҫ��ֲ�������ļ�����bsp_sdio_sd.c
//2.�ҵ����̲����ļ����ԱȲ��첢��ֲ
//3.ʹ��example ��ߵ�main.c�ļ�����
//4.������ֲSDIO sd������

extern void SDCardTest(void);
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
	/* ����һ���ַ��� */
	printf("����һ��SD������ʵ��\n");
	
  SDCardTest();
  while(1)
	{	
		
	}	
}



/*********************************************END OF FILE**********************/

