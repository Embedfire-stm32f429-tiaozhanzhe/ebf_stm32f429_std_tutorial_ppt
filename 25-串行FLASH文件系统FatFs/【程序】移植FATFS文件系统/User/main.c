/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   文件系统移植例程
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"
#include "./flash/bsp_spi_flash.h" 
#include "ff.h"  

// 函数原型声明
void Delay(__IO uint32_t nCount);


FATFS flash_fs;
FIL testfp;

uint8_t w_buff[] = "测试fatfs文件系统";
uint8_t r_buff[1024];

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{ 	
	FRESULT res;
  UINT bw;
  
  UINT br;
  
  LED_GPIO_Config();
	LED_BLUE;
	
	/* 配置串口1为：115200 8-N-1 */
	Debug_USART_Config();
  
	printf("\r\n这是一个文件系统移植实验 \r\n");
  
  res = f_mount(&flash_fs,"1:",1); 
  
  printf("\r\nf_mount res =%d\r\n ",res);
  
  #if 0
  //格式化操作，会擦除原文件系统的内容，尽量不要格式化
  res = f_mkfs("1:",0,0);
  printf("\r\nf_f_mkfs res =%d\r\n ",res);
  
  //格式化操作完成
  
  res = f_mount(NULL,"1:",1); 
  res = f_mount(&flash_fs,"1:",1); 
  #endif
  
  res = f_open(&testfp,"1:/中文支持936.txt",FA_CREATE_ALWAYS|FA_WRITE|FA_READ);
  
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

//移植文件系统的步骤
//1.修改diskio.c驱动接口
//2.修改ffconf.h文件的配置
//3.编写测试
//4.中文支持

//作业：自己亲自尝试移植文件系统

/*********************************************END OF FILE**********************/

