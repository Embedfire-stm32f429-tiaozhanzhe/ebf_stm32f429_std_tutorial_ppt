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


// m : 2~63
// n :192~432
// p ：2、4、6、8
// q ：2~15
// SYSCLK = (HSE/m) * n /p = 25/25 * 432 / 2 = 216M 
// HSE_SetSysClk(25,432,2,7)
void HSE_SetSysClk(uint32_t m,uint32_t n,uint32_t p,uint32_t q)
{
	__IO uint32_t HSEStartUpStatus = 0;
	
	/* 使能HSE 并等待HSE稳定*/
	RCC_HSEConfig(RCC_HSE_ON);	
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if( HSEStartUpStatus == SUCCESS )
  {
			/* 选择电压调节器输出为模式1 */
			/* 使能电源接口时钟 */
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


			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
			while ( ( RCC_GetSYSCLKSource() ) != 0X08 )
			{
			}	  
  }
  else{ /* HSE启动识别，用户在这里添加纠错代码 */ }
}





// MCO1 PA8 GPIO 初始化
void MCO1_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  // MCO1 GPIO 配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

// MCO2 PC9 GPIO 初始化
void MCO2_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  // MCO2 GPIO 配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}


















