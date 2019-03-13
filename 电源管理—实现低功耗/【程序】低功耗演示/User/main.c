/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ʹ���ⲿ�ж�EXTI��ⰴ�������Ʋʵơ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./key/bsp_exti.h"
#include "./usart/bsp_debug_usart.h"

void Delay(__IO u32 nCount); 
void SysClockResetFromStop(void);
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  uint8_t systemClock=0;
  
  RCC_ClocksTypeDef  rccClockFreq;
  
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
  
  Debug_USART_Config();
  	
	/* ��ʼ��EXTI�жϣ����°����ᴥ���жϣ�
  *  �����жϻ����stm32f4xx_it.c�ļ��еĺ���
	*  KEY1_IRQHandler��KEY2_IRQHandler�������жϣ���תLED�ơ�
	*/
//	EXTI_Key_Config(); 
  
  if(PWR_GetFlagStatus(PWR_FLAG_WU) ==SET)
  {
    printf("waup ���Ÿ�λ");
    PWR_ClearFlag(PWR_FLAG_WU);
  }
  else
    printf("��λ������λ");
  
  
	
	/* �ȴ��жϣ�����ʹ���жϷ�ʽ��CPU������ѯ���� */
	while(1)                            
	{
    
    LED_RED;
    
    Delay(0xFFFFFF);
    
    LED_GREEN;
    
     Delay(0xFFFFFF);
    
//    systemClock = RCC_GetSYSCLKSource();
//    RCC_GetClocksFreq(&rccClockFreq);
    
//    printf("\r\n before stop");

//    printf("\r\n systemClock =%x",systemClock);
//    
//    printf("\r\n HCLK_Frequency =%d,PCLK1_Frequency=%d,PCLK2_Frequency=%d,SYSCLK_Frequency=%d",
//                        rccClockFreq.HCLK_Frequency,
//                        rccClockFreq.PCLK1_Frequency,
//                        rccClockFreq.PCLK2_Frequency,
//                        rccClockFreq.SYSCLK_Frequency);
    PWR_WakeUpPinCmd(ENABLE);
    PWR_EnterSTANDBYMode(); 
    
//    systemClock = RCC_GetSYSCLKSource();
//    RCC_GetClocksFreq(&rccClockFreq);
    
    
//    SysClockResetFromStop();
    
//    printf("\r\n \r\n After stop");

//    printf("\r\n systemClock =%x",systemClock);
//    
//    printf("\r\n HCLK_Frequency =%d,PCLK1_Frequency=%d,PCLK2_Frequency=%d,SYSCLK_Frequency=%d",
//                        rccClockFreq.HCLK_Frequency,
//                        rccClockFreq.PCLK1_Frequency,
//                        rccClockFreq.PCLK2_Frequency,
//                        rccClockFreq.SYSCLK_Frequency);
    
    

    
    LED_BLUE;
    
    Delay(0xFFFFFF);
    
	}
}



void Delay(__IO u32 nCount)
{
  for(;nCount>0;nCount--);

}




void SysClockResetFromStop(void)
{
  RCC_HSEConfig (RCC_HSE_ON);
  
  while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) != RESET)
  {}
    
   RCC_PLLCmd(ENABLE);
    
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) !=RESET)
   {}
     
  RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);   
     
     while(RCC_GetSYSCLKSource() != 0x08)
     {}
     
    
  
  
}


//1.��оƬ����˯��ģʽ����ʹ��systick��ʱ�����ѡ�
//2.����ʹ��systick�ܷ���ֹͣģʽ��оƬ��
/*********************************************END OF FILE**********************/

