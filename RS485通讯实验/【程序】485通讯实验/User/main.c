/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   485测试。
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
#include "./485/bsp_485.h"
#include "./key/bsp_key.h"


extern uint8_t receive_flag;
extern uint8_t ucTemp;


static void _delay(__IO u32 nCount)
{

	for(; nCount != 0; nCount--);
}

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	
  __485_USART_Config();
  
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART,"这是一个485接收回显实验\n");
	printf("这是一个485接收回显实验\n");
	
  while(1)
	{	
		/*按一次按键发送一次数据*/
		if(	Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) == KEY_ON)
		{

			
      __485_SendByte(__485_USART,0x01);
			
			printf("\r\n已使用485发送数据！\r\n");
		}
    
    if(receive_flag ==1 )
    {
       
      _delay(0xFFFFFF);
        
      printf("\r\n接收到数据包：%x",ucTemp);
    
      __485_SendByte(__485_USART,ucTemp);   
      
      receive_flag = 0;
    }

	}	
}



/*********************************************END OF FILE**********************/

