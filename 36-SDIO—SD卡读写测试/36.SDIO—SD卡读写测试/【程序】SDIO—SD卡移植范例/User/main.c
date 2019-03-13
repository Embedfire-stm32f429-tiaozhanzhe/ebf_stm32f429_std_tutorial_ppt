/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDIO SD卡移植范例
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


//移植官方例子的步骤

//1.找到要移植的驱动文件，如bsp_sdio_sd.c
//2.找到工程测试文件，对比差异并移植
//3.使用example 里边的main.c文件测试
//4.亲手移植SDIO sd卡驱动

extern void SDCardTest(void);
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
	/* 发送一个字符串 */
	printf("这是一个SD卡测试实验\n");
	
  SDCardTest();
  while(1)
	{	
		
	}	
}



/*********************************************END OF FILE**********************/

