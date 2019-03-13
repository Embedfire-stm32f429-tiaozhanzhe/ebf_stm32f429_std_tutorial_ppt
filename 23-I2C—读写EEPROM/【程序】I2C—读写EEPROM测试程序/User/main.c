/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   EEPROM����
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
#include "./i2c/bsp_i2c_eeprom.h"




/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  
  uint8_t test_addr = 0x02;
  uint8_t test_writeData = 0x27;
  uint8_t test_readData =0;
  
  
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART,"����һ��EEPROM����ʵ��\n");
	printf("����һ��EEPROM����ʵ��\n");
  
  
  printf("\r\n��ʼ��I2C\r\n");
  
  EEPROM_GPIO_Config();
  EEPROM_I2C_ModeConfig();
  
  printf("\r\nI2C��ʼ�����\r\n");  
  
  EEPROM_Byte_Write(&test_writeData,test_addr);

  test_readData = EEPROM_Byte_Read(test_addr);  

  printf("test_readData =0x%x",test_readData);
	
  while(1)
	{	
		
	}	
}

//1.�����Լ���д�����Գ���
//2.��IIC��SCL��SDA�߳�ʼ�����������ģʽ������һ���Ƿ�����
//3.����ʹ��EEPROM��¼float���Լ�int�͵ı�����



/*********************************************END OF FILE**********************/

