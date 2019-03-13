#include "./i2c/bsp_i2c_eeprom.h"

void Wait_for_EEPROM(void);
//1.��ʼ��GPIO
void EEPROM_GPIO_Config(void)
{

  GPIO_InitTypeDef GPIO_InitStructure;
		
  RCC_AHB1PeriphClockCmd(EEPROM_SCL_GPIO_CLK|EEPROM_SDA_GPIO_CLK,ENABLE);

    
 /* ����SCL*/
  GPIO_PinAFConfig(EEPROM_SCL_GPIO_PORT,EEPROM_SCL_SOURCE,EEPROM_SCL_AF);

  /*  ���� SDA*/
  GPIO_PinAFConfig(EEPROM_SDA_GPIO_PORT,EEPROM_SDA_SOURCE,EEPROM_SDA_AF);
  
  
  /* GPIO��ʼ�� */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  
  /* ����SCL����Ϊ���ù���  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = EEPROM_SCL_PIN  ;  
  GPIO_Init(EEPROM_SCL_GPIO_PORT, &GPIO_InitStructure);

  /* ����SDA����Ϊ���ù��� */
  GPIO_InitStructure.GPIO_Pin = EEPROM_SDA_PIN;
  GPIO_Init(EEPROM_SDA_GPIO_PORT, &GPIO_InitStructure);
  

}

//2.��ʼ��I2Cģʽ
void EEPROM_I2C_ModeConfig(void)
{
  I2C_InitTypeDef I2C_InitStruct;
    
  /* ʹ�� I2Cʱ�� */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
  
  I2C_InitStruct.I2C_Ack =  I2C_Ack_Enable;
  I2C_InitStruct.I2C_AcknowledgedAddress =  I2C_AcknowledgedAddress_7bit;
  I2C_InitStruct.I2C_ClockSpeed =  I2C_SPEED; 
  I2C_InitStruct.I2C_DutyCycle =  I2C_DutyCycle_2 ;
  I2C_InitStruct.I2C_Mode =  I2C_Mode_I2C ;
  I2C_InitStruct.I2C_OwnAddress1 = I2C_OWN_ADDR;
  
  I2C_Init(EEPROM_I2C,&I2C_InitStruct);
  
  I2C_Cmd(EEPROM_I2C,ENABLE);

}


//3.byte write ����
void EEPROM_Byte_Write(uint8_t* pData,uint8_t addr)
{
  I2C_GenerateSTART(EEPROM_I2C,ENABLE);
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS )
  {
     //....
  }
    
  I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) != SUCCESS )
  {
  
  }
  
  
  I2C_SendData(EEPROM_I2C,addr);
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED) != SUCCESS )
  {
  
  }
  
  
  I2C_SendData(EEPROM_I2C,*pData);
  
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED) != SUCCESS )
  {
  
  }
  
  
  I2C_GenerateSTOP(EEPROM_I2C,ENABLE);

}


//4.random read
uint8_t EEPROM_Byte_Read(uint8_t addr)
{
  uint8_t readTemp;

  Wait_for_EEPROM();
  
  
  I2C_GenerateSTART(EEPROM_I2C,ENABLE);
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS )
  {
     //....
  }
    
  I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) != SUCCESS )
  {
  
  }
  
  
  I2C_SendData(EEPROM_I2C,addr);
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED) != SUCCESS )
  {
  
  }
  
  
  I2C_GenerateSTART(EEPROM_I2C,ENABLE);
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS )
  {
     //....
  }

  
  I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Receiver);
  
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) != SUCCESS )
  {
  
  }
  
  I2C_AcknowledgeConfig(EEPROM_I2C,DISABLE);
  
  while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_RECEIVED) != SUCCESS )
  {
  
  }
  
  readTemp = I2C_ReceiveData(EEPROM_I2C);
   
  
  I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
  
  return readTemp;

}

//5.�ȴ�EEPROM�ڲ�д���
void Wait_for_EEPROM(void)
{
  do
  {
    I2C_GenerateSTART(EEPROM_I2C,ENABLE);
  
//    while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS )
//    {
//       //....
//    }
      
    I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);  
  
  }while(I2C_GetFlagStatus(EEPROM_I2C,I2C_FLAG_ADDR) == RESET);
  
  //�ȴ�ADDR = 1 ��ִ����������
  
  I2C_ClearFlag(EEPROM_I2C,I2C_FLAG_AF);
  
  
  I2C_GenerateSTOP(EEPROM_I2C,ENABLE);

  
  while(I2C_GetFlagStatus(EEPROM_I2C,I2C_FLAG_BUSY) == SET);
  
  //���߿��У�ִ����������

}  



/*********************************************END OF FILE**********************/


