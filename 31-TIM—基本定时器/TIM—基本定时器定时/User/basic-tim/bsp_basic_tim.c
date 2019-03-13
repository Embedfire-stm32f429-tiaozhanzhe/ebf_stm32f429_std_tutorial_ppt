#include "bsp_basic_tim.h"


static void TIMx_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIMx_IRQn; 	
		// ������ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // ���������ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void BASIC_TIMx_Mode_Config(void)
{
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	  RCC_APB1PeriphClockCmd(BASIC_TIMx_CLK, ENABLE);

	  /* �ۼ� TIM_Period�������һ�����»����ж�*/		
  //����ʱ����0������4999����Ϊ5000�Σ�Ϊһ����ʱ����
  TIM_TimeBaseStructure.TIM_Period = 5000-1;       
	
	//��ʱ��ʱ��ԴTIMxCLK = 2 * PCLK1  
  //				PCLK1 = HCLK / 4 
  //				=> TIMxCLK=HCLK/2=SystemCoreClock/2=90MHz
	// �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(TIM_Prescaler+1)=10000Hz
  TIM_TimeBaseStructure.TIM_Prescaler = 9000-1;	
	
	// ��ʼ����ʱ��TIMx, x[2,3,4,5]
	TIM_TimeBaseInit(BASIC_TIMx, &TIM_TimeBaseStructure);
	
	
	// �����ʱ�������жϱ�־λ
	TIM_ClearFlag(BASIC_TIMx, TIM_FLAG_Update);
	
	// ������ʱ�������ж�
	TIM_ITConfig(BASIC_TIMx,TIM_IT_Update,ENABLE);
	
	// ʹ�ܶ�ʱ��
	TIM_Cmd(BASIC_TIMx, ENABLE);	
}

void BASIC_TIMx_Config(void)
{
	TIMx_NVIC_Configuration();
	BASIC_TIMx_Mode_Config();
}


