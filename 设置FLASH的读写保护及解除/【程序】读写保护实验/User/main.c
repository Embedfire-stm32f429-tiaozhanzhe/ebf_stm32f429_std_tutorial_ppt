/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   演示读写保护的设置与解除
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

//设置读写保护（配置到级别1）
//1.解锁选项字节
//2.配置选项字节寄存器的RDP位
//3.调用函数使得寄存器配置被拷贝到选项字节的FLASH
//4.上锁

//解除读写保护（恢复到级别0）
//1.解锁选项字节
//2.配置选项字节寄存器的RDP位
//3.调用函数使得寄存器配置被拷贝到选项字节的FLASH
//4.上锁


//作业：
//尝试给芯片设置PCROP保护，保护某个扇区。
//然后尝试使芯片恢复到默认的选项字节配置。
//恢复默认值的时候尝试一下，直接从级别0恢复。


void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();	 
 
  
  //配置到级别1的过程
  FLASH_OB_Unlock();
  
  FLASH_OB_RDPConfig(OB_RDP_Level_1);
  
  FLASH_OB_Launch();
  
  FLASH_OB_Lock();
  
    
  LED_BLUE;
  
  
  //恢复到级别0的过程
  FLASH_OB_Unlock();
  
  FLASH_OB_RDPConfig(OB_RDP_Level_0);
  
  FLASH_OB_Launch();
  
  FLASH_OB_Lock();
  
  
  LED_GREEN;

	/* 方法2，使用固件库控制IO */
	while (1)
	{
	
	}
}


void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

