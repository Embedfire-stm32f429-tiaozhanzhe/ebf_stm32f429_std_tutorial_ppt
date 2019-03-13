/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   读写内部FLASH实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"


//向内部FLASH写入数据并读出来进行校验
//写入：解锁、选择操作位数、
//擦除扇区(要注意选择空余的FLASH空间，防止覆盖程序数据)、
//写入数据,写完数据后要注意上锁

//读出：直接使用指针读取数据。


//作业：
//尝试在程序运行的时候擦除扇区0，看实验现象。

//尝试擦写之前不解锁，检测函数的返回值

#define PROGRAM_ADDR  0x08008000

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  
  uint32_t write_data =0x12345678;
  
  uint32_t *read_pointer;
  
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
	/* 发送一个字符串 */
	printf("这是一个读写内部FLASH实验\n");
	
  FLASH_Unlock();
  
  FLASH_EraseSector(FLASH_Sector_2,VoltageRange_3);
  
  printf("\r\n 写入的数据为0x%x",write_data);
  
  FLASH_ProgramWord(PROGRAM_ADDR,write_data);
  
  FLASH_Lock();
  
  read_pointer = (uint32_t *)PROGRAM_ADDR;
  
  
  printf("\r\n 读出的数据为0x%x",*read_pointer);
  
    
  
  
  while(1)
	{	
		
	}	
}



/*********************************************END OF FILE**********************/

