/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   LCD����
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
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./sdram/bsp_sdram.h"
#include "./lcd/bsp_lcd.h"
#include <stdlib.h>


void Delay(__IO u32 nCount); 


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
    
  /* ��ʼ������ */
  Debug_USART_Config();
  
  printf("\r\n ����STM32F429 LCD ��������\r\n");
  
  /*��ʼ��SDRAMģ��*/
  SDRAM_Init();
  
  //��ʼ��Һ��
  LCD_Init();
  
  DIS_Line();
  DIS_Line_Layer1();
  
  
  DIS_RECT_LAYER1();
//  DIS_RECT();
  
  DIS_Line_DMA2D();
	

  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}


//1.�Լ�дһ��LTDC��ʼ������
//2.ʹ��ֱ�Ӳ����Դ�ķ�ʽ���ڵ�2��xy����Ϊ(20��20)��λ����ʾһ������Ϊ50���ص�Ļ�ɫ�ĺ���
//3.ʹ��DMA2D�����Դ�ķ�ʽ���ڵ�2��xy����Ϊ(20��20)��λ����ʾһ������Ϊ50���ص�Ļ�ɫ�ĺ���
//4.����һ��ʹ��͸���Ƚ��л�ϲ����������ϲ���ʾ��͸����ɫ���ײ���ʾ��ɫ���鿴Һ��������ʾЧ��

/*********************************************END OF FILE**********************/

