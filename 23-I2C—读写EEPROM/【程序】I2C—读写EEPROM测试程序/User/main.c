/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   EEPROM测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./i2c/bsp_i2c_eeprom.h"




/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  
  uint8_t test_addr = 0x02;
  uint8_t test_writeData = 0x27;
  uint8_t test_readData =0;
  
  
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART,"这是一个EEPROM测试实验\n");
	printf("这是一个EEPROM测试实验\n");
  
  
  printf("\r\n初始化I2C\r\n");
  
  EEPROM_GPIO_Config();
  EEPROM_I2C_ModeConfig();
  
  printf("\r\nI2C初始化完毕\r\n");  
  
  EEPROM_Byte_Write(&test_writeData,test_addr);

  test_readData = EEPROM_Byte_Read(test_addr);  

  printf("test_readData =0x%x",test_readData);
	
  while(1)
	{	
		
	}	
}

//1.重新自己编写本测试程序
//2.把IIC的SCL跟SDA线初始化成推挽输出模式，测试一下是否正常
//3.尝试使用EEPROM记录float型以及int型的变量。



/*********************************************END OF FILE**********************/

