#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_rccclkconfig.h"

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}

int main(void)
{
  // ��������main����֮ǰ�������ļ���statup_stm32f10x_hd.s�Ѿ�����
	// SystemInit()������ϵͳʱ�ӳ�ʼ����72MHZ
	// SystemInit()��system_stm32f10x.c�ж���
	// ����û����޸�ϵͳʱ�ӣ������б�д�����޸�	
	// ��������ϵͳʱ�ӣ���ʱ�����ѡ��ʹ��HSE����HSI
	
	/* ��ϵͳʱ�ӳ�ʼ��Ϊ216M */
	HSE_SetSysClk(25,432,2,9);
	
	//HSI_SetSysClk(16,432,2,9);
	
	LED_GPIO_Config();
	
	// MCO1 ���PLLCLK	
  RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_1);

	
	while (1)
	{
		LED1( ON );			 // �� 
		Delay(0x0FFFFF);
		LED1( OFF );		  // ��
	  Delay(0x0FFFFF);
	}
}

// ��ҵ

// 1- ʹ��ʾ�������MCO1��ʱ�����������һ�´����д�Ƿ���ȷ













