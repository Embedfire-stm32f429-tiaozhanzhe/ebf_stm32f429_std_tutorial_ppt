#include "bsp_rccclkconfig.h"

#if 0
static void SetSysClock(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

/*-------------------------1-使能HSE，并等待HSE稳定----------------------------------------*/  
  /* 使能 HSE */
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待HSE启动完成，如果超时则跳出 */
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

  /* HSE启动成功 */
	if (HSEStatus == (uint32_t)0x01)
  {
/*----------------------------------------------------------------------------------------*/
    /* 选择电压调节器输出为模式1 */
		/* 使能电源接口时钟 */
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;
/*----------------------------2-配置 AHB APB2 APB1 总线的预分频因子-----------------------*/
    /* HCLK = SYSCLK / 1*/
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;    
    /* PCLK2 = HCLK / 2*/
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;    
    /* PCLK1 = HCLK / 4*/
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

/*----------------------------3-配置 PLL的各种分频因子，并使能PLL-----------------------*/  
    /* 配置 主 PLL */
    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);
    
    
    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;
    /* 等待PLL启动稳定 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }   

/*----------------------------------------------------------------------------------------*/
    /* 打开OVER-Drive模式，为的是达到更高的频率 */
    PWR->CR |= PWR_CR_ODEN;
    while((PWR->CSR & PWR_CSR_ODRDY) == 0)
    {
    }
    PWR->CR |= PWR_CR_ODSWEN;
    while((PWR->CSR & PWR_CSR_ODSWRDY) == 0)
    {
    }      
    /* 配置 Flash 预取指, 指令缓存, 数据缓存 和等待周期 */
    FLASH->ACR = FLASH_ACR_PRFTEN |
              	 FLASH_ACR_ICEN   |
		             FLASH_ACR_DCEN   |
		             FLASH_ACR_LATENCY_5WS;
		
/*----------------------------4-选择系统时钟来源-----------------------------------------*/

    /* 选择主锁相环时钟作为系统时钟 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* 等待PLLCLH切换称系统时钟 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
    {
    }
  }
  else
  { /* HSE启动失败后，用户纠错的代码 */
  } 
}

#endif

void HSE_SetSysCLK()
{
	
}

