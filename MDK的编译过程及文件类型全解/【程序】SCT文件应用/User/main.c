/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   读写SDRAM
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
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./sdram/bsp_sdram.h"
#include <stdlib.h>



//1.修改启动文件，在分散加载代码之前初始化sdram
//2.修改sct文件，使得变量默认分配到外部SDRAM
//3.修改sct文件，使得堆区分配到sdram（malloc使用的空间）
//4.测试

//5.改进，默认使用内部SRAM，有需要时才使用外部SDRAM
//6.把堆空间分配到外部sdram


//作业：
//1.学习使用fromelf 生成各种axf的信息文件，学习axf文件里边的内容。
//2.使用fromelf生成bin及hex文件，尝试在mdk中添加命令生成bin文件。
//3.尝试在工程中定义不同属性的变量（RO RW data ，及局部变量），观察map文件的变化。
//4.尝试自己修改sct文件，实现变量指定分配到某个空间，（外部SDRAM或高速内部SRAM）


void Delay(__IO u32 nCount); 


#define __EXRAM   __attribute__ ((section ("EXRAM")))

uint8_t  a  __EXRAM =0;

uint8_t b=10;

uint8_t c[40] __EXRAM={0};
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
  
  uint8_t * test_p;
  c[0]=a+b;
  
	/* LED 端口初始化 */
	LED_GPIO_Config();	 
    
  /* 初始化串口 */
  Debug_USART_Config();
  
  printf("\r\n 秉火STM32F429 SDRAM 读写测试例程\r\n");
  
  printf("c =%d",c[0]);
  
  printf("\r\nc addr =0x%x",(uint32_t)&c);

  
  printf("\r\nb addr =0x%x",(uint32_t)&b);
  
  
  test_p = (uint8_t *)malloc(10);
  
  
  printf("\r\nmalloc addr = 0x%x",(uint32_t)test_p);
  

  
  /*蓝灯亮，表示正在读写SDRAM测试*/
  LED_BLUE;
  
	

  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

