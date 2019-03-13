/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   使用外部中断EXTI检测按键，控制彩灯。
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./key/bsp_exti.h"

void Delay(__IO u32 nCount); 


//1.配置EXTI16中断源
//2.配置PVD电压阈值
//3.编写中断服务函数

void PVD_Config(void)
{
  
  EXTI_InitTypeDef EXTI_InitStructure;
  
  NVIC_InitTypeDef NVIC_InitStructure;


  	/* 连接 EXTI 中断源 到key1引脚 */
  SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,KEY1_INT_EXTI_PINSOURCE);

  /* 选择 EXTI 中断源 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line16;
  /* 中断模式 */
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  /* 下降沿触发 */
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
  /* 使能中断/事件线 */
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
    
  /* 配置NVIC为优先级组1 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置中断源：按键1 */
  NVIC_InitStructure.NVIC_IRQChannel = PVD_IRQn;
  /* 配置抢占优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 配置子优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断通道 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  
  PWR_PVDLevelConfig (PWR_PVDLevel_5 );//电压低于2.8V引起PVD中断
  PWR_PVDCmd (ENABLE);
  
  

}


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();
  	  
  LED_GREEN;
  
  //配置PVD，电压低于2.8V进入中断，亮红灯，进行紧急处理
  PVD_Config();
  
	while(1)                            
	{
	}
}

//把PVD阈值配置成其它级别，并尝试降低输入电压至阈值，观察实验现象

/*********************************************END OF FILE**********************/

