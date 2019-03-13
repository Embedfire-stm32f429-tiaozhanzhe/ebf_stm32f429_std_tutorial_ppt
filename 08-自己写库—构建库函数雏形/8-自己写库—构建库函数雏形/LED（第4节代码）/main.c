/**
  * �Լ�д��-�����⺯������
	*/
	
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "bsp_led.h"


int main(void)
{
	/* ʹ��GPIOH�˿ڵ�ʱ�� */
	RCC_AHB1ENR |= (1<<7);
/*=========================PH10===============================*/	
	#if 0
	// 1-ȷ�����ź�
	
  // 2-ȷ�������뻹�����
	/* PH10����Ϊ��� */
	GPIOH->MODER &= ~(3<<2*10);
	GPIOH->MODER |= (1<<2*10);
	
	// 3-������������������	
	/* ����Ϊ���� */
  GPIOH->PUPDR &= ~(3<<2*10);
	GPIOH->PUPDR |= (1<<2*10);
	
	// 4-ȷ�������컹�ǿ�©���
	/* ����PH10Ϊ������� */
	GPIOH->OTYPER &= ~(1<<10);
	
  // 5-����������ٶ�
	/* PH10�ٶ�Ϊ50M */
	GPIOH->OSPEEDR &= ~(3<<2*10);
	GPIOH->OSPEEDR |= (2<<2*10);
	#else
	LED_GPIO_Config();
	#endif
	
/*============================================================*/

	//GPIO_ResetBits( LED_R_GPIO_PORT,LED_R_GPIO_PIN );
	//GPIO_ResetBits( LED_G_GPIO_PORT,LED_G_GPIO_PIN );
	GPIO_ResetBits( LED_B_GPIO_PORT,LED_B_GPIO_PIN );

	
	while(1);
}


/* ����Ϊ�գ�Ŀ����Ϊ��ƭ�������������� */
void SystemInit(void)
{
	
}

