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
#include "./led/bsp_led.h"
#include "bsp_debug_usart.h"

static void Show_Message(void);

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	char ch;
	LED_GPIO_Config();
	Debug_USART_Config();
	//Usart_SendByte( DEBUG_USART, 'A');
	//Usart_SendHalfWord( DEBUG_USART, 65535);
	
	//Usart_SendString( DEBUG_USART, "野火STM32F429串口通信例程");
	
//	printf("\r\n 串口通信printf函数测试 \r\n");
//	
//	ch = getchar();
//	printf("\r\n %c \r\n",ch);
	
	Show_Message();
while(1)
	{	
    /* 获取字符指令 */
    ch=getchar();
    printf("接收到字符：%c\n",ch);
    
    /* 根据字符指令控制RGB彩灯颜色 */
    switch(ch)
    {
      case '1':
        LED_RED;
      break;
      case '2':
        LED_GREEN;
      break;
      case '3':
        LED_BLUE;
      break;
      case '4':
        LED_YELLOW;
      break;
      case '5':
        LED_PURPLE;
      break;
      case '6':
        LED_CYAN;
      break;
      case '7':
        LED_WHITE;
      break;
      case '8':
        LED_RGBOFF;
      break;
      default:
        /* 如果不是指定指令字符，打印提示信息 */
        Show_Message();
        break;      
    }   
	}
}


static void Show_Message(void)
{
  printf("\r\n   这是一个通过串口通信指令控制RGB彩灯实验 \n");
  printf("使用  USART1  参数为：%d 8-N-1 \n",DEBUG_USART_BAUDRATE);
  printf("开发板接到指令后控制RGB彩灯颜色，指令对应如下：\n");
  printf("   指令   ------ 彩灯颜色 \n");
  printf("     1    ------    红 \n");
  printf("     2    ------    绿 \n");
  printf("     3    ------    蓝 \n");
  printf("     4    ------    黄 \n");
  printf("     5    ------    紫 \n");
  printf("     6    ------    青 \n");
  printf("     7    ------    白 \n");
  printf("     8    ------    灭 \n");  
}

// 作业

// 用串口2实现这两个例程


/*********************************************END OF FILE**********************/

