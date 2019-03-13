/**
  * �½�����ģ�桪�Ĵ����汾
	*/
	
#include "stm32f4xx.h"

/* peripheral */
#define PERIPH_BASE            ((unsigned int)0x40000000)
#define AHB1PERIPH_BASE        (PERIPH_BASE+0x00020000)
#define GPIOH_BASE             (AHB1PERIPH_BASE+0x00001C00)
#define GPIOA_BASE             (AHB1PERIPH_BASE+0x00000000)

#define GPIOH_MODER            *(unsigned int *)(GPIOH_BASE+0X00)
#define GPIOH_OTYPER           *(unsigned int *)(GPIOH_BASE+0X04)
#define GPIOH_OSPEEDR          *(unsigned int *)(GPIOH_BASE+0X08)
#define GPIOH_PUPDR            *(unsigned int *)(GPIOH_BASE+0X0C)
#define GPIOH_IDR              *(unsigned int *)(GPIOH_BASE+0X10)
#define GPIOH_ODR              *(unsigned int *)(GPIOH_BASE+0X14)
#define GPIOH_BSRR             *(unsigned int *)(GPIOH_BASE+0X18)
#define GPIOH_LCKR             *(unsigned int *)(GPIOH_BASE+0X1C)
#define GPIOH_AFRL             *(unsigned int *)(GPIOH_BASE+0X20)
#define GPIOH_AFRH             *(unsigned int *)(GPIOH_BASE+0X24)

typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;

typedef struct
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint16_t BSRRL;
	uint16_t BSRRH;
	uint32_t LCKR;
	uint32_t AFR[2];
}GPIO_TypeDef;

#define GPIOH       ((GPIO_TypeDef *)GPIOH_BASE)
#define GPIOA       ((GPIO_TypeDef *)GPIOA_BASE)


#define RCC_BASE              (AHB1PERIPH_BASE+0x00003800)
#define RCC_AHB1ENR            *(unsigned int *)(RCC_BASE+0X30)

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
  /* PH10����Ϊ��� */
	GPIOH->MODER &= ~(3<<2*11);
	GPIOH->MODER |= (1<<2*11);
	
	/* ����PH10Ϊ������� */
	GPIOH->OTYPER &= ~(1<<11);
  
  /* PH10�ٶ�Ϊ50M */
	GPIOH->OSPEEDR &= ~(3<<2*11);
	GPIOH->OSPEEDR |= (2<<2*11);

	
	/* PH10����͵�ƽ */
	//GPIOH->ODR &= ~(1<<10);	
	GPIOH->BSRRH |= (1<<10);
	
		/* PH11����͵�ƽ */
	//GPIOH->ODR &= ~(1<<11);	
	//GPIOH->BSRRH |= (1<<11);
	
	/* PH12����͵�ƽ */
	//GPIOH->ODR &= ~(1<<12);	
	//GPIOH->BSRRH |= (1<<12);

	/* PH10����ߵ�ƽ */
	//GPIOH_ODR |= (1<<10);
  //GPIOH->BSRRL |= (1<<10); 	
	
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



