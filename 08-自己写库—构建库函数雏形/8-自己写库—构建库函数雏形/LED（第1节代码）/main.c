/**
  * 新建工程模版—寄存器版本
	*/
	
#include "stm32f4xx.h"

/* peripheral */
#define PERIPH_BASE            ((unsigned int)0x40000000)
#define AHB1PERIPH_BASE        (PERIPH_BASE+0x00020000)
#define GPIOH_BASE             (AHB1PERIPH_BASE+0x00001C00)


#define GPIOH_MODER            *(unsigned int *)(GPIOH_BASE+0X00)
#define GPIOH_ODR              *(unsigned int *)(GPIOH_BASE+0X14)

#define RCC_BASE              (AHB1PERIPH_BASE+0x00003800)
#define RCC_AHB1ENR            *(unsigned int *)(RCC_BASE+0X30)


int main(void)
{
	/* 使能GPIOH端口的时钟 */
	RCC_AHB1ENR |= (1<<7);
	
  /* PH10配置为输出 */
	GPIOH_MODER &= ~(3<<2*10);
	GPIOH_MODER |= (1<<2*10);
	
	/* PH10输出低电平 */
	GPIOH_ODR &= ~(1<<10);

	/* PH10输出低电平 */
	//GPIOH_ODR |= (1<<10); 	
	
	while(1);
}

/* 函数为空，目的是为了骗过编译器不报错 */
void SystemInit(void)
{
	
}



