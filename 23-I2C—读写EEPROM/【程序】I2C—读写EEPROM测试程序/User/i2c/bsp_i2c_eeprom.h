#ifndef __BSP_I2C_EEPROM_H
#define	__BSP_I2C_EEPROM_H

#include "stm32f4xx.h"

#define I2C_OWN_ADDR 0x77 

#define I2C_SPEED 400000

#define EEPROM_ADDR (0x50<<1)   //0xA0


//Òý½Å¶¨Òå
/*******************************************************/
#define EEPROM_I2C                              I2C1
#define EEPROM_I2C_CLK                         RCC_APB1Periph_I2C1

#define EEPROM_SCL_GPIO_PORT                    GPIOB
#define EEPROM_SCL_GPIO_CLK                     RCC_AHB1Periph_GPIOB
#define EEPROM_SCL_PIN                          GPIO_Pin_6
#define EEPROM_SCL_AF                           GPIO_AF_I2C1
#define EEPROM_SCL_SOURCE                       GPIO_PinSource6

#define EEPROM_SDA_GPIO_PORT                GPIOB
#define EEPROM_SDA_GPIO_CLK                 RCC_AHB1Periph_GPIOB
#define EEPROM_SDA_PIN                       GPIO_Pin_7
#define EEPROM_SDA_AF                        GPIO_AF_I2C1
#define EEPROM_SDA_SOURCE                   GPIO_PinSource7

/************************************************************/
void EEPROM_GPIO_Config(void);
void EEPROM_I2C_ModeConfig(void);
void EEPROM_Byte_Write(uint8_t* pData,uint8_t addr);
uint8_t EEPROM_Byte_Read(uint8_t addr);

#endif /* __BSP_I2C_EEPROM_H */
