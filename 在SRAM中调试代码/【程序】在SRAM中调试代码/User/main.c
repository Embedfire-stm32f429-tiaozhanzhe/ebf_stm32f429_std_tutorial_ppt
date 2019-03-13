/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ƶ����ˮ��
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



//1.�������԰汾�ĳ���
//2.�޸�sct�ļ���ʹ�ó������ӵ��ڲ�SRAM
//3.�޸��ж�������Ĵ洢λ�ã��ĳɴ洢���ڲ�SRAM
//4.�޸����������ã�ʹ�õ�����ذ�ť��ʱ��������ص��ڲ�sram

//5.������Ҫ�����޸�.ini�ļ����ã������޸�boot���ŵ�ƽ(ֻ֧�ֵ���ģʽ���Ҳ��ܸ�λ)

//��ҵ���Լ����԰���ˮ�Ƴ���ĵ�RAM����ģʽ

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

	/* ����LED�� */
	while (1)
	{
		LED1( ON );			 // �� 
		Delay(0xFFFFFF);
		LED1( OFF );		  // ��

		LED2( ON );			// �� 
		Delay(0xFFFFFF);
		LED2( OFF );		  // ��

		LED3( ON );			 // �� 
		Delay(0xFFFFFF);
		LED3( OFF );		  // ��	

		/*������ʾ ������������� ��ɫ*/
		LED_RED;
		Delay(0xFFFFFF);
		
		LED_GREEN;
		Delay(0xFFFFFF);
		
		LED_BLUE;
		Delay(0xFFFFFF);
		
		LED_YELLOW;
		Delay(0xFFFFFF);
		
		LED_PURPLE;
		Delay(0xFFFFFF);
				
		LED_CYAN;
		Delay(0xFFFFFF);
		
		LED_WHITE;
		Delay(0xFFFFFF);
		
		LED_RGBOFF;
		Delay(0xFFFFFF);
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

