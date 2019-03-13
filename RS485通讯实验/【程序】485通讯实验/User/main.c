/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   485���ԡ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
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
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
  __485_USART_Config();
  
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART,"����һ��485���ջ���ʵ��\n");
	printf("����һ��485���ջ���ʵ��\n");
	
  while(1)
	{	
		/*��һ�ΰ�������һ������*/
		if(	Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) == KEY_ON)
		{

			
      __485_SendByte(__485_USART,0x01);
			
			printf("\r\n��ʹ��485�������ݣ�\r\n");
		}
    
    if(receive_flag ==1 )
    {
       
      _delay(0xFFFFFF);
        
      printf("\r\n���յ����ݰ���%x",ucTemp);
    
      __485_SendByte(__485_USART,ucTemp);   
      
      receive_flag = 0;
    }

	}	
}



/*********************************************END OF FILE**********************/

