/**
  * 自己写库-构建库函数雏形
	*/
	
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "bsp_led.h"


int main(void)
{
	/* 使能GPIOH端口的时钟 */
	RCC_AHB1ENR |= (1<<7);
/*=========================PH10===============================*/	
	#if 0
	// 1-确定引脚号
	
  // 2-确定是输入还是输出
	/* PH10配置为输出 */
	GPIOH->MODER &= ~(3<<2*10);
	GPIOH->MODER |= (1<<2*10);
	
	// 3-配置是上拉还是下拉	
	/* 配置为上拉 */
  GPIOH->PUPDR &= ~(3<<2*10);
	GPIOH->PUPDR |= (1<<2*10);
	
	// 4-确定是推挽还是开漏输出
	/* 设置PH10为推挽输出 */
	GPIOH->OTYPER &= ~(1<<10);
	
  // 5-配置输出的速度
	/* PH10速度为50M */
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


/* 函数为空，目的是为了骗过编译器不报错 */
void SystemInit(void)
{
	
}

