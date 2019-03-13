/**
  * �½�����ģ�桪�Ĵ����汾
	*/
	
#include "stm32f4xx.h"

void LED_Delay( unsigned int count)
{
	for(; count !=0; count--);
}

int main(void)
{
		/* ��GPIOH�˿ڵ�ʱ�� */
	RCC_AHB1ENR |= 1<<7;
	
  /* PH10����Ϊ��� */	
	GPIOH_MODER = (1<<(2*10));	
	
	while(1)
 {
	 GPIOH_ODR |= (1<<10);
	 LED_Delay(0xEFFFF);
	 
	/* PH10����͵�ƽ */
	GPIOH_ODR &= ~(1<<10);
	LED_Delay(0xEFFFF);	 
 }
}

/* HSI = 16M */

/* ����Ϊ�գ�Ŀ����Ϊ��ƭ�������������� */
void SystemInit(void)
{
	
}



