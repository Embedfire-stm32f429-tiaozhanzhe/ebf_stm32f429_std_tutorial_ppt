/**
  ******************************************************************************
  * @file    bsp_debug_usart.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDRAM����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������  
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./sdram/bsp_sdram.h"


//1.��ʼ��FMCʹ�õ�GPIO
//2.��ʼ��FMC��ʱ��ṹ��
//3.��ʼ��FMC�ĳ�ʼ���ṹ��
//4.ʹ�������ʼ��SDRAMоƬ
//5.���ж�дSDRAM����




//��ʼ��GPIO
static void SDRAM_GPIO_Config(void)
{
 
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* ʹ��SDRAM��ص�GPIOʱ�� */

                         /*��ַ�ź���*/
  RCC_AHB1PeriphClockCmd(FMC_A0_GPIO_CLK | FMC_A1_GPIO_CLK | FMC_A2_GPIO_CLK | 
                         FMC_A3_GPIO_CLK | FMC_A4_GPIO_CLK | FMC_A5_GPIO_CLK |
                         FMC_A6_GPIO_CLK | FMC_A7_GPIO_CLK | FMC_A8_GPIO_CLK |
                         FMC_A9_GPIO_CLK | FMC_A10_GPIO_CLK| FMC_A11_GPIO_CLK| 
												 FMC_BA0_GPIO_CLK| FMC_BA1_GPIO_CLK|
                         /*�����ź���*/
                         FMC_D0_GPIO_CLK | FMC_D1_GPIO_CLK | FMC_D2_GPIO_CLK | 
                         FMC_D3_GPIO_CLK | FMC_D4_GPIO_CLK | FMC_D5_GPIO_CLK |
                         FMC_D6_GPIO_CLK | FMC_D7_GPIO_CLK | FMC_D8_GPIO_CLK |
                         FMC_D9_GPIO_CLK | FMC_D10_GPIO_CLK| FMC_D11_GPIO_CLK|
                         FMC_D12_GPIO_CLK| FMC_D13_GPIO_CLK| FMC_D14_GPIO_CLK|
                         FMC_D15_GPIO_CLK|  
                         /*�����ź���*/
                         FMC_CS_GPIO_CLK  | FMC_WE_GPIO_CLK | FMC_RAS_GPIO_CLK |
                         FMC_CAS_GPIO_CLK |FMC_CLK_GPIO_CLK | FMC_CKE_GPIO_CLK |
                         FMC_UDQM_GPIO_CLK|FMC_LDQM_GPIO_CLK, ENABLE);
                         


  
  /*-- GPIO ���� -----------------------------------------------------*/

  /* ͨ�� GPIO ���� */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;       //����Ϊ���ù���
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //�������
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;   
  
  
  /*A���е�ַ�ź��� �����������*/
  GPIO_InitStructure.GPIO_Pin = FMC_A0_GPIO_PIN; 
  GPIO_Init(FMC_A0_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A0_GPIO_PORT, FMC_A0_PINSOURCE , FMC_A0_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A1_GPIO_PIN; 
  GPIO_Init(FMC_A1_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A1_GPIO_PORT, FMC_A1_PINSOURCE , FMC_A1_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A2_GPIO_PIN; 
  GPIO_Init(FMC_A2_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A2_GPIO_PORT, FMC_A2_PINSOURCE , FMC_A2_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A3_GPIO_PIN; 
  GPIO_Init(FMC_A3_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A3_GPIO_PORT, FMC_A3_PINSOURCE , FMC_A3_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A4_GPIO_PIN; 
  GPIO_Init(FMC_A4_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A4_GPIO_PORT, FMC_A4_PINSOURCE , FMC_A4_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A5_GPIO_PIN; 
  GPIO_Init(FMC_A5_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A5_GPIO_PORT, FMC_A5_PINSOURCE , FMC_A5_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A6_GPIO_PIN; 
  GPIO_Init(FMC_A6_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A6_GPIO_PORT, FMC_A6_PINSOURCE , FMC_A6_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A7_GPIO_PIN; 
  GPIO_Init(FMC_A7_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A7_GPIO_PORT, FMC_A7_PINSOURCE , FMC_A7_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A8_GPIO_PIN; 
  GPIO_Init(FMC_A8_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A8_GPIO_PORT, FMC_A8_PINSOURCE , FMC_A8_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A9_GPIO_PIN; 
  GPIO_Init(FMC_A9_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A9_GPIO_PORT, FMC_A9_PINSOURCE , FMC_A9_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A10_GPIO_PIN; 
  GPIO_Init(FMC_A10_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A10_GPIO_PORT, FMC_A10_PINSOURCE , FMC_A10_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_A11_GPIO_PIN; 
  GPIO_Init(FMC_A11_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_A11_GPIO_PORT, FMC_A11_PINSOURCE , FMC_A11_AF);
	
	/*BA��ַ�ź���*/
	GPIO_InitStructure.GPIO_Pin = FMC_BA0_GPIO_PIN; 
  GPIO_Init(FMC_BA0_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_BA0_GPIO_PORT, FMC_BA0_PINSOURCE , FMC_BA0_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_BA1_GPIO_PIN;
  GPIO_Init(FMC_BA1_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_BA1_GPIO_PORT, FMC_BA1_PINSOURCE , FMC_BA1_AF);
  
  
  /*DQ�����ź��� �����������*/
  GPIO_InitStructure.GPIO_Pin = FMC_D0_GPIO_PIN; 
  GPIO_Init(FMC_D0_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D0_GPIO_PORT, FMC_D0_PINSOURCE , FMC_D0_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D1_GPIO_PIN; 
  GPIO_Init(FMC_D1_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D1_GPIO_PORT, FMC_D1_PINSOURCE , FMC_D1_AF);
    
  GPIO_InitStructure.GPIO_Pin = FMC_D2_GPIO_PIN; 
  GPIO_Init(FMC_D2_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D2_GPIO_PORT, FMC_D2_PINSOURCE , FMC_D2_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D3_GPIO_PIN; 
  GPIO_Init(FMC_D3_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D3_GPIO_PORT, FMC_D3_PINSOURCE , FMC_D3_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D4_GPIO_PIN; 
  GPIO_Init(FMC_D4_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D4_GPIO_PORT, FMC_D4_PINSOURCE , FMC_D4_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D5_GPIO_PIN; 
  GPIO_Init(FMC_D5_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D5_GPIO_PORT, FMC_D5_PINSOURCE , FMC_D5_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D6_GPIO_PIN; 
  GPIO_Init(FMC_D6_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D6_GPIO_PORT, FMC_D6_PINSOURCE , FMC_D6_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D7_GPIO_PIN; 
  GPIO_Init(FMC_D7_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D7_GPIO_PORT, FMC_D7_PINSOURCE , FMC_D7_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D8_GPIO_PIN; 
  GPIO_Init(FMC_D8_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D8_GPIO_PORT, FMC_D8_PINSOURCE , FMC_D8_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D9_GPIO_PIN; 
  GPIO_Init(FMC_D9_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D9_GPIO_PORT, FMC_D9_PINSOURCE , FMC_D9_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D10_GPIO_PIN; 
  GPIO_Init(FMC_D10_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D10_GPIO_PORT, FMC_D10_PINSOURCE , FMC_D10_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D11_GPIO_PIN; 
  GPIO_Init(FMC_D11_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D11_GPIO_PORT, FMC_D11_PINSOURCE , FMC_D11_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D12_GPIO_PIN; 
  GPIO_Init(FMC_D12_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D12_GPIO_PORT, FMC_D12_PINSOURCE , FMC_D12_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D13_GPIO_PIN; 
  GPIO_Init(FMC_D13_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D13_GPIO_PORT, FMC_D13_PINSOURCE , FMC_D13_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D14_GPIO_PIN; 
  GPIO_Init(FMC_D14_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D14_GPIO_PORT, FMC_D14_PINSOURCE , FMC_D14_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_D15_GPIO_PIN; 
  GPIO_Init(FMC_D15_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_D15_GPIO_PORT, FMC_D15_PINSOURCE , FMC_D15_AF);
  
  /*�����ź���*/
  GPIO_InitStructure.GPIO_Pin = FMC_CS_GPIO_PIN; 
  GPIO_Init(FMC_CS_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_CS_GPIO_PORT, FMC_CS_PINSOURCE , FMC_CS_AF);
    
  GPIO_InitStructure.GPIO_Pin = FMC_WE_GPIO_PIN; 
  GPIO_Init(FMC_WE_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_WE_GPIO_PORT, FMC_WE_PINSOURCE , FMC_WE_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_RAS_GPIO_PIN; 
  GPIO_Init(FMC_RAS_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_RAS_GPIO_PORT, FMC_RAS_PINSOURCE , FMC_RAS_AF);
    
  GPIO_InitStructure.GPIO_Pin = FMC_CAS_GPIO_PIN; 
  GPIO_Init(FMC_CAS_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_CAS_GPIO_PORT, FMC_CAS_PINSOURCE , FMC_CAS_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_CLK_GPIO_PIN; 
  GPIO_Init(FMC_CLK_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_CLK_GPIO_PORT, FMC_CLK_PINSOURCE , FMC_CLK_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_CKE_GPIO_PIN; 
  GPIO_Init(FMC_CKE_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_CKE_GPIO_PORT, FMC_CKE_PINSOURCE , FMC_CKE_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_UDQM_GPIO_PIN; 
  GPIO_Init(FMC_UDQM_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_UDQM_GPIO_PORT, FMC_UDQM_PINSOURCE , FMC_UDQM_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_LDQM_GPIO_PIN; 
  GPIO_Init(FMC_LDQM_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_LDQM_GPIO_PORT, FMC_LDQM_PINSOURCE , FMC_LDQM_AF);
	

}

//��ʼ��FMC��ʱ�򼰳�ʼ���ṹ��
static void SDRAM_TIMING_Config(void)
{
 FMC_SDRAMInitTypeDef   FMC_SDRAMInitStruct;
 FMC_SDRAMTimingInitTypeDef FMC_SDRAMTimingInitStruct;

  //SDCLKʱ��Ƶ��Ϊf = 90MHz��һ��ʱ������ T =1/f =1/90M =  1.111*10^8 s = 11 ns 
  //��ʼ��ʱ��ṹ��
  FMC_SDRAMTimingInitStruct.FMC_ExitSelfRefreshDelay = 7; //txsr
  FMC_SDRAMTimingInitStruct.FMC_LoadToActiveDelay = 2;  //tmrd
  FMC_SDRAMTimingInitStruct.FMC_RCDDelay = 2;//trcd
  FMC_SDRAMTimingInitStruct.FMC_RowCycleDelay = 6;
  FMC_SDRAMTimingInitStruct.FMC_RPDelay = 2; //trpd
  FMC_SDRAMTimingInitStruct.FMC_SelfRefreshTime = 4; //tras
  FMC_SDRAMTimingInitStruct.FMC_WriteRecoveryTime = 2 ;//twr
  
  //���ó�90MHz
  FMC_SDRAMInitStruct.FMC_SDClockPeriod = FMC_SDClock_Period_2;//hclk��2��Ƶ
  FMC_SDRAMInitStruct.FMC_Bank = FMC_Bank2_SDRAM; //ʹ�õ�sdram����
  FMC_SDRAMInitStruct.FMC_CASLatency = FMC_CAS_Latency_2  ;//CAS�ӳ�����
  
  FMC_SDRAMInitStruct.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_8b  ; //�е�ַ����Ŀ
  FMC_SDRAMInitStruct.FMC_RowBitsNumber = FMC_RowBits_Number_12b;//�е�ַ����Ŀ
  FMC_SDRAMInitStruct.FMC_SDMemoryDataWidth = FMC_SDMemory_Width_16b ; //�����߿�ȣ�16λ
  
  FMC_SDRAMInitStruct.FMC_InternalBankNumber = FMC_InternalBank_Number_4 ;//sdram�ڲ�bank��Ŀ
  FMC_SDRAMInitStruct.FMC_ReadBurst = FMC_Read_Burst_Enable; //ʹ��ͻ����
  FMC_SDRAMInitStruct.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_0 ;//cas����ʱ���ٸ�HCLK
  FMC_SDRAMInitStruct.FMC_WriteProtection = FMC_Write_Protection_Disable ; //��ֹд����

  FMC_SDRAMInitStruct.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingInitStruct;
  
 FMC_SDRAMInit (&FMC_SDRAMInitStruct);

  
}  


static void SDRAM_Delay(uint32_t delay)
{
  for(;delay>0;delay--);
    
}

//ʹ�������ʼ��SDRAM
static void SDRAM_Init_Process(void)
{
  
  FMC_SDRAMCommandTypeDef FMC_SDRAMCommandStruct;
 
  //1.����SDCLK
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_CLK_Enabled  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //��������
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //�ȴ���������
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  //��ʱ
  SDRAM_Delay(0xFFFFF);
  
  //2.������BANK����Ԥ���
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_PALL  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //��������
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //�ȴ���������
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  
    //��ʱ
  SDRAM_Delay(0xFFFFF);
  
  //3.�Զ�ˢ����������
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_AutoRefresh  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 2 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //��������
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //�ȴ���������
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  
      //��ʱ
  SDRAM_Delay(0xFFFFF);
  
  //4.����ģʽ�Ĵ���
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_LoadMode  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = BURST_LENGTH|  BT|CAS_LATENCY|OP_CODE|WB;
  
  //��������
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //�ȴ���������
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);

  SDRAM_Delay(0xFFFFF);


}  


void SDRAM_Init(void)
{
  SDRAM_GPIO_Config();
  SDRAM_TIMING_Config();
  SDRAM_Init_Process();
}


/*********************************************END OF FILE**********************/
