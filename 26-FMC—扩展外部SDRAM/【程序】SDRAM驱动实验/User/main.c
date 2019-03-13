/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDRAM驱动实验
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
#include "./sdram/bsp_sdram.h"

//1.初始化FMC及SDRAM
//2.使用指针直接访问 SDRAM映射的地址
//3.使用编译器强制指定变量定义的地址（必须定义为全局变量）
//4.使用sct文件实现自动分配变量的地址到SDRAM

uint16_t ptest __attribute__ ((at(SDRAM_BASE_ADDR+100)));



/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  uint16_t *pdata_test;


  uint16_t read_temp;
  

 
  
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
  //初始化SDRAM
  SDRAM_Init();
  
  
  
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART,"这是一个SDRAM测试实验\n");
	printf("这是一个SDRAM测试实验\n");
	
  
  //使用指针访问SDRAM数据,写入
  
//   pdata_test = (uint16_t *)SDRAM_BASE_ADDR;
//  *pdata_test = 0xF5F5;
  
  *(uint16_t *)(SDRAM_BASE_ADDR)  = 0xF5F5;
  
  //使用指针访问SDRAM数据,读出
//   pdata_test = (uint16_t *)SDRAM_BASE_ADDR;
//  read_temp =  *pdata_test;
  
  read_temp =  *(uint16_t *)(SDRAM_BASE_ADDR) ; 
  
  printf("\r\n 读出的数据为：0x%x\r\n",read_temp);
  
  
  
  //使用编译器强制指定变量定义的地址，赋值，写入
  ptest = 0xAA;

  
  printf("\r\n ptest：0x%x\r\n ptest的地址：0x%x",ptest,&ptest);
  
  
  
  
  
  while(1)
	{	
		
	}	
}

//作业：尝试自己定义一些变量到SDRAM，并检查变量的地址是否正常

/*********************************************END OF FILE**********************/

