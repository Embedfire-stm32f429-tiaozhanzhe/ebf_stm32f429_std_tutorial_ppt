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

void HSE_SetSysCLK()
{
	
}

