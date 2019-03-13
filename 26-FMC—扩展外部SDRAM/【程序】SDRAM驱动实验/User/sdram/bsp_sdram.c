/**
  ******************************************************************************
  * @file    bsp_debug_usart.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SDRAM驱动
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板  
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./sdram/bsp_sdram.h"


//1.初始化FMC使用的GPIO
//2.初始化FMC的时序结构体
//3.初始化FMC的初始化结构体
//4.使用命令初始化SDRAM芯片
//5.进行读写SDRAM测试




//初始化GPIO
static void SDRAM_GPIO_Config(void)
{
 
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* 使能SDRAM相关的GPIO时钟 */

                         /*地址信号线*/
  RCC_AHB1PeriphClockCmd(FMC_A0_GPIO_CLK | FMC_A1_GPIO_CLK | FMC_A2_GPIO_CLK | 
                         FMC_A3_GPIO_CLK | FMC_A4_GPIO_CLK | FMC_A5_GPIO_CLK |
                         FMC_A6_GPIO_CLK | FMC_A7_GPIO_CLK | FMC_A8_GPIO_CLK |
                         FMC_A9_GPIO_CLK | FMC_A10_GPIO_CLK| FMC_A11_GPIO_CLK| 
												 FMC_BA0_GPIO_CLK| FMC_BA1_GPIO_CLK|
                         /*数据信号线*/
                         FMC_D0_GPIO_CLK | FMC_D1_GPIO_CLK | FMC_D2_GPIO_CLK | 
                         FMC_D3_GPIO_CLK | FMC_D4_GPIO_CLK | FMC_D5_GPIO_CLK |
                         FMC_D6_GPIO_CLK | FMC_D7_GPIO_CLK | FMC_D8_GPIO_CLK |
                         FMC_D9_GPIO_CLK | FMC_D10_GPIO_CLK| FMC_D11_GPIO_CLK|
                         FMC_D12_GPIO_CLK| FMC_D13_GPIO_CLK| FMC_D14_GPIO_CLK|
                         FMC_D15_GPIO_CLK|  
                         /*控制信号线*/
                         FMC_CS_GPIO_CLK  | FMC_WE_GPIO_CLK | FMC_RAS_GPIO_CLK |
                         FMC_CAS_GPIO_CLK |FMC_CLK_GPIO_CLK | FMC_CKE_GPIO_CLK |
                         FMC_UDQM_GPIO_CLK|FMC_LDQM_GPIO_CLK, ENABLE);
                         


  
  /*-- GPIO 配置 -----------------------------------------------------*/

  /* 通用 GPIO 配置 */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;       //配置为复用功能
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽输出
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;   
  
  
  /*A行列地址信号线 针对引脚配置*/
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
	
	/*BA地址信号线*/
	GPIO_InitStructure.GPIO_Pin = FMC_BA0_GPIO_PIN; 
  GPIO_Init(FMC_BA0_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_BA0_GPIO_PORT, FMC_BA0_PINSOURCE , FMC_BA0_AF);
  
  GPIO_InitStructure.GPIO_Pin = FMC_BA1_GPIO_PIN;
  GPIO_Init(FMC_BA1_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(FMC_BA1_GPIO_PORT, FMC_BA1_PINSOURCE , FMC_BA1_AF);
  
  
  /*DQ数据信号线 针对引脚配置*/
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
  
  /*控制信号线*/
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

//初始化FMC的时序及初始化结构体
static void SDRAM_TIMING_Config(void)
{
 FMC_SDRAMInitTypeDef   FMC_SDRAMInitStruct;
 FMC_SDRAMTimingInitTypeDef FMC_SDRAMTimingInitStruct;

  //SDCLK时钟频率为f = 90MHz，一个时钟周期 T =1/f =1/90M =  1.111*10^8 s = 11 ns 
  //初始化时序结构体
  FMC_SDRAMTimingInitStruct.FMC_ExitSelfRefreshDelay = 7; //txsr
  FMC_SDRAMTimingInitStruct.FMC_LoadToActiveDelay = 2;  //tmrd
  FMC_SDRAMTimingInitStruct.FMC_RCDDelay = 2;//trcd
  FMC_SDRAMTimingInitStruct.FMC_RowCycleDelay = 6;
  FMC_SDRAMTimingInitStruct.FMC_RPDelay = 2; //trpd
  FMC_SDRAMTimingInitStruct.FMC_SelfRefreshTime = 4; //tras
  FMC_SDRAMTimingInitStruct.FMC_WriteRecoveryTime = 2 ;//twr
  
  //配置成90MHz
  FMC_SDRAMInitStruct.FMC_SDClockPeriod = FMC_SDClock_Period_2;//hclk的2分频
  FMC_SDRAMInitStruct.FMC_Bank = FMC_Bank2_SDRAM; //使用的sdram区域
  FMC_SDRAMInitStruct.FMC_CASLatency = FMC_CAS_Latency_2  ;//CAS延迟周期
  
  FMC_SDRAMInitStruct.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_8b  ; //列地址线数目
  FMC_SDRAMInitStruct.FMC_RowBitsNumber = FMC_RowBits_Number_12b;//行地址线数目
  FMC_SDRAMInitStruct.FMC_SDMemoryDataWidth = FMC_SDMemory_Width_16b ; //数据线宽度：16位
  
  FMC_SDRAMInitStruct.FMC_InternalBankNumber = FMC_InternalBank_Number_4 ;//sdram内部bank数目
  FMC_SDRAMInitStruct.FMC_ReadBurst = FMC_Read_Burst_Enable; //使能突发读
  FMC_SDRAMInitStruct.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_0 ;//cas后延时多少个HCLK
  FMC_SDRAMInitStruct.FMC_WriteProtection = FMC_Write_Protection_Disable ; //禁止写保护

  FMC_SDRAMInitStruct.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingInitStruct;
  
 FMC_SDRAMInit (&FMC_SDRAMInitStruct);

  
}  


static void SDRAM_Delay(uint32_t delay)
{
  for(;delay>0;delay--);
    
}

//使用命令初始化SDRAM
static void SDRAM_Init_Process(void)
{
  
  FMC_SDRAMCommandTypeDef FMC_SDRAMCommandStruct;
 
  //1.开启SDCLK
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_CLK_Enabled  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //发送命令
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //等待命令发送完毕
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  //延时
  SDRAM_Delay(0xFFFFF);
  
  //2.对所有BANK进行预充电
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_PALL  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //发送命令
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //等待命令发送完毕
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  
    //延时
  SDRAM_Delay(0xFFFFF);
  
  //3.自动刷新至少两次
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_AutoRefresh  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 2 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = 0;  
  
  //发送命令
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //等待命令发送完毕
  while( FMC_GetFlagStatus(FMC_Bank2_SDRAM,FMC_FLAG_Busy)== SET);
  
  
  
      //延时
  SDRAM_Delay(0xFFFFF);
  
  //4.加载模式寄存器
  FMC_SDRAMCommandStruct.FMC_CommandMode = FMC_Command_Mode_LoadMode  ;
  FMC_SDRAMCommandStruct.FMC_CommandTarget = FMC_Command_Target_bank2  ; 
  FMC_SDRAMCommandStruct.FMC_AutoRefreshNumber = 0 ;
  FMC_SDRAMCommandStruct.FMC_ModeRegisterDefinition = BURST_LENGTH|  BT|CAS_LATENCY|OP_CODE|WB;
  
  //发送命令
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStruct);

  //等待命令发送完毕
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
