/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ڽӷ����ԣ����ڽ��յ����ݺ����ϻش���
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
#include "./key/bsp_key.h"
#include "./can/bsp_can.h"


extern uint8_t can_rx_flag;

CanTxMsg can_tx_msg;
CanRxMsg can_rx_msg;

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  uint8_t i;
  
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	Key_GPIO_Config();
  
  CAN_Test_Init();

	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART,"����һ��CANʵ��\n");
	printf("����һ��CANʵ��\n");
	
  printf("\r\n����KEY1�����ͱ���\n");

  
  
  
  while(1)
	{	
    
    //������KEY1���ͷ���һ������
		if(Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) == KEY_ON)
    {
      for(i=0;i<8;i++)
      {
        can_tx_msg.Data[i]= i; //���ݰ�������Ϊ8���ֽڣ�0-7
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
      //������յ���can����
           
      
      printf("\r\n ���յ�����\r\n");
      
      printf("\r\n ����ID=%x",can_rx_msg.ExtId);
      
      for(i=0;i<can_rx_msg.DLC;i++)
      {
        printf("\r\n rx msg = %2d ",can_rx_msg.Data[i]);

      }
      
      can_rx_flag = 0;
     
    }
    
	}	
}


//��ҵ
//1.��дcan�������ػ�ģʽ��
//2.��д��������ID�ı��ģ������Ƿ��ܽ��ճɹ���������ɹ��������޸Ĺ�����
//3.ʹ��CAN_TransmitStatus ����ⷢ��״̬��ȷ���Ƿ������


/*********************************************END OF FILE**********************/

