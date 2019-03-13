#include "bsp_exti.h"

static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStruct.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);	
}


void EXTI_Key_Config(void)
{
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
	
		EXTI_InitTypeDef  EXTI_InitStruct;

		/*开启LED相关的GPIO外设时钟*/
		RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOA, ENABLE);
		/*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin =  KEY1_GPIO_PIN;	
		/*设置引脚模式为输入模式*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   
    /*设置引脚为浮空模式*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		/*调用库函数，使用上面配置的GPIO_InitStructure初始化GPIO*/
		GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);

	
		RCC_APB2PeriphClockCmd ( RCC_APB2Periph_SYSCFG, ENABLE);
		
		SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE);	
	
		EXTI_InitStruct.EXTI_Line = KEY1_INT_EXTI_LINE;
		EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStruct);
		
		EXTI_NVIC_Config();
}



