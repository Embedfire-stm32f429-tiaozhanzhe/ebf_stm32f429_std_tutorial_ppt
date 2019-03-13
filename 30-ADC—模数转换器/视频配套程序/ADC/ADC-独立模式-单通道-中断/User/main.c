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
#include "bsp_adc.h"


// ADCת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
__IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_Vol; 

static void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
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

	Rheostat_Init();
	
    while (1)
    {
    
      printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 
      printf("\r\n The current AD value = %f V \r\n",ADC_Vol);     

			ADC_Vol =(float) ADC_ConvertedValue/4096*(float)3.3; // ��ȡת����ADֵ


      Delay(0xffffee);  
    }
}

// ��ҵ

// ��PC3 �ĳ� PA4 ���������մ�������ģ����


/*********************************************END OF FILE**********************/

