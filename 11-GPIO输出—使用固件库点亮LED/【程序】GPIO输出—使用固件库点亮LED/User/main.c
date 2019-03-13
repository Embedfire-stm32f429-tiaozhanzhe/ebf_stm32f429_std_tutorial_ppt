#include "stm32f4xx.h"
#include "bsp_led.h"
// bsp : board support package

int main(void)
{
	LED_GPIO_Config();
	
	GPIO_ResetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	//GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	
	while(1);
}

// 课后作业

// 1- 让红灯以大概500ms的时间闪烁

// 2- 把绿灯跟蓝灯也点亮，实现一个流水灯