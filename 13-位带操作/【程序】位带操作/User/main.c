#include "stm32f4xx.h"
#include "bsp_led.h"

#define GPIOA_ODR_ADDR           (GPIOA_BASE+0X14)
#define GPIOB_ODR_ADDR           (GPIOB_BASE+0X14)
#define GPIOC_ODR_ADDR           (GPIOC_BASE+0X14)
#define GPIOD_ODR_ADDR           (GPIOD_BASE+0X14)
#define GPIOE_ODR_ADDR           (GPIOE_BASE+0X14)
#define GPIOF_ODR_ADDR           (GPIOF_BASE+0X14)

#define GPIOH_ODR_ADDR           (GPIOH_BASE+0X14)

// 求出位带别名区的地址
#define BITBAND(addr,bitnum)     ((addr & 0xF0000000)+0x02000000+((addr &0x000FFFFF)<<5)+(bitnum<<2))
// 把一个立即数强制类型转换成一个指针，然后对指针 * 操作
#define MEM_ADDR(addr)           (*(volatile unsigned long *)(addr))
#define BIT_ACTION(addr,bitnum)  MEM_ADDR(BITBAND(addr,bitnum)) 


#define PHout(n)  BIT_ACTION(GPIOH_ODR_ADDR,n)
#define PAout(n)  BIT_ACTION(GPIOA_ODR_ADDR,n)

int main(void)
{
	LED_GPIO_Config();
	
	//MEM_ADDR(BITBAND(GPIOH_ODR_ADDR,10)) = 0;
	//BIT_ACTION(GPIOH_ODR_ADDR,10) = 0;
	
	PHout(10) = 0;
	//PAout(10) = 1;
	
	
	//GPIO_ResetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	//GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	
	while(1);
}

void zhongduanhanshu(void)
{
	// 这里面就写你的中断服务函数
}

// 1- 如何实现其他GPIO端口的ODR寄存器的位操作

// 2- 如果实现其他GPIO端口的IDR寄存器的位操作

// 3- 重新实现GPIO输入—按键检测部分的代码：读取IO电平的那一部分代码，用位带操作的形式操作

// uint16_t temp; temp = PAint(0);

// 4- 把 绿灯 跟蓝灯 也点亮









