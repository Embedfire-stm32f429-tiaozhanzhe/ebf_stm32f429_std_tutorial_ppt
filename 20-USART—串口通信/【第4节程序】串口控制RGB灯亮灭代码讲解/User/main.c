/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ƶ����ˮ��
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
#include "bsp_debug_usart.h"

static void Show_Message(void);

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	char ch;
	LED_GPIO_Config();
	Debug_USART_Config();
	//Usart_SendByte( DEBUG_USART, 'A');
	//Usart_SendHalfWord( DEBUG_USART, 65535);
	
	//Usart_SendString( DEBUG_USART, "Ұ��STM32F429����ͨ������");
	
//	printf("\r\n ����ͨ��printf�������� \r\n");
//	
//	ch = getchar();
//	printf("\r\n %c \r\n",ch);
	
	Show_Message();
while(1)
	{	
    /* ��ȡ�ַ�ָ�� */
    ch=getchar();
    printf("���յ��ַ���%c\n",ch);
    
    /* �����ַ�ָ�����RGB�ʵ���ɫ */
    switch(ch)
    {
      case '1':
        LED_RED;
      break;
      case '2':
        LED_GREEN;
      break;
      case '3':
        LED_BLUE;
      break;
      case '4':
        LED_YELLOW;
      break;
      case '5':
        LED_PURPLE;
      break;
      case '6':
        LED_CYAN;
      break;
      case '7':
        LED_WHITE;
      break;
      case '8':
        LED_RGBOFF;
      break;
      default:
        /* �������ָ��ָ���ַ�����ӡ��ʾ��Ϣ */
        Show_Message();
        break;      
    }   
	}
}


static void Show_Message(void)
{
  printf("\r\n   ����һ��ͨ������ͨ��ָ�����RGB�ʵ�ʵ�� \n");
  printf("ʹ��  USART1  ����Ϊ��%d 8-N-1 \n",DEBUG_USART_BAUDRATE);
  printf("������ӵ�ָ������RGB�ʵ���ɫ��ָ���Ӧ���£�\n");
  printf("   ָ��   ------ �ʵ���ɫ \n");
  printf("     1    ------    �� \n");
  printf("     2    ------    �� \n");
  printf("     3    ------    �� \n");
  printf("     4    ------    �� \n");
  printf("     5    ------    �� \n");
  printf("     6    ------    �� \n");
  printf("     7    ------    �� \n");
  printf("     8    ------    �� \n");  
}

// ��ҵ

// �ô���2ʵ������������


/*********************************************END OF FILE**********************/

