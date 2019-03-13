/**
  ******************************************************************************
  * @file    bsp_debug_usart.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   FLASH 驱动
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板  
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./flash/bsp_spi_flash.h"


static  uint8_t SPI_TIMEOUT_UserCallback(uint8_t errorCode);
static void Wait_for_Ready(void);

uint32_t time_out = SPI_LONG_TIMEOUT;  

 /**
  * @brief  初始化FLASH的SPI引脚
  * @param  无
  * @retval 无
  */
void FLASH_SPI_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  SPI_InitTypeDef SPI_InitStructure;
		
 //1.初始化GPIO 
  
  RCC_AHB1PeriphClockCmd(FLASH_SPI_CS_GPIO_CLK|FLASH_SPI_SCK_GPIO_CLK|FLASH_SPI_MISO_GPIO_CLK|FLASH_SPI_MOSI_GPIO_CLK,ENABLE);
  
   /* 连接 引脚源*/
  GPIO_PinAFConfig(FLASH_SPI_SCK_GPIO_PORT,FLASH_SPI_SCK_SOURCE,FLASH_SPI_SCK_AF);

  /*  连接 */
  GPIO_PinAFConfig(FLASH_SPI_MISO_GPIO_PORT,FLASH_SPI_MISO_SOURCE,FLASH_SPI_MISO_AF);
  
  GPIO_PinAFConfig(FLASH_SPI_MOSI_GPIO_PORT,FLASH_SPI_MOSI_SOURCE,FLASH_SPI_MOSI_AF);

  
  /* 使能 SPI 时钟 */
  RCC_APB_CLOCK_FUN(FLASH_SPI_CLK, ENABLE);
  
  /* GPIO初始化 */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  
  /* 配置SCK引脚为复用功能  */
  GPIO_InitStructure.GPIO_Pin = FLASH_SPI_SCK_PIN  ;  
  GPIO_Init(FLASH_SPI_SCK_GPIO_PORT, &GPIO_InitStructure);

  /* 配置MISO引脚为复用功能 */
  GPIO_InitStructure.GPIO_Pin = FLASH_SPI_MISO_PIN;
  GPIO_Init(FLASH_SPI_MISO_GPIO_PORT, &GPIO_InitStructure);
    
  /* 配置MOSI引脚为复用功能 */
  GPIO_InitStructure.GPIO_Pin = FLASH_SPI_MOSI_PIN;
  GPIO_Init(FLASH_SPI_MOSI_GPIO_PORT, &GPIO_InitStructure);
  
  
  /*CS引脚 */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  
  /* 配置SCK引脚为复用功能  */
  GPIO_InitStructure.GPIO_Pin = FLASH_SPI_CS_PIN  ;  
  GPIO_Init(FLASH_SPI_CS_GPIO_PORT, &GPIO_InitStructure);
  
  //2.配置SPI工作模式
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2 ;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge ;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High ;
  SPI_InitStructure.SPI_CRCPolynomial = 0 ; //不需要使用CRC校验
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex  ;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB  ;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft   ;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master ;
  
  SPI_Init(FLASH_SPI,&SPI_InitStructure); 
  
  SPI_Cmd(FLASH_SPI,ENABLE); 
  
  CS_HIGH_DISABLE();
}


//3.接收以及发送数据
uint8_t Read_Write_Byte(uint8_t data)
{

    time_out = SPI_FLAG_TIMEOUT;
  
    while(SPI_GetFlagStatus(FLASH_SPI,SPI_FLAG_TXE) == RESET)
    {
      if((time_out--)==0) return SPI_TIMEOUT_UserCallback(0);
 
    }
    
    //发送缓冲区为空
    SPI_I2S_SendData(FLASH_SPI,data);
        
    
    time_out = SPI_FLAG_TIMEOUT;
    //接收缓冲区为空，死循环
    while(SPI_GetFlagStatus(FLASH_SPI,SPI_FLAG_RXNE) == RESET)
    {
      if((time_out--)==0) return SPI_TIMEOUT_UserCallback(1);
    }
    
    
   return  SPI_I2S_ReceiveData (FLASH_SPI);  
  
  
}



//4.获取flash ID 
uint32_t Read_Device_ID(void)
{
    uint8_t temp[3];
  
    //拉低片选
    CS_LOW_ENABLE();
  
    Read_Write_Byte(JEDEC_ID);

    temp[0] = Read_Write_Byte(DUMMY);
  
    temp[1] = Read_Write_Byte(DUMMY);
  
    temp[2] = Read_Write_Byte(DUMMY);
    
    //拉高片选
    CS_HIGH_DISABLE();
  
    return temp[0]<<16|temp[1]<<8|temp[2];
}

//5.写使能
void Write_Enable(void)
{
    //拉低片选
    CS_LOW_ENABLE();
  
    Read_Write_Byte(WRITE_ENABLE);    
    //拉高片选
    CS_HIGH_DISABLE(); 

}


//5.擦除FLASH
void erace_setor(uint32_t addr)
{
    Write_Enable();
  
    Wait_for_Ready();
    //拉低片选
    CS_LOW_ENABLE();
  
    Read_Write_Byte(ERACE_SECTOR);
  
    Read_Write_Byte((addr>>16)&0xFF);
    Read_Write_Byte((addr>>8)&0xFF);
    Read_Write_Byte(addr&0xFF);  
    
    //拉高片选
    CS_HIGH_DISABLE();
  
   //等待内部时序（等待擦除完成）
  
    
}

//5.读取数据
void Read_buffer(uint8_t* pdata,uint32_t addr,uint32_t numByteTorRead)
{
    Wait_for_Ready();
    //拉低片选
    CS_LOW_ENABLE();
  
    Read_Write_Byte(READ_DATA);
  
    Read_Write_Byte((addr>>16)&0xFF);
    Read_Write_Byte((addr>>8)&0xFF);
    Read_Write_Byte(addr&0xFF); 
  
    while(numByteTorRead--)
    {
      *pdata = Read_Write_Byte(DUMMY);
      pdata++;
    }
    
    //拉高片选
    CS_HIGH_DISABLE();

}


//6.获取寄存器状态
void Wait_for_Ready(void)
{
    uint8_t reg_status=0x01;
  
    while(reg_status &0x01)
    {
      //拉低片选
      CS_LOW_ENABLE();
    
      //读状态寄存器
      Read_Write_Byte(READ_STATUS);

      reg_status = Read_Write_Byte(DUMMY);    
      //拉高片选
      CS_HIGH_DISABLE(); 
    }
    
      
}

//5.读取数据 最多写256个数据
void Write_buffer(uint8_t* pdata,uint32_t addr,uint32_t numByteTorWrite)
{
    Write_Enable();
    Wait_for_Ready();

    //拉低片选
    CS_LOW_ENABLE();
  
    Read_Write_Byte(PAGE_PROGRAM);
  
    Read_Write_Byte((addr>>16)&0xFF);
    Read_Write_Byte((addr>>8)&0xFF);
    Read_Write_Byte(addr&0xFF); 
  
    while(numByteTorWrite--)
    {
      Read_Write_Byte(*pdata);
      pdata++;
    }
    
    //拉高片选
    CS_HIGH_DISABLE();

}





/**
  * @brief  Basic management of the timeout situation.
  * @param  errorCode：错误代码，可以用来定位是哪个环节出错.
  * @retval 返回0，表示IIC读取失败.
  */
static  uint8_t SPI_TIMEOUT_UserCallback(uint8_t errorCode)
{
  /* Block communication and all processes */
  FLASH_ERROR("SPI 等待超时!errorCode = %d",errorCode); 
  
  return 0xFF;
}

/*********************************************END OF FILE**********************/
