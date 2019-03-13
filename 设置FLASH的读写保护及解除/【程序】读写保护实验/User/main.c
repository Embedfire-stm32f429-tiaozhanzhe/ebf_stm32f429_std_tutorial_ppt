/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��ʾ��д��������������
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

//���ö�д���������õ�����1��
//1.����ѡ���ֽ�
//2.����ѡ���ֽڼĴ�����RDPλ
//3.���ú���ʹ�üĴ������ñ�������ѡ���ֽڵ�FLASH
//4.����

//�����д�������ָ�������0��
//1.����ѡ���ֽ�
//2.����ѡ���ֽڼĴ�����RDPλ
//3.���ú���ʹ�üĴ������ñ�������ѡ���ֽڵ�FLASH
//4.����


//��ҵ��
//���Ը�оƬ����PCROP����������ĳ��������
//Ȼ����ʹоƬ�ָ���Ĭ�ϵ�ѡ���ֽ����á�
//�ָ�Ĭ��ֵ��ʱ����һ�£�ֱ�ӴӼ���0�ָ���


void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
 
  
  //���õ�����1�Ĺ���
  FLASH_OB_Unlock();
  
  FLASH_OB_RDPConfig(OB_RDP_Level_1);
  
  FLASH_OB_Launch();
  
  FLASH_OB_Lock();
  
    
  LED_BLUE;
  
  
  //�ָ�������0�Ĺ���
  FLASH_OB_Unlock();
  
  FLASH_OB_RDPConfig(OB_RDP_Level_0);
  
  FLASH_OB_Launch();
  
  FLASH_OB_Lock();
  
  
  LED_GREEN;

	/* ����2��ʹ�ù̼������IO */
	while (1)
	{
	
	}
}


void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

