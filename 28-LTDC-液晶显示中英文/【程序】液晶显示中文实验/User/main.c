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
#include "./flash/bsp_spi_flash.h"

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
  
  SPI_FLASH_Init(); 
    
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
	
  dis_charater(100,100,0xBABA);
  
  dis_string(100,200,"������ʾ"); 
  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}


//��ҵ��
//1.ʹ����ģ�����������32*32��С����ģ
//2.ʹ�ø���ģ����д���ڻ�Һ����ʾ���ֵĺ���
//3.����ʹ�ò�ͬ����ģѡ������ģ����ʵ������
/*********************************************END OF FILE**********************/

