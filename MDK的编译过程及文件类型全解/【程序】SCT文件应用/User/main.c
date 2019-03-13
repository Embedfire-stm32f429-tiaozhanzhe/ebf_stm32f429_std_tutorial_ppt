/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��дSDRAM
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
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./sdram/bsp_sdram.h"
#include <stdlib.h>



//1.�޸������ļ����ڷ�ɢ���ش���֮ǰ��ʼ��sdram
//2.�޸�sct�ļ���ʹ�ñ���Ĭ�Ϸ��䵽�ⲿSDRAM
//3.�޸�sct�ļ���ʹ�ö������䵽sdram��mallocʹ�õĿռ䣩
//4.����

//5.�Ľ���Ĭ��ʹ���ڲ�SRAM������Ҫʱ��ʹ���ⲿSDRAM
//6.�Ѷѿռ���䵽�ⲿsdram


//��ҵ��
//1.ѧϰʹ��fromelf ���ɸ���axf����Ϣ�ļ���ѧϰaxf�ļ���ߵ����ݡ�
//2.ʹ��fromelf����bin��hex�ļ���������mdk�������������bin�ļ���
//3.�����ڹ����ж��岻ͬ���Եı�����RO RW data �����ֲ����������۲�map�ļ��ı仯��
//4.�����Լ��޸�sct�ļ���ʵ�ֱ���ָ�����䵽ĳ���ռ䣬���ⲿSDRAM������ڲ�SRAM��


void Delay(__IO u32 nCount); 


#define __EXRAM   __attribute__ ((section ("EXRAM")))

uint8_t  a  __EXRAM =0;

uint8_t b=10;

uint8_t c[40] __EXRAM={0};
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  
  uint8_t * test_p;
  c[0]=a+b;
  
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
    
  /* ��ʼ������ */
  Debug_USART_Config();
  
  printf("\r\n ����STM32F429 SDRAM ��д��������\r\n");
  
  printf("c =%d",c[0]);
  
  printf("\r\nc addr =0x%x",(uint32_t)&c);

  
  printf("\r\nb addr =0x%x",(uint32_t)&b);
  
  
  test_p = (uint8_t *)malloc(10);
  
  
  printf("\r\nmalloc addr = 0x%x",(uint32_t)test_p);
  

  
  /*����������ʾ���ڶ�дSDRAM����*/
  LED_BLUE;
  
	

  while(1); 
 

}


void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

