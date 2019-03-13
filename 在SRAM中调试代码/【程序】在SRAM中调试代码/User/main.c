/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   控制多彩流水灯
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



//1.创建调试版本的程序
//2.修改sct文件，使得程序被链接到内部SRAM
//3.修改中断向量表的存储位置，改成存储到内部SRAM
//4.修改下载器配置，使得点击下载按钮的时候程序被下载到内部sram

//5.根据需要，可修改.ini文件配置，不用修改boot引脚电平(只支持调试模式，且不能复位)

//作业：自己尝试把流水灯程序改到RAM调试模式

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

	/* 控制LED灯 */
	while (1)
	{
		LED1( ON );			 // 亮 
		Delay(0xFFFFFF);
		LED1( OFF );		  // 灭

		LED2( ON );			// 亮 
		Delay(0xFFFFFF);
		LED2( OFF );		  // 灭

		LED3( ON );			 // 亮 
		Delay(0xFFFFFF);
		LED3( OFF );		  // 灭	

		/*轮流显示 红绿蓝黄紫青白 颜色*/
		LED_RED;
		Delay(0xFFFFFF);
		
		LED_GREEN;
		Delay(0xFFFFFF);
		
		LED_BLUE;
		Delay(0xFFFFFF);
		
		LED_YELLOW;
		Delay(0xFFFFFF);
		
		LED_PURPLE;
		Delay(0xFFFFFF);
				
		LED_CYAN;
		Delay(0xFFFFFF);
		
		LED_WHITE;
		Delay(0xFFFFFF);
		
		LED_RGBOFF;
		Delay(0xFFFFFF);
	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

