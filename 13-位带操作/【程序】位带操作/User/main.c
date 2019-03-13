#include "stm32f4xx.h"
#include "bsp_led.h"

#define GPIOA_ODR_ADDR           (GPIOA_BASE+0X14)
#define GPIOB_ODR_ADDR           (GPIOB_BASE+0X14)
#define GPIOC_ODR_ADDR           (GPIOC_BASE+0X14)
#define GPIOD_ODR_ADDR           (GPIOD_BASE+0X14)
#define GPIOE_ODR_ADDR           (GPIOE_BASE+0X14)
#define GPIOF_ODR_ADDR           (GPIOF_BASE+0X14)

#define GPIOH_ODR_ADDR           (GPIOH_BASE+0X14)

// ���λ���������ĵ�ַ
#define BITBAND(addr,bitnum)     ((addr & 0xF0000000)+0x02000000+((addr &0x000FFFFF)<<5)+(bitnum<<2))
// ��һ��������ǿ������ת����һ��ָ�룬Ȼ���ָ�� * ����
#define MEM_ADDR(addr)           (*(volatile unsigned long *)(addr))
#define BIT_ACTION(addr,bitnum)  MEM_ADDR(BITBAND(addr,bitnum)) 


#define PHout(n)  BIT_ACTION(GPIOH_ODR_ADDR,n)
#define PAout(n)  BIT_ACTION(GPIOA_ODR_ADDR,n)

int main(void)
{
	LED_GPIO_Config();
	
	//MEM_ADDR(BITBAND(GPIOH_ODR_ADDR,10)) = 0;
	//BIT_ACTION(GPIOH_ODR_ADDR,10) = 0;
	
	PHout(10) = 0;
	//PAout(10) = 1;
	
	
	//GPIO_ResetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	//GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
	
	while(1);
}

void zhongduanhanshu(void)
{
	// �������д����жϷ�����
}

// 1- ���ʵ������GPIO�˿ڵ�ODR�Ĵ�����λ����

// 2- ���ʵ������GPIO�˿ڵ�IDR�Ĵ�����λ����

// 3- ����ʵ��GPIO���롪������ⲿ�ֵĴ��룺��ȡIO��ƽ����һ���ִ��룬��λ����������ʽ����

// uint16_t temp; temp = PAint(0);

// 4- �� �̵� ������ Ҳ����









