/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   �ļ�ϵͳ��ֲ����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./flash/bsp_spi_flash.h" 
#include "ff.h"  

// ����ԭ������
void Delay(__IO uint32_t nCount);


FATFS flash_fs;
FIL testfp;

uint8_t w_buff[] = "����fatfs�ļ�ϵͳ";
uint8_t r_buff[1024];

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{ 	
	FRESULT res;
  UINT bw;
  
  UINT br;
  
  LED_GPIO_Config();
	LED_BLUE;
	
	/* ���ô���1Ϊ��115200 8-N-1 */
	Debug_USART_Config();
  
	printf("\r\n����һ���ļ�ϵͳ��ֲʵ�� \r\n");
  
  res = f_mount(&flash_fs,"1:",1); 
  
  printf("\r\nf_mount res =%d\r\n ",res);
  
  #if 0
  //��ʽ�������������ԭ�ļ�ϵͳ�����ݣ�������Ҫ��ʽ��
  res = f_mkfs("1:",0,0);
  printf("\r\nf_f_mkfs res =%d\r\n ",res);
  
  //��ʽ���������
  
  res = f_mount(NULL,"1:",1); 
  res = f_mount(&flash_fs,"1:",1); 
  #endif
  
  res = f_open(&testfp,"1:/����֧��936.txt",FA_CREATE_ALWAYS|FA_WRITE|FA_READ);
  
  printf("\r\nf_open res =%d \r\n",res);
  
  
  printf("\r\nflash_fs size =%d,testfp size= %d\r\n",sizeof(flash_fs),sizeof(testfp));
  
  res = f_write(&testfp,&w_buff,sizeof(w_buff),&bw);
  
  printf("\r\nf_write res =%d\r\n ",res);

  res = f_lseek(&testfp,0);
  
  printf("\r\nf_lseek res =%d\r\n ",res);


  res = f_read(&testfp,r_buff,1024,&br);
  
  printf("\r\nf_read res =%d\r\n ",res);
  
  printf("\r\nr_buff =%s\r\n ",r_buff);
  
  printf("\r\nbr =%d\r\n ",br);
  
  f_close(&testfp);
	
	while(1);  
}


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

//��ֲ�ļ�ϵͳ�Ĳ���
//1.�޸�diskio.c�����ӿ�
//2.�޸�ffconf.h�ļ�������
//3.��д����
//4.����֧��

//��ҵ���Լ����Գ�����ֲ�ļ�ϵͳ

/*********************************************END OF FILE**********************/

