/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   使用外部中断EXTI检测按键，控制彩灯。
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
#include "./key/bsp_exti.h"
#include "./usart/bsp_debug_usart.h"

void Delay(__IO u32 nCount); 
void SysClockResetFromStop(void);
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
  uint8_t systemClock=0;
  
  RCC_ClocksTypeDef  rccClockFreq;
  
	/* LED 端口初始化 */
	LED_GPIO_Config();
  
  Debug_USART_Config();
  	
	/* 初始化EXTI中断，按下按键会触发中断，
  *  触发中断会进入stm32f4xx_it.c文件中的函数
	*  KEY1_IRQHandler和KEY2_IRQHandler，处理中断，反转LED灯。
	*/
//	EXTI_Key_Config(); 
  
  if(PWR_GetFlagStatus(PWR_FLAG_WU) ==SET)
  {
    printf("waup 引脚复位");
    PWR_ClearFlag(PWR_FLAG_WU);
  }
  else
    printf("复位按键复位");
  
  
	
	/* 等待中断，由于使用中断方式，CPU不用轮询按键 */
	while(1)                            
	{
    
    LED_RED;
    
    Delay(0xFFFFFF);
    
    LED_GREEN;
    
     Delay(0xFFFFFF);
    
//    systemClock = RCC_GetSYSCLKSource();
//    RCC_GetClocksFreq(&rccClockFreq);
    
//    printf("\r\n before stop");

//    printf("\r\n systemClock =%x",systemClock);
//    
//    printf("\r\n HCLK_Frequency =%d,PCLK1_Frequency=%d,PCLK2_Frequency=%d,SYSCLK_Frequency=%d",
//                        rccClockFreq.HCLK_Frequency,
//                        rccClockFreq.PCLK1_Frequency,
//                        rccClockFreq.PCLK2_Frequency,
//                        rccClockFreq.SYSCLK_Frequency);
    PWR_WakeUpPinCmd(ENABLE);
    PWR_EnterSTANDBYMode(); 
    
//    systemClock = RCC_GetSYSCLKSource();
//    RCC_GetClocksFreq(&rccClockFreq);
    
    
//    SysClockResetFromStop();
    
//    printf("\r\n \r\n After stop");

//    printf("\r\n systemClock =%x",systemClock);
//    
//    printf("\r\n HCLK_Frequency =%d,PCLK1_Frequency=%d,PCLK2_Frequency=%d,SYSCLK_Frequency=%d",
//                        rccClockFreq.HCLK_Frequency,
//                        rccClockFreq.PCLK1_Frequency,
//                        rccClockFreq.PCLK2_Frequency,
//                        rccClockFreq.SYSCLK_Frequency);
    
    

    
    LED_BLUE;
    
    Delay(0xFFFFFF);
    
	}
}



void Delay(__IO u32 nCount)
{
  for(;nCount>0;nCount--);

}




void SysClockResetFromStop(void)
{
  RCC_HSEConfig (RCC_HSE_ON);
  
  while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) != RESET)
  {}
    
   RCC_PLLCmd(ENABLE);
    
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) !=RESET)
   {}
     
  RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);   
     
     while(RCC_GetSYSCLKSource() != 0x08)
     {}
     
    
  
  
}


//1.让芯片进入睡眠模式，并使用systick定时器唤醒。
//2.尝试使用systick能否唤醒停止模式的芯片。
/*********************************************END OF FILE**********************/

