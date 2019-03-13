#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_rccclkconfig.h"

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

int main(void)
{
  // 程序来到main函数之前，启动文件：statup_stm32f10x_hd.s已经调用
	// SystemInit()函数把系统时钟初始化成72MHZ
	// SystemInit()在system_stm32f10x.c中定义
	// 如果用户想修改系统时钟，可自行编写程序修改	
	// 重新设置系统时钟，这时候可以选择使用HSE还是HSI
	
	/* 把系统时钟初始化为216M */
	HSE_SetSysClk(25,432,2,9);
	
	//HSI_SetSysClk(16,432,2,9);
	
	LED_GPIO_Config();
	
	// MCO1 输出PLLCLK	
  RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_1);

	
	while (1)
	{
		LED1( ON );			 // 亮 
		Delay(0x0FFFFF);
		LED1( OFF );		  // 灭
	  Delay(0x0FFFFF);
	}
}

// 作业

// 1- 使用示波器监控MCO1的时钟输出，检验一下代码编写是否正确













