/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   can驱动
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./can/bsp_can.h" 


/**
  * @brief  配置can用到的I/O口
  * @param  无
  * @retval 无
  */
static void CAN_GPIO_Config(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键GPIO口的时钟*/
	RCC_AHB1PeriphClockCmd(CAN_TX_GPIO_CLK|CAN_RX_GPIO_CLK,ENABLE);
	
   /* 连接 PXx 到 _Tx*/
  GPIO_PinAFConfig(CAN_TX_GPIO_PORT,CAN_TX_SOURCE,CAN_TX_AF);

  /*  连接 PXx 到 __Rx*/
  GPIO_PinAFConfig(CAN_RX_GPIO_PORT,CAN_RX_SOURCE,CAN_RX_AF);

  
	GPIO_InitStructure.GPIO_Pin = CAN_TX_PIN;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;   
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  
	GPIO_Init(CAN_TX_GPIO_PORT, &GPIO_InitStructure);    

	GPIO_InitStructure.GPIO_Pin = CAN_RX_PIN; 
  
	GPIO_Init(CAN_RX_GPIO_PORT, &GPIO_InitStructure);  
}


static void CAN_Mode_Config(void)
{
  
  CAN_InitTypeDef Can_InitStruct;
  
    /* 使能CAN 时钟 */
  RCC_APB1PeriphClockCmd(CAN_APB_CLK, ENABLE);

  
  Can_InitStruct.CAN_ABOM = ENABLE;
  Can_InitStruct.CAN_AWUM = ENABLE;

  Can_InitStruct.CAN_Mode = CAN_Mode_Normal;
  Can_InitStruct.CAN_NART = ENABLE;
  Can_InitStruct.CAN_RFLM = DISABLE;
  Can_InitStruct.CAN_TTCM = DISABLE;
  Can_InitStruct.CAN_TXFP = DISABLE; //根据报文ID决定发送优先级
  
  
  //配置CAN的通讯速度
  Can_InitStruct.CAN_Prescaler = 5;
  Can_InitStruct.CAN_BS1 = CAN_BS1_5tq ; //ss+ bs1+bs2 = 1+5+3 =9Tq
  Can_InitStruct.CAN_BS2 = CAN_BS2_3tq ; 
  Can_InitStruct.CAN_SJW = CAN_SJW_4tq  ;
  
  CAN_Init(CAN_NUM,&Can_InitStruct);
  
  CAN_ITConfig(CAN_NUM,CAN_IT_FMP0,ENABLE);
  
}

 /**
  * @brief  配置嵌套向量中断控制器NVIC
  * @param  无
  * @retval 无
  */
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 配置NVIC为优先级组1 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置中断源：按键1 */
  NVIC_InitStructure.NVIC_IRQChannel = CAN_IRQ_Channel;
  /* 配置抢占优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 配置子优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断通道 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  

}





//初始化筛选器
static void CAN_Fliter_Config(void)
{
  CAN_FilterInitTypeDef  CAN_FilterInitStruct;
  
  CAN_FilterInitStruct.CAN_FilterActivation= ENABLE;
  CAN_FilterInitStruct.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0  ;
  CAN_FilterInitStruct.CAN_FilterMode = CAN_FilterMode_IdList;
  CAN_FilterInitStruct.CAN_FilterNumber = 0;
  CAN_FilterInitStruct.CAN_FilterScale =CAN_FilterScale_32bit ;
  
  //扩展的数据帧，ID1:0x1234 ，ID2:0x4321  
  CAN_FilterInitStruct.CAN_FilterIdHigh = (((((uint32_t)MESSAGE_EXID1)<<3)|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF0000)>>16;
  CAN_FilterInitStruct.CAN_FilterIdLow = (((((uint32_t)MESSAGE_EXID1)<<3)|CAN_ID_EXT|CAN_RTR_Data)&0x0000FFFF);
  CAN_FilterInitStruct.CAN_FilterMaskIdHigh =(((((uint32_t)MESSAGE_EXID2)<<3)|CAN_ID_EXT|CAN_RTR_Data)&0xFFFF0000)>>16;
  CAN_FilterInitStruct.CAN_FilterMaskIdLow  =(((((uint32_t)MESSAGE_EXID2)<<3)|CAN_ID_EXT|CAN_RTR_Data)&0x0000FFFF);
   

  CAN_FilterInit(&CAN_FilterInitStruct);
}


//1.初始化GPIO
//2.初始化CAN工作模式
//3.初始化接收中断
//4.编写中断服务函数
//5.初始化筛选器
void CAN_Test_Init(void)
{
  CAN_GPIO_Config();
  CAN_Mode_Config();
  NVIC_Configuration();
  CAN_Fliter_Config();
  
}







/*********************************************END OF FILE**********************/
