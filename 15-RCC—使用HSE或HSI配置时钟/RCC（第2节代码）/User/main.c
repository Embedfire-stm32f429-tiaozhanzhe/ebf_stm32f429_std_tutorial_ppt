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

