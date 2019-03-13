/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/
#include "diskio.h"		/* FatFs lower layer API */
#include "./flash/bsp_spi_flash.h"


/* Definitions of physical drive number for each drive */
#define ATA     0
#define SPI_FLASH		1	/* Example: Map FLASH harddisk to physical drive 1 */



/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
//	int result;

	switch (pdrv) {
	case ATA :
		return stat;

	case SPI_FLASH :
      /* 获取 Flash Device ID */
      if (SPI_FLASH_ReadID() == sFLASH_ID)
      {
        return  0;      
      }      
      else
      {
        return STA_NOINIT;      
      }
      

	}
  
  
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
//	int result;

	switch (pdrv) {
	case ATA :
//		result = ATA_disk_initialize();

		// translate the reslut code here

		return stat;

	case SPI_FLASH :
//		result = MMC_disk_initialize();
  
      SPI_FLASH_Init();
  
      SPI_Flash_WAKEUP();
  
      if (SPI_FLASH_ReadID() == sFLASH_ID)
      {
        return  0;      
      }      
      else
      {
        return STA_NOINIT;      
      }

		// translate the reslut code here

//		return stat;

	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;
//	int result;

	switch (pdrv) {
	case ATA :
		// translate the arguments here

//		result = ATA_disk_read(buff, sector, count);

		// translate the reslut code here

		return res;

	case SPI_FLASH :
		// translate the arguments here

    sector += 1536; 
		SPI_FLASH_BufferRead(buff, sector*4096, count*4096);

		// translate the reslut code here

		return RES_OK ;


	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;
//	int result;

	switch (pdrv) {
	case ATA :
		// translate the arguments here

//		result = ATA_disk_write(buff, sector, count);

		// translate the reslut code here

		return res;

	case SPI_FLASH :
		// translate the arguments here

    sector += 1536;
  
    SPI_FLASH_SectorErase(sector*4096);
		SPI_FLASH_BufferWrite((u8 *)buff,sector*4096, count*4096);

		// translate the reslut code here

		return RES_OK;


	}

	return RES_PARERR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
//	int result;

	switch (pdrv) {
	case ATA :

		// Process of the command for the ATA drive

		return res;

	case SPI_FLASH :
    
    switch(cmd)
    {
      case CTRL_SYNC:
        
        
        break;
      
      
      case GET_SECTOR_COUNT:
        *(DWORD *)buff  = 4096 -1536;  //不操作前面6MB 
        break;
      
      case GET_SECTOR_SIZE:
        *(WORD *)buff = 4096;
        break;
      
      case GET_BLOCK_SIZE:
        *(DWORD *)buff = 1;
        break;
    
    
    }

		// Process of the command for the MMC/SD card
    res = RES_OK;
		return res;


	}

	return RES_PARERR;
}
#endif



DWORD get_fattime (void)
{
  return 0; //返回时间，默认

}

