/**
  ******************************************************************************
  * @file    bsp_debug_usart.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   485驱动
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板  
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./485/bsp_485.h"


//1.初始化485使用到的串口
//2.编写TX_RX引脚控制输出
//3.编写中断服务函数
//4.编写收发测试

//注意！！ 控制TX_RX_EN引脚状态切换后，一定要加延时


//作业：参考本例子，编写485通讯驱动。试验一下把切换状态中的延时取消，观察现象


 /**
  * @brief  配置嵌套向量中断控制器NVIC
  * @param  无
  * @retval 无
  */
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 嵌套向量中断控制器组选择 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* 配置USART为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = __485_USART_IRQ;
  /* 抢断优先级为1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 子优先级为1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* 初始化配置NVIC */
  NVIC_Init(&NVIC_InitStructure);
}


 /**
  * @brief  __485_USART GPIO 配置,工作模式配置。115200 8-N-1 ，中断接收模式
  * @param  无
  * @retval 无
  */
void __485_USART_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
		
  RCC_AHB1PeriphClockCmd(__485_USART_RX_GPIO_CLK|__485_USART_TX_GPIO_CLK|__485_CS_GPIO_CLK,ENABLE);

  /* 使能 USART 时钟 */
  RCC_APB1PeriphClockCmd(__485_USART_CLK, ENABLE);
  
  /* GPIO初始化 */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  
  /* 配置Tx引脚为复用功能  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = __485_USART_TX_PIN  ;  
  GPIO_Init(__485_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  /* 配置Rx引脚为复用功能 */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = __485_USART_RX_PIN;
  GPIO_Init(__485_USART_RX_GPIO_PORT, &GPIO_InitStructure);
  
  //配置485收发器的控制引脚
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Pin = __485_CS__PIN;
  GPIO_Init(__485_CS_GPIO_PORT, &GPIO_InitStructure);
  

  
 /* 连接 PXx 到 USARTx_Tx*/
  GPIO_PinAFConfig(__485_USART_RX_GPIO_PORT,__485_USART_RX_SOURCE,__485_USART_RX_AF);

  /*  连接 PXx 到 USARTx__Rx*/
  GPIO_PinAFConfig(__485_USART_TX_GPIO_PORT,__485_USART_TX_SOURCE,__485_USART_TX_AF);
  
  /* 配置串__485_USART 模式 */
  /* 波特率设置：__485_USART_BAUDRATE */
  USART_InitStructure.USART_BaudRate = __485_USART_BAUDRATE;
  /* 字长(数据位+校验位)：8 */
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  /* 停止位：1个停止位 */
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  /* 校验位选择：不使用校验 */
  USART_InitStructure.USART_Parity = USART_Parity_No;
  /* 硬件流控制：不使用硬件流 */
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  /* USART模式控制：同时使能接收和发送 */
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  /* 完成USART初始化配置 */
  USART_Init(__485_USART, &USART_InitStructure); 
	
  /* 嵌套向量中断控制器NVIC配置 */
	NVIC_Configuration();
  
	/* 使能串口接收中断 */
	USART_ITConfig(__485_USART, USART_IT_RXNE, ENABLE);
	
  /* 使能串口 */
  USART_Cmd(__485_USART, ENABLE);
    //初始化完，485收发器默认处于接收状态
  __485_CS_RX_EN;
}

/*****************  发送一个字符 **********************/
void __485_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
  //准备发送数据
  __485_CS_TX_EN;
  
	/* 发送一个字节数据到USART */
	USART_SendData(pUSARTx,ch);
		
	/* 等待发送数据寄存器为空 */
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	

  
  //发送完成，准备接收数据
  __485_CS_RX_EN;
}



/*********************************************END OF FILE**********************/
