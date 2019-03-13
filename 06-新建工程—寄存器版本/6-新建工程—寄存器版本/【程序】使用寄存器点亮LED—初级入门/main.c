/**
  * 新建工程模版—寄存器版本
	*/
	
#include "stm32f4xx.h"

void LED_Delay( unsigned int count)
{
	for(; count !=0; count--);
}

int main(void)
{
		/* 打开GPIOH端口的时钟 */
	RCC_AHB1ENR |= 1<<7;
	
  /* PH10配置为输出 */	
	GPIOH_MODER = (1<<(2*10));	
	
	while(1)
 {
	 GPIOH_ODR |= (1<<10);
	 LED_Delay(0xEFFFF);
	 
	/* PH10输出低电平 */
	GPIOH_ODR &= ~(1<<10);
	LED_Delay(0xEFFFF);	 
 }
}

/* HSI = 16M */

/* 函数为空，目的是为了骗过编译器不报错 */
void SystemInit(void)
{
	
}



