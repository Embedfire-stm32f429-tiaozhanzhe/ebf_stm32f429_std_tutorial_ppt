/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��дEEPROM
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
#include "./i2c/bsP_i2c_ee.h"
#include "./led/bsp_led.h"



#define  EEP_Firstpage      0x00
uint8_t I2c_Buf_Write[256];
uint8_t I2c_Buf_Read[256];
uint8_t I2C_Test(void);


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  LED_GPIO_Config();
	
	LED_BLUE;
  /*��ʼ��USART1*/
  Debug_USART_Config(); 

	printf("\r\n ��ӭʹ�ñ���  STM32 F429 �����塣\r\n");		 

	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");

	/* I2C �����(AT24C02)ʼ�� */
	I2C_EE_Init();
 	 
	if(I2C_Test() ==1)
	{
			LED_GREEN;
	}
	else
	{
			LED_RED;
	}
  
  while (1)
  {      
  }  

}




/**
  * @brief  I2C(AT24C02)��д����
  * @param  ��
  * @retval ��������1 ������������0
  */
uint8_t I2C_Test(void)
{
	u16 i;

	EEPROM_INFO("д�������");
    
	for ( i=0; i<=255; i++ ) //��仺��
  {   
    I2c_Buf_Write[i] = i;

    printf("0x%02X ", I2c_Buf_Write[i]);
    if(i%16 == 15)    
        printf("\n\r");    
   }

  //��I2c_Buf_Write��˳�����������д��EERPOM�� 
	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, 256);
  
  EEPROM_INFO("д�ɹ�");
   
  EEPROM_INFO("����������");
  //��EEPROM��������˳�򱣳ֵ�I2c_Buf_Read��
	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
   
  //��I2c_Buf_Read�е�����ͨ�����ڴ�ӡ
	for (i=0; i<256; i++)
	{	
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
			printf("0x%02X ", I2c_Buf_Read[i]);
			EEPROM_ERROR("����:I2C EEPROMд������������ݲ�һ��");
			return 0;
		}
    printf("0x%02X ", I2c_Buf_Read[i]);
    if(i%16 == 15)    
        printf("\n\r");
    
	}
  EEPROM_INFO("I2C(AT24C02)��д���Գɹ�");
	return 1;
}


//��ҵ��
//ʹ�����IIC���Զ�ȡ���ݴ���оƬ�İ汾�š�

/*********************************************END OF FILE**********************/

