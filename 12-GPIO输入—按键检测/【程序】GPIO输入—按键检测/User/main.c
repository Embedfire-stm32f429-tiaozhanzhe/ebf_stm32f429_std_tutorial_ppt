#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"

int main(void)
{
	LED_GPIO_Config();
	
	Key_GPIO_Config();
	
	while(1)
	{
		if ( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON)
		{
			LED_R_TOGGLE;
		}	
		
		if ( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON)
		{
			LED_R_TOGGLE;
			//LED_G_TOGGLE;
		}	
		
	}
}

// 作业

// 1- K1 按下的时候，LED_R 反转

// 2- K2按下的时候，LED_G 反转

