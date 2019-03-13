/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   串口接发测试，串口接收到数据后马上回传。
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
#include "./flash/bsp_spi_flash.h"

uint8_t readBuff[4096] = {0x0};
uint8_t writeBuff[4096] = {0x0};

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  uint32_t device_id = 0;
  uint32_t i=0;
 
  
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
  
  FLASH_SPI_Config();
	
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART,"这是一个FLASH实验\n");
	printf("这是一个FLASH实验\n");

  device_id = Read_Device_ID();
  
  printf("device_id =0x%x",device_id);
  
  
  erace_setor(0x00);   
  
  //读出擦除后的数据
  Read_buffer(readBuff,0x00,4096);  
  
  
  printf("\r\n*************读出擦除后的数据**********\r\n");

  for(i=0;i<4096;i++)
      printf("0x%x ",readBuff[i]);
  
  for(i=0;i<256;i++)
      writeBuff[i] = i;
  
  
  Write_buffer(writeBuff,0x00,256);
  
  
    //读出擦除后的数据
  Read_buffer(readBuff,0x00,256);  
  
  
  printf("\r\n*************读出写入后的数据**********\r\n");

  for(i=0;i<256;i++)
      printf("0x%x ",readBuff[i]);
      
      
  
  while(1)
	{	
		
	}	
}

//作业：
//1.参考本例程，自己编写SPI 读写FLASH的驱动。
//2.尝试使用FLASH存储float型的数据
//3.尝试写入数据前，不对FLASH空间进行擦除操作，检验数据是否正常。


/*********************************************END OF FILE**********************/

