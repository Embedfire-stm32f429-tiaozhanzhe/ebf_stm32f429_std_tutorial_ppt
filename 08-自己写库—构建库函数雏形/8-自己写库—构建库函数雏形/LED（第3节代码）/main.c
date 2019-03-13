/**
  * 自己写库-构建库函数雏形
	*/
	
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

#if 1
/* 使用寄存器结构体指针的方式来操作GPIO */
int main(void)
{
	/* 使能GPIOH端口的时钟 */
	RCC_AHB1ENR |= (1<<7);
/*=========================PH10===============================*/
//	/* 配置为上拉 */
//  GPIOH->PUPDR &= ~(3<<2*10);
//	GPIOH->PUPDR |= (1<<2*10);
	
  /* PH10配置为输出 */
	GPIOH->MODER &= ~(3<<2*10);
	GPIOH->MODER |= (1<<2*10);
	
	/* 设置PH10为推挽输出 */
	GPIOH->OTYPER &= ~(1<<10);
	
  /* PH10速度为50M */
	GPIOH->OSPEEDR &= ~(3<<2*10);
	GPIOH->OSPEEDR |= (2<<2*10);
	
/*=========================PH11===============================*/
//  /* PH10配置为输出 */
//	GPIOH->MODER &= ~(3<<2*11);
//	GPIOH->MODER |= (1<<2*11);
//	
//	/* 设置PH10为推挽输出 */
//	GPIOH->OTYPER &= ~(1<<11);
//  
//  /* PH10速度为50M */
//	GPIOH->OSPEEDR &= ~(3<<2*11);
//	GPIOH->OSPEEDR |= (2<<2*11);

	
	/* PH10输出低电平 */
	//GPIOH->ODR &= ~(1<<10);	
	//GPIOH->BSRRH |= (1<<10);
	
		/* PH11输出低电平 */
	//GPIOH->ODR &= ~(1<<11);	
	//GPIOH->BSRRH |= (1<<11);
	
	/* PH12输出低电平 */
	//GPIOH->ODR &= ~(1<<12);	
	//GPIOH->BSRRH |= (1<<12);

	/* PH10输出高电平 */
	//GPIOH_ODR |= (1<<10);
  //GPIOH->BSRRL |= (1<<10);

  GPIO_SetBits( GPIOH,10 );
	GPIO_ResetBits( GPIOH,10 );
	
	while(1);
}

#else 
int main(void)
{
	/* 使能GPIOH端口的时钟 */
	RCC_AHB1ENR |= (1<<7);
	
  /* PH10配置为输出 */
	GPIOH_MODER &= ~(3<<2*10);
	GPIOH_MODER |= (1<<2*10);
	
	/* 设置PH10为推挽输出 */
	GPIOH_OTYPER &= ~(1<<10);
  
  /* PH10配置为输出 */
	GPIOH_OSPEEDR &= ~(3<<2*10);
	GPIOH_OSPEEDR |= (2<<2*10);
	
	/* PH10输出低电平 */
	GPIOH_ODR &= ~(1<<10);

	/* PH10输出低电平 */
	//GPIOH_ODR |= (1<<10); 	
	
	while(1);
}

#endif


/* 函数为空，目的是为了骗过编译器不报错 */
void SystemInit(void)
{
	
}

