#ifndef __BSP_SPI_FLASH_H
#define	__BSP_SPI_FLASH_H

#include "stm32f4xx.h"
#include <stdio.h>


//引脚定义
/*******************************************************/
#define FLASH_SPI                               SPI5
#define FLASH_SPI_CLK                           RCC_APB2Periph_SPI5
#define RCC_APB_CLOCK_FUN                       RCC_APB2PeriphClockCmd


#define FLASH_SPI_CS_GPIO_PORT                 GPIOF
#define FLASH_SPI_CS_GPIO_CLK                 RCC_AHB1Periph_GPIOF
#define FLASH_SPI_CS_PIN                      GPIO_Pin_6
//#define FLASH_SPI_CS_AF                       GPIO_AF_SPI5
//#define FLASH_SPI_CS_SOURCE                   GPIO_PinSource6

#define FLASH_SPI_SCK_GPIO_PORT                 GPIOF
#define FLASH_SPI_SCK_GPIO_CLK                 RCC_AHB1Periph_GPIOF
#define FLASH_SPI_SCK_PIN                      GPIO_Pin_7
#define FLASH_SPI_SCK_AF                       GPIO_AF_SPI5
#define FLASH_SPI_SCK_SOURCE                   GPIO_PinSource7

#define FLASH_SPI_MISO_GPIO_PORT                 GPIOF
#define FLASH_SPI_MISO_GPIO_CLK                 RCC_AHB1Periph_GPIOF
#define FLASH_SPI_MISO_PIN                      GPIO_Pin_8
#define FLASH_SPI_MISO_AF                       GPIO_AF_SPI5
#define FLASH_SPI_MISO_SOURCE                   GPIO_PinSource8

#define FLASH_SPI_MOSI_GPIO_PORT                 GPIOF
#define FLASH_SPI_MOSI_GPIO_CLK                 RCC_AHB1Periph_GPIOF
#define FLASH_SPI_MOSI_PIN                      GPIO_Pin_9
#define FLASH_SPI_MOSI_AF                       GPIO_AF_SPI5
#define FLASH_SPI_MOSI_SOURCE                   GPIO_PinSource9
/************************************************************/


#define CS_HIGH_DISABLE()				GPIO_SetBits(FLASH_SPI_CS_GPIO_PORT,FLASH_SPI_CS_PIN)
#define CS_LOW_ENABLE()				  GPIO_ResetBits(FLASH_SPI_CS_GPIO_PORT,FLASH_SPI_CS_PIN)


/*等待超时时间*/
#define SPI_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define SPI_LONG_TIMEOUT         ((uint32_t)(10 * SPI_FLAG_TIMEOUT))

/*信息输出*/
#define FLASH_DEBUG_ON         0

#define FLASH_INFO(fmt,arg...)           printf("<<-FLASH-INFO->> "fmt"\n",##arg)
#define FLASH_ERROR(fmt,arg...)          printf("<<-FLASH-ERROR->> "fmt"\n",##arg)
#define FLASH_DEBUG(fmt,arg...)          do{\
                                          if(FLASH_DEBUG_ON)\
                                          printf("<<-FLASH-DEBUG->>[%s] [%d]"fmt"\n",__FILE__,__LINE__, ##arg);\
                                          }while(0)



//命令定义

#define DUMMY           0xFF
#define JEDEC_ID        0x9F
#define ERACE_SECTOR    0x20
#define READ_DATA       0x03
#define READ_STATUS     0x05
#define WRITE_ENABLE     0x06                                          
#define PAGE_PROGRAM     0x02

                                          
void FLASH_SPI_Config(void);
uint32_t Read_Device_ID(void);
void erace_setor(uint32_t addr);
void Read_buffer(uint8_t* pdata,uint32_t addr,uint32_t numByteTorRead);
void Write_buffer(uint8_t* pdata,uint32_t addr,uint32_t numByteTorWrite);
                             
                                          
#endif /* __BSP_SPI_FLASH_H */
