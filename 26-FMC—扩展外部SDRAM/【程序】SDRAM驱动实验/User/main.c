/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDRAM����ʵ��
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
#include "./sdram/bsp_sdram.h"

//1.��ʼ��FMC��SDRAM
//2.ʹ��ָ��ֱ�ӷ��� SDRAMӳ��ĵ�ַ
//3.ʹ�ñ�����ǿ��ָ����������ĵ�ַ�����붨��Ϊȫ�ֱ�����
//4.ʹ��sct�ļ�ʵ���Զ���������ĵ�ַ��SDRAM

uint16_t ptest __attribute__ ((at(SDRAM_BASE_ADDR+100)));



/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  uint16_t *pdata_test;


  uint16_t read_temp;
  

 
  
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	
  //��ʼ��SDRAM
  SDRAM_Init();
  
  
  
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART,"����һ��SDRAM����ʵ��\n");
	printf("����һ��SDRAM����ʵ��\n");
	
  
  //ʹ��ָ�����SDRAM����,д��
  
//   pdata_test = (uint16_t *)SDRAM_BASE_ADDR;
//  *pdata_test = 0xF5F5;
  
  *(uint16_t *)(SDRAM_BASE_ADDR)  = 0xF5F5;
  
  //ʹ��ָ�����SDRAM����,����
//   pdata_test = (uint16_t *)SDRAM_BASE_ADDR;
//  read_temp =  *pdata_test;
  
  read_temp =  *(uint16_t *)(SDRAM_BASE_ADDR) ; 
  
  printf("\r\n ����������Ϊ��0x%x\r\n",read_temp);
  
  
  
  //ʹ�ñ�����ǿ��ָ����������ĵ�ַ����ֵ��д��
  ptest = 0xAA;

  
  printf("\r\n ptest��0x%x\r\n ptest�ĵ�ַ��0x%x",ptest,&ptest);
  
  
  
  
  
  while(1)
	{	
		
	}	
}

//��ҵ�������Լ�����һЩ������SDRAM�����������ĵ�ַ�Ƿ�����

/*********************************************END OF FILE**********************/

