/**
  * �Լ�д��-�����⺯������
	*/
	
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

#if 1
/* ʹ�üĴ����ṹ��ָ��ķ�ʽ������GPIO */
int main(void)
{
	/* ʹ��GPIOH�˿ڵ�ʱ�� */
	RCC_AHB1ENR |= (1<<7);
/*=========================PH10===============================*/
//	/* ����Ϊ���� */
//  GPIOH->PUPDR &= ~(3<<2*10);
//	GPIOH->PUPDR |= (1<<2*10);
	
  /* PH10����Ϊ��� */
	GPIOH->MODER &= ~(3<<2*10);
	GPIOH->MODER |= (1<<2*10);
	
	/* ����PH10Ϊ������� */
	GPIOH->OTYPER &= ~(1<<10);
	
  /* PH10�ٶ�Ϊ50M */
	GPIOH->OSPEEDR &= ~(3<<2*10);
	GPIOH->OSPEEDR |= (2<<2*10);
	
/*=========================PH11===============================*/
//  /* PH10����Ϊ��� */
//	GPIOH->MODER &= ~(3<<2*11);
//	GPIOH->MODER |= (1<<2*11);
//	
//	/* ����PH10Ϊ������� */
//	GPIOH->OTYPER &= ~(1<<11);
//  
//  /* PH10�ٶ�Ϊ50M */
//	GPIOH->OSPEEDR &= ~(3<<2*11);
//	GPIOH->OSPEEDR |= (2<<2*11);

	
	/* PH10����͵�ƽ */
	//GPIOH->ODR &= ~(1<<10);	
	//GPIOH->BSRRH |= (1<<10);
	
		/* PH11����͵�ƽ */
	//GPIOH->ODR &= ~(1<<11);	
	//GPIOH->BSRRH |= (1<<11);
	
	/* PH12����͵�ƽ */
	//GPIOH->ODR &= ~(1<<12);	
	//GPIOH->BSRRH |= (1<<12);

	/* PH10����ߵ�ƽ */
	//GPIOH_ODR |= (1<<10);
  //GPIOH->BSRRL |= (1<<10);

  GPIO_SetBits( GPIOH,10 );
	GPIO_ResetBits( GPIOH,10 );
	
	while(1);
}

#else 
int main(void)
{
	/* ʹ��GPIOH�˿ڵ�ʱ�� */
	RCC_AHB1ENR |= (1<<7);
	
  /* PH10����Ϊ��� */
	GPIOH_MODER &= ~(3<<2*10);
	GPIOH_MODER |= (1<<2*10);
	
	/* ����PH10Ϊ������� */
	GPIOH_OTYPER &= ~(1<<10);
  
  /* PH10����Ϊ��� */
	GPIOH_OSPEEDR &= ~(3<<2*10);
	GPIOH_OSPEEDR |= (2<<2*10);
	
	/* PH10����͵�ƽ */
	GPIOH_ODR &= ~(1<<10);

	/* PH10����͵�ƽ */
	//GPIOH_ODR |= (1<<10); 	
	
	while(1);
}

#endif


/* ����Ϊ�գ�Ŀ����Ϊ��ƭ�������������� */
void SystemInit(void)
{
	
}

