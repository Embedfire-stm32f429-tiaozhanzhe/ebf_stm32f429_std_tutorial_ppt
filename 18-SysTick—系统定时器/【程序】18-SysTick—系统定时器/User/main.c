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
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_systick.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	

	SysTick_Init();
	
	/* ����LED�� */
	while (1)
	{
		LED_RED;
		Delay_us(100000);
		
		LED_GREEN;
		Delay_us(100000);
		
		LED_BLUE;
		Delay_us(100000);
	}
}




// ��ҵ
// ��ϵͳ��ʱ�����ж�ʱ��ĳ�1ms��ʵ��RGB��1s��Ƶ������˸









/*********************************************END OF FILE**********************/

