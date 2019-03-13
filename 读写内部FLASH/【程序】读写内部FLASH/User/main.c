/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��д�ڲ�FLASHʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"


//���ڲ�FLASHд�����ݲ�����������У��
//д�룺������ѡ�����λ����
//��������(Ҫע��ѡ������FLASH�ռ䣬��ֹ���ǳ�������)��
//д������,д�����ݺ�Ҫע������

//������ֱ��ʹ��ָ���ȡ���ݡ�


//��ҵ��
//�����ڳ������е�ʱ���������0����ʵ������

//���Բ�д֮ǰ����������⺯���ķ���ֵ

#define PROGRAM_ADDR  0x08008000

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  
  uint32_t write_data =0x12345678;
  
  uint32_t *read_pointer;
  
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
	/* ����һ���ַ��� */
	printf("����һ����д�ڲ�FLASHʵ��\n");
	
  FLASH_Unlock();
  
  FLASH_EraseSector(FLASH_Sector_2,VoltageRange_3);
  
  printf("\r\n д�������Ϊ0x%x",write_data);
  
  FLASH_ProgramWord(PROGRAM_ADDR,write_data);
  
  FLASH_Lock();
  
  read_pointer = (uint32_t *)PROGRAM_ADDR;
  
  
  printf("\r\n ����������Ϊ0x%x",*read_pointer);
  
    
  
  
  while(1)
	{	
		
	}	
}



/*********************************************END OF FILE**********************/

