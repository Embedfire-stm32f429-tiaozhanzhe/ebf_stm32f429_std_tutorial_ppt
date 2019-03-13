/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   LCD驱动
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
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./sdram/bsp_sdram.h"
#include "./lcd/bsp_lcd.h"
#include <stdlib.h>
#include "./flash/bsp_spi_flash.h"

void Delay(__IO u32 nCount); 




/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();	 
  
  SPI_FLASH_Init(); 
    
  /* 初始化串口 */
  Debug_USART_Config();
  
  printf("\r\n 秉火STM32F429 LCD 测试例程\r\n");
  
  /*初始化SDRAM模块*/
  SDRAM_Init();
  
  //初始化液晶
  LCD_Init();
  
  DIS_Line();
  DIS_Line_Layer1();
  
  
  DIS_RECT_LAYER1();
//  DIS_RECT();
  
  DIS_Line_DMA2D();
	
  dis_charater(100,100,0xBABA);
  
  dis_string(100,200,"汉字演示"); 
  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}


//作业：
//1.使用字模制作软件生成32*32大小的字模
//2.使用该字模，编写串口或液晶显示汉字的函数
//3.尝试使用不同的字模选项，输出字模，看实验现象
/*********************************************END OF FILE**********************/

