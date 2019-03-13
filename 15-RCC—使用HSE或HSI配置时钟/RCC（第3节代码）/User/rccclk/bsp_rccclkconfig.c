#include "bsp_rccclkconfig.h"

#if 0
static void SetSysClock(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

/*-------------------------1-ʹ��HSE�����ȴ�HSE�ȶ�----------------------------------------*/  
  /* ʹ�� HSE */
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* �ȴ�HSE������ɣ������ʱ������ */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }

  /* HSE�����ɹ� */
	if (HSEStatus == (uint32_t)0x01)
  {
/*----------------------------------------------------------------------------------------*/
    /* ѡ���ѹ���������Ϊģʽ1 */
		/* ʹ�ܵ�Դ�ӿ�ʱ�� */
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;
/*----------------------------2-���� AHB APB2 APB1 ���ߵ�Ԥ��Ƶ����-----------------------*/
    /* HCLK = SYSCLK / 1*/
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;    
    /* PCLK2 = HCLK / 2*/
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;    
    /* PCLK1 = HCLK / 4*/
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

/*----------------------------3-���� PLL�ĸ��ַ�Ƶ���ӣ���ʹ��PLL-----------------------*/  
    /* ���� �� PLL */
    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);
    
    
    /* ʹ�� PLL */
    RCC->CR |= RCC_CR_PLLON;
    /* �ȴ�PLL�����ȶ� */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }   

/*----------------------------------------------------------------------------------------*/
    /* ��OVER-Driveģʽ��Ϊ���Ǵﵽ���ߵ�Ƶ�� */
    PWR->CR |= PWR_CR_ODEN;
    while((PWR->CSR & PWR_CSR_ODRDY) == 0)
    {
    }
    PWR->CR |= PWR_CR_ODSWEN;
    while((PWR->CSR & PWR_CSR_ODSWRDY) == 0)
    {
    }      
    /* ���� Flash Ԥȡָ, ָ���, ���ݻ��� �͵ȴ����� */
    FLASH->ACR = FLASH_ACR_PRFTEN |
              	 FLASH_ACR_ICEN   |
		             FLASH_ACR_DCEN   |
		             FLASH_ACR_LATENCY_5WS;
		
/*----------------------------4-ѡ��ϵͳʱ����Դ-----------------------------------------*/

    /* ѡ�������໷ʱ����Ϊϵͳʱ�� */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* �ȴ�PLLCLH�л���ϵͳʱ�� */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
    {
    }
  }
  else
  { /* HSE����ʧ�ܺ��û�����Ĵ��� */
  } 
}

#endif


// m : 2~63
// n :192~432
// p ��2��4��6��8
// q ��2~15
// SYSCLK = (HSE/m) * n /p = 25/25 * 432 / 2 = 216M 
// HSE_SetSysClk(25,432,2,7)
void HSE_SetSysClk(uint32_t m,uint32_t n,uint32_t p,uint32_t q)
{
	__IO uint32_t HSEStartUpStatus = 0;
	
	/* ʹ��HSE ���ȴ�HSE�ȶ�*/
	RCC_HSEConfig(RCC_HSE_ON);	
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if( HSEStartUpStatus == SUCCESS )
  {
			/* ѡ���ѹ���������Ϊģʽ1 */
			/* ʹ�ܵ�Դ�ӿ�ʱ�� */
			RCC->APB1ENR |= RCC_APB1ENR_PWREN;
			PWR->CR |= PWR_CR_VOS;

			RCC_HCLKConfig(RCC_SYSCLK_Div1);
			RCC_PCLK2Config(RCC_HCLK_Div2);
			RCC_PCLK1Config(RCC_HCLK_Div4);

			RCC_PLLConfig(RCC_PLLSource_HSE, m, n, p, q);

			RCC_PLLCmd(ENABLE);
			while ( ( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) ) == RESET )
			{
			}
			/* ��OVER-Driveģʽ��Ϊ���Ǵﵽ���ߵ�Ƶ�� */
			PWR->CR |= PWR_CR_ODEN;
			while((PWR->CSR & PWR_CSR_ODRDY) == 0)
			{
			}
			PWR->CR |= PWR_CR_ODSWEN;
			while((PWR->CSR & PWR_CSR_ODSWRDY) == 0)
			{
			}

			/* ���� Flash Ԥȡָ, ָ���, ���ݻ��� �͵ȴ����� */
			FLASH->ACR = FLASH_ACR_PRFTEN |
			FLASH_ACR_ICEN   |
			FLASH_ACR_DCEN   |
			FLASH_ACR_LATENCY_5WS;


			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
			while ( ( RCC_GetSYSCLKSource() ) != 0X08 )
			{
			}	  
  }
  else{ /* HSE����ʶ���û���������Ӿ������ */ }
}





// MCO1 PA8 GPIO ��ʼ��
void MCO1_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  // MCO1 GPIO ����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

// MCO2 PC9 GPIO ��ʼ��
void MCO2_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  // MCO2 GPIO ����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}


















