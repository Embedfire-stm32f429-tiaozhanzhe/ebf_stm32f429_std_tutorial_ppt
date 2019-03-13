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
#include "./usart/bsp_debug_usart.h"
#include "./key/bsp_key.h"
#include "./can/bsp_can.h"


extern uint8_t can_rx_flag;

CanTxMsg can_tx_msg;
CanRxMsg can_rx_msg;

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  uint8_t i;
  
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	Key_GPIO_Config();
  
  CAN_Test_Init();

	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART,"这是一个CAN实验\n");
	printf("这是一个CAN实验\n");
	
  printf("\r\n按下KEY1，发送报文\n");

  
  
  
  while(1)
	{	
    
    //若按下KEY1，就发送一个报文
		if(Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) == KEY_ON)
    {
      for(i=0;i<8;i++)
      {
        can_tx_msg.Data[i]= i; //数据包的内容为8个字节，0-7
        printf("\r\n tx msg = %2d ",can_tx_msg.Data[i]);
      }
      
      can_tx_msg.DLC = 8;
      can_tx_msg.IDE = CAN_ID_EXT ;
      can_tx_msg.ExtId = MESSAGE_EXID1;
      can_tx_msg.RTR = CAN_RTR_DATA ;
      can_tx_msg.StdId = 0;     
      
      CAN_Transmit(CAN_NUM,&can_tx_msg);

    
    }
    
    
    if(can_rx_flag ==1 )
    {
      //处理接收到的can数据
           
      
      printf("\r\n 接收到报文\r\n");
      
      printf("\r\n 报文ID=%x",can_rx_msg.ExtId);
      
      for(i=0;i<can_rx_msg.DLC;i++)
      {
        printf("\r\n rx msg = %2d ",can_rx_msg.Data[i]);

      }
      
      can_rx_flag = 0;
     
    }
    
	}	
}


//作业
//1.编写can驱动（回环模式）
//2.编写发送其它ID的报文，尝试是否能接收成功，如果不成功，尝试修改过滤器
//3.使用CAN_TransmitStatus 来检测发送状态，确认是否发送完成


/*********************************************END OF FILE**********************/

