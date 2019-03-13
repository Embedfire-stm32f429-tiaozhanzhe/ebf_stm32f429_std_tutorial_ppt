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
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_systick.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();	

	SysTick_Init();
	
	/* 控制LED灯 */
	while (1)
	{
		LED_RED;
		Delay_us(100000);
		
		LED_GREEN;
		Delay_us(100000);
		
		LED_BLUE;
		Delay_us(100000);
	}
}




// 作业
// 把系统定时器的中断时间改成1ms，实现RGB灯1s的频率来闪烁









/*********************************************END OF FILE**********************/

