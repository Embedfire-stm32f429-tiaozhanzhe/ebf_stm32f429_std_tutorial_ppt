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
#include "./usart/bsp_debug_usart.h"
#include "./flash/bsp_spi_flash.h"

uint8_t readBuff[4096] = {0x0};
uint8_t writeBuff[4096] = {0x0};

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  uint32_t device_id = 0;
  uint32_t i=0;
 
  
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
  
  FLASH_SPI_Config();
	
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART,"����һ��FLASHʵ��\n");
	printf("����һ��FLASHʵ��\n");

  device_id = Read_Device_ID();
  
  printf("device_id =0x%x",device_id);
  
  
  erace_setor(0x00);   
  
  //���������������
  Read_buffer(readBuff,0x00,4096);  
  
  
  printf("\r\n*************���������������**********\r\n");

  for(i=0;i<4096;i++)
      printf("0x%x ",readBuff[i]);
  
  for(i=0;i<256;i++)
      writeBuff[i] = i;
  
  
  Write_buffer(writeBuff,0x00,256);
  
  
    //���������������
  Read_buffer(readBuff,0x00,256);  
  
  
  printf("\r\n*************����д��������**********\r\n");

  for(i=0;i<256;i++)
      printf("0x%x ",readBuff[i]);
      
      
  
  while(1)
	{	
		
	}	
}

//��ҵ��
//1.�ο������̣��Լ���дSPI ��дFLASH��������
//2.����ʹ��FLASH�洢float�͵�����
//3.����д������ǰ������FLASH�ռ���в������������������Ƿ�������


/*********************************************END OF FILE**********************/

