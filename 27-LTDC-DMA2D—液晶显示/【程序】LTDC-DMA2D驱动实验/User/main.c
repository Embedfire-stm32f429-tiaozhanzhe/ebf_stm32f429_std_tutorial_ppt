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
	

  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}


//1.自己写一遍LTDC初始化驱动
//2.使用直接操作显存的方式，在第2层xy坐标为(20，20)的位置显示一条长度为50像素点的黄色的横线
//3.使用DMA2D操作显存的方式，在第2层xy坐标为(20，20)的位置显示一条长度为50像素点的黄色的横线
//4.尝试一下使用透明度进行混合操作，比如上层显示半透明红色，底层显示蓝色，查看液晶屏的显示效果

/*********************************************END OF FILE**********************/

