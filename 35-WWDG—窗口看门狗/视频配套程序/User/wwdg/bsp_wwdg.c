#include "bsp_wwdg.h"


//���ڼ�¼���Ź� �ݼ���������ֵ������ι������ֱ��ʹ��
static uint8_t wwdg_cnt ;

// WWDG �ж����ȼ���ʼ��
static void WWDG_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure; 
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
  NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


/* WWDG ���ú���
 * tr ���ݼ���ʱ����ֵ�� ȡֵ��ΧΪ��0x7f~0x40��������Χ��ֱ�Ӹ�λ
 * wr ������ֵ��ȡֵ��ΧΪ��0x7f~0x40
 * prv��Ԥ��Ƶ��ֵ��ȡֵ������
 *      @arg WWDG_Prescaler_1: WWDG counter clock = (PCLK1(45MHz)/4096)/1  Լ10968Hz 91us
 *      @arg WWDG_Prescaler_2: WWDG counter clock = (PCLK1(45MHz)/4096)/2	 Լ5484Hz	182us
 *      @arg WWDG_Prescaler_4: WWDG counter clock = (PCLK1(45MHz)/4096)/4	 Լ2742Hz	364us
 *      @arg WWDG_Prescaler_8: WWDG counter clock = (PCLK1(45MHz)/4096)/8  Լ1371Hz	728us
 *      
 *			����tr = 127(0x7f��tr�����ֵ)  wr = 80��0x50, 0x40Ϊ��Сwr��Сֵ��  prv =  WWDG_Prescaler_8
 *			~728 * (127-80) = 34.2ms < ˢ�´��� < ~728 * 64 = 46.6ms
 *			Ҳ����˵����WWDG_Config�������������ã�����֮���34.2msǰι����ϵͳ�Ḵλ����46.6ms��û��ι����ϵͳҲ�Ḵλ��
 *			��Ҫ��ˢ�´��ڵ�ʱ����ι����ϵͳ�Ų��Ḵλ��	
*/
void WWDG_Config(uint8_t tr, uint8_t wr, uint32_t prv)
{	
	
	wwdg_cnt = tr;//����CNT���ã�����ι������
	
	// ���� WWDG ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	// ����Ԥ��Ƶ����ֵ
	WWDG_SetPrescaler( prv );
	
	// �����ϴ���ֵ
	WWDG_SetWindowValue( wr );
	
	// ���ü�������ֵ��ʹ��WWDG
	WWDG_Enable(tr);	
	
	// �����ǰ�����жϱ�־λ
	WWDG_ClearFlag();	
	// ����WWDG�ж����ȼ�
	WWDG_NVIC_Config();	
	// ��WWDG �ж�
	WWDG_EnableIT();
}


// ι��
void WWDG_Feed(void)
{
	// ι����ˢ�µݼ���������ֵ�����ó����WDG_CNT=0X7F
	WWDG_SetCounter( wwdg_cnt );
}

