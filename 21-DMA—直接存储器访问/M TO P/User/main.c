/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   串口接发测试，串口接收到数据后马上回传。
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
#include "bsp_usart_dma.h"

static void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

extern uint8_t SendBuff[SENDBUFF_SIZE];

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  uint16_t i;
	
	LED_GPIO_Config();
	
	/*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
	  /*填充将要发送的数据*/
  for(i=0;i<SENDBUFF_SIZE;i++)
  {
    SendBuff[i]	 = 'A';
    
  }
	
	MtoP_DMA_Config();
	
	USART_DMACmd(DEBUG_USART, USART_DMAReq_Tx, ENABLE);

  while(1)
	{	
		LED1_TOGGLE
    Delay(0xFFFFF);
	}	
}



/*********************************************END OF FILE**********************/

