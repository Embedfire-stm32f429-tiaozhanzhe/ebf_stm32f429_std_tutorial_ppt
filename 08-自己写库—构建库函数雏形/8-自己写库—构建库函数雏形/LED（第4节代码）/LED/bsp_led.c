#include "bsp_led.h"



void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_Init_struct;
	
	GPIO_Init_struct.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_Init_struct.GPIO_Speed = GPIO_Speed_50MHZ;
	GPIO_Init_struct.GPIO_PuPd  = GPIO_PuPd_UP;
	
	GPIO_Init_struct.GPIO_Pin = LED_R_GPIO_PIN;	
	GPIO_Init( LED_R_GPIO_PORT,&GPIO_Init_struct );
	GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	
	GPIO_Init_struct.GPIO_Pin = LED_G_GPIO_PIN;	
	GPIO_Init( LED_G_GPIO_PORT,&GPIO_Init_struct );
	GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
	
	GPIO_Init_struct.GPIO_Pin = LED_B_GPIO_PIN;	
	GPIO_Init( LED_B_GPIO_PORT,&GPIO_Init_struct );
	GPIO_SetBits(LED_B_GPIO_PORT,LED_B_GPIO_PIN);
}


