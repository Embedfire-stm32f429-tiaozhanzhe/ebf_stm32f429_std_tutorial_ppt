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
extern __IO uint16_t ADC_ConvertedValue[2];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[2]={0};

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
				 Delay(0xffffee);  
				
				ADC_ConvertedValueLocal[0] =(float)((uint16_t)ADC_ConvertedValue[0]*3.3/4096); 
				ADC_ConvertedValueLocal[1] =(float)((uint16_t)ADC_ConvertedValue[1]*3.3/4096);    
				
				printf("\r\n The current AD value = 0x%08X \r\n", ADC_ConvertedValue[0]); 
				printf("\r\n The current AD value = 0x%08X \r\n", ADC_ConvertedValue[1]);     
				
				printf("\r\n The current ADC1 value = %f V \r\n",ADC_ConvertedValueLocal[0]); 
				printf("\r\n The current ADC2 value = %f V \r\n",ADC_ConvertedValueLocal[1]);   
    }
}




/*********************************************END OF FILE**********************/

