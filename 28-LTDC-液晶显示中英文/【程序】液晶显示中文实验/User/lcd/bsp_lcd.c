/**
  ******************************************************************************
  * @file    bsp_sdram.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   LCD�����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������  
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./lcd/bsp_lcd.h"   
#include "./flash/bsp_spi_flash.h"


//1.��ʼ��LCD����������
//2.ʹ��LTDC��ʼ���ṹ�壬����Һ�����Ŀ��Ʋ���
//3.ʹ��LTDC�Ĳ㼶��ʼ���ṹ�壬���ø���Ŀ��Ʋ���
//4.ֱ�Ӳٿ��Դ棬����Һ������ʾͼ��
//5.ʹ��DMA2D���ٻ���ֱ�߼�����



//1.��ʼ��LCD����������

static void LCD_GPIO_Config(void)
{
 GPIO_InitTypeDef GPIO_InitStruct;

 /* ʹ��LCDʹ�õ�������ʱ�� */
                         //��ɫ������
 RCC_AHB1PeriphClockCmd(LTDC_R0_GPIO_CLK | LTDC_R1_GPIO_CLK | LTDC_R2_GPIO_CLK|
                        LTDC_R3_GPIO_CLK | LTDC_R4_GPIO_CLK | LTDC_R5_GPIO_CLK|
                        LTDC_R6_GPIO_CLK | LTDC_R7_GPIO_CLK |
                         //��ɫ������
                         LTDC_G0_GPIO_CLK|LTDC_G1_GPIO_CLK|LTDC_G2_GPIO_CLK|
                         LTDC_G3_GPIO_CLK|LTDC_G4_GPIO_CLK|LTDC_G5_GPIO_CLK|
                         LTDC_G6_GPIO_CLK|LTDC_G7_GPIO_CLK|
                         //��ɫ������
                         LTDC_B0_GPIO_CLK|LTDC_B1_GPIO_CLK|LTDC_B2_GPIO_CLK|
                         LTDC_B3_GPIO_CLK|LTDC_B4_GPIO_CLK|LTDC_B5_GPIO_CLK|
                         LTDC_B6_GPIO_CLK|LTDC_B7_GPIO_CLK|
                         //�����ź���
                         LTDC_CLK_GPIO_CLK | LTDC_HSYNC_GPIO_CLK |LTDC_VSYNC_GPIO_CLK|
                         LTDC_DE_GPIO_CLK  | LTDC_BL_GPIO_CLK    |LTDC_DISP_GPIO_CLK ,ENABLE);


/* GPIO���� */

/* ��ɫ������ */
 GPIO_InitStruct.GPIO_Pin = LTDC_R0_GPIO_PIN;
 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

 GPIO_Init(LTDC_R0_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R0_GPIO_PORT, LTDC_R0_PINSOURCE, LTDC_R0_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R1_GPIO_PIN;
 GPIO_Init(LTDC_R1_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R1_GPIO_PORT, LTDC_R1_PINSOURCE, LTDC_R1_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R2_GPIO_PIN;
 GPIO_Init(LTDC_R2_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R2_GPIO_PORT, LTDC_R2_PINSOURCE, LTDC_R2_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R3_GPIO_PIN;
 GPIO_Init(LTDC_R3_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R3_GPIO_PORT, LTDC_R3_PINSOURCE, LTDC_R3_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R4_GPIO_PIN;
 GPIO_Init(LTDC_R4_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R4_GPIO_PORT, LTDC_R4_PINSOURCE, LTDC_R4_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R5_GPIO_PIN;
 GPIO_Init(LTDC_R5_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R5_GPIO_PORT, LTDC_R5_PINSOURCE, LTDC_R5_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R6_GPIO_PIN;
 GPIO_Init(LTDC_R6_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R6_GPIO_PORT, LTDC_R6_PINSOURCE, LTDC_R6_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_R7_GPIO_PIN;
 GPIO_Init(LTDC_R7_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_R7_GPIO_PORT, LTDC_R7_PINSOURCE, LTDC_R7_AF);

 //��ɫ������
 GPIO_InitStruct.GPIO_Pin = LTDC_G0_GPIO_PIN;
 GPIO_Init(LTDC_G0_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G0_GPIO_PORT, LTDC_G0_PINSOURCE, LTDC_G0_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G1_GPIO_PIN;
 GPIO_Init(LTDC_G1_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G1_GPIO_PORT, LTDC_G1_PINSOURCE, LTDC_G1_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G2_GPIO_PIN;
 GPIO_Init(LTDC_G2_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G2_GPIO_PORT, LTDC_G2_PINSOURCE, LTDC_G2_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G3_GPIO_PIN;
 GPIO_Init(LTDC_G3_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G3_GPIO_PORT, LTDC_G3_PINSOURCE, LTDC_G3_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G4_GPIO_PIN;
 GPIO_Init(LTDC_G4_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G4_GPIO_PORT, LTDC_G4_PINSOURCE, LTDC_G4_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G5_GPIO_PIN;
 GPIO_Init(LTDC_G5_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G5_GPIO_PORT, LTDC_G5_PINSOURCE, LTDC_G5_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G6_GPIO_PIN;
 GPIO_Init(LTDC_G6_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G6_GPIO_PORT, LTDC_G6_PINSOURCE, LTDC_G6_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_G7_GPIO_PIN;
 GPIO_Init(LTDC_G7_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_G7_GPIO_PORT, LTDC_G7_PINSOURCE, LTDC_G7_AF);

 //��ɫ������
 GPIO_InitStruct.GPIO_Pin = LTDC_B0_GPIO_PIN;
 GPIO_Init(LTDC_B0_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B0_GPIO_PORT, LTDC_B0_PINSOURCE, LTDC_B0_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B1_GPIO_PIN;
 GPIO_Init(LTDC_B1_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B1_GPIO_PORT, LTDC_B1_PINSOURCE, LTDC_B1_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B2_GPIO_PIN;
 GPIO_Init(LTDC_B2_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B2_GPIO_PORT, LTDC_B2_PINSOURCE, LTDC_B2_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B3_GPIO_PIN;
 GPIO_Init(LTDC_B3_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B3_GPIO_PORT, LTDC_B3_PINSOURCE, LTDC_B3_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B4_GPIO_PIN;
 GPIO_Init(LTDC_B4_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B4_GPIO_PORT, LTDC_B4_PINSOURCE, LTDC_B4_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B5_GPIO_PIN;
 GPIO_Init(LTDC_B5_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B5_GPIO_PORT, LTDC_B5_PINSOURCE, LTDC_B5_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B6_GPIO_PIN;
 GPIO_Init(LTDC_B6_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B6_GPIO_PORT, LTDC_B6_PINSOURCE, LTDC_B6_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_B7_GPIO_PIN;
 GPIO_Init(LTDC_B7_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_B7_GPIO_PORT, LTDC_B7_PINSOURCE, LTDC_B7_AF);

 //�����ź���
 GPIO_InitStruct.GPIO_Pin = LTDC_CLK_GPIO_PIN;
 GPIO_Init(LTDC_CLK_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_CLK_GPIO_PORT, LTDC_CLK_PINSOURCE, LTDC_CLK_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_HSYNC_GPIO_PIN;
 GPIO_Init(LTDC_HSYNC_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_HSYNC_GPIO_PORT, LTDC_HSYNC_PINSOURCE, LTDC_HSYNC_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_VSYNC_GPIO_PIN;
 GPIO_Init(LTDC_VSYNC_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_VSYNC_GPIO_PORT, LTDC_VSYNC_PINSOURCE, LTDC_VSYNC_AF);

 GPIO_InitStruct.GPIO_Pin = LTDC_DE_GPIO_PIN;
 GPIO_Init(LTDC_DE_GPIO_PORT, &GPIO_InitStruct);
 GPIO_PinAFConfig(LTDC_DE_GPIO_PORT, LTDC_DE_PINSOURCE, LTDC_DE_AF);

 //BL DISP
 GPIO_InitStruct.GPIO_Pin = LTDC_DISP_GPIO_PIN;
 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

 GPIO_Init(LTDC_DISP_GPIO_PORT, &GPIO_InitStruct);


 GPIO_InitStruct.GPIO_Pin = LTDC_BL_GPIO_PIN;
 GPIO_Init(LTDC_BL_GPIO_PORT, &GPIO_InitStruct);

 //����ʹ��lcd
 GPIO_SetBits(LTDC_DISP_GPIO_PORT,LTDC_DISP_GPIO_PIN);
 GPIO_SetBits(LTDC_BL_GPIO_PORT,LTDC_BL_GPIO_PIN);
}  



#define HSW    2
#define VSW    2
#define HBP    46
#define VBP    23
#define HFP    210 
#define VFP     22






//2.ʹ��LTDC��ʼ���ṹ�壬����Һ�����Ŀ��Ʋ���
static void LCD_Mode_Config(void)
{
  LTDC_InitTypeDef LTDC_InitTypeStruct;  
  
    //CLK���25 MHz 
  //N =200
  //Q = 20 //����Ҫ
  //R= 2
  //DIV =4
  
  RCC_PLLSAIConfig(200,20,2);
  
  RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
  
  RCC_PLLSAICmd (ENABLE );
  
  
  //�ȴ�RCCʱ��ʹ�����
  while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC,ENABLE);
  
  RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_DMA2D,ENABLE);
  
  //���ż���
  LTDC_InitTypeStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL ; //HSYNC�͵�ƽ��Ч
  LTDC_InitTypeStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL  ;//VSYNC�͵�ƽ��Ч
  LTDC_InitTypeStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL; //DE�͵�ƽ��Ч
  LTDC_InitTypeStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC ;//�����زɼ�����
  
  //ʱ�����
  LTDC_InitTypeStruct.LTDC_HorizontalSync = HSW - 1;
  LTDC_InitTypeStruct.LTDC_VerticalSync = VSW - 1;
  LTDC_InitTypeStruct.LTDC_AccumulatedHBP = HSW+HBP -1 ; 
  LTDC_InitTypeStruct.LTDC_AccumulatedVBP = VSW +VBP -1;
  
  LTDC_InitTypeStruct.LTDC_AccumulatedActiveW = HSW+HBP + LCD_WIDTH  -1;
  LTDC_InitTypeStruct.LTDC_AccumulatedActiveH = VSW+VBP+LCD_HEIGHT -1;
  
  LTDC_InitTypeStruct.LTDC_TotalWidth =  HSW+HBP + LCD_WIDTH + HFP -1;; 
  LTDC_InitTypeStruct.LTDC_TotalHeigh = VSW+VBP+LCD_HEIGHT + VFP -1;
  
  
  //����µı�������ɫ
  LTDC_InitTypeStruct.LTDC_BackgroundRedValue = 0;
  LTDC_InitTypeStruct.LTDC_BackgroundBlueValue = 0;
  LTDC_InitTypeStruct.LTDC_BackgroundGreenValue = 0;  
  
  LTDC_Init(&LTDC_InitTypeStruct);
    
}

//3.ʹ��LTDC�Ĳ㼶��ʼ���ṹ�壬���ø���Ŀ��Ʋ���
static void LCD_Layer_Init(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitTypeStruct;
  
  
  //���ò㼶�������
  LTDC_Layer_InitTypeStruct.LTDC_HorizontalStart = HBP + HSW;
  LTDC_Layer_InitTypeStruct.LTDC_HorizontalStop = HSW+HBP + LCD_WIDTH  -1;  
  LTDC_Layer_InitTypeStruct.LTDC_VerticalStart = VBP + VSW;
  LTDC_Layer_InitTypeStruct.LTDC_VerticalStop =  VSW+VBP+LCD_HEIGHT -1;
  
  LTDC_Layer_InitTypeStruct.LTDC_PixelFormat = LTDC_Pixelformat_RGB565;
  
  //0Ϊ͸����0xFFΪ��͸��
  LTDC_Layer_InitTypeStruct.LTDC_ConstantAlpha = 0xFF;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorRed = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorGreen = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorBlue = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorAlpha = 0;
  
  //�������
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_CA  ;
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_CA  ;

  //�����Դ���صĲ���
  LTDC_Layer_InitTypeStruct.LTDC_CFBStartAdress  = LCD_LAYER1_START_ADDR;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineLength = LCD_WIDTH * 2 +3;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineNumber = LCD_HEIGHT;  
  LTDC_Layer_InitTypeStruct.LTDC_CFBPitch = LCD_WIDTH * 2;
  
  LTDC_LayerInit(LTDC_Layer1,&LTDC_Layer_InitTypeStruct); 
  
  
  //���õڶ���
  
  LTDC_Layer_InitTypeStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;

  //�������
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA  ;
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA  ;

  //�����Դ���صĲ���
  LTDC_Layer_InitTypeStruct.LTDC_CFBStartAdress  = LCD_LAYER2_START_ADDR;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineLength = LCD_WIDTH * 4 +3;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineNumber = LCD_HEIGHT;  
  LTDC_Layer_InitTypeStruct.LTDC_CFBPitch = LCD_WIDTH * 4;
  
  LTDC_LayerInit(LTDC_Layer2,&LTDC_Layer_InitTypeStruct); 

  //ʹ����������Դ
  LTDC_LayerCmd (LTDC_Layer1,ENABLE);
  LTDC_LayerCmd (LTDC_Layer2,ENABLE);

  //�������ò���
  LTDC_ReloadConfig (LTDC_IMReload);
  
  //ʹ�ܶ�����Ԫ
  LTDC_DitherCmd(ENABLE);
  
  //ʹ��LTDC
  LTDC_Cmd(ENABLE);
}


//��ʼ������
void LCD_Init(void)
{ 

  LCD_GPIO_Config();
  LCD_Mode_Config();
  LCD_Layer_Init();
}

//ֱ�ӻ��ߡ�����
void DIS_Line(void)
{
  uint16_t i,j;
  
  uint32_t *p = (uint32_t *)(LCD_LAYER2_START_ADDR );
  
  for(j=0;j<480;j++)
  for(i=0;i<800;i++)
  {
    //ARGB8888 
    *p = 0x7F0000FF;
    p++;
    }
  
  
}  



//ֱ�ӻ��ߡ�����
void DIS_Line_Layer1(void)
{
  uint16_t i,j;
  
  uint16_t *p = (uint16_t *)(LCD_LAYER1_START_ADDR );
  
  for(j=0;j<480;j++)
  for(i=0;i<800;i++)
  {
    //ARGB8888
    *p = 0xF800;
    p++;
    }
  
  
}  


//ʹ��DMA2D������
void DIS_RECT_LAYER1(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_RGB565;
  
  
  
  
  //Ҫ�������ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputRed = (0xff >>3) & 0x1F ; //��8λ����ɫֵת��5λ����ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = (0xFF>>2) & 0x3F ;//��8λ����ɫֵת��6λ����ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = (0x00 >>3) & 0x1F;  //��8λ����ɫֵת��5λ����ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //Ҫ���䵽���Դ��ַ
  DMA2D_InitTypeStruct.DMA2D_OutputMemoryAdd = LCD_LAYER1_START_ADDR +LCD_WIDTH*200*2 + 350*2;
  DMA2D_InitTypeStruct.DMA2D_OutputOffset = 800-100; 
  DMA2D_InitTypeStruct.DMA2D_PixelPerLine = 100;
  DMA2D_InitTypeStruct.DMA2D_NumberOfLine = 100;
  
  DMA2D_Init(&DMA2D_InitTypeStruct);  

  DMA2D_StartTransfer();
  
  while( DMA2D_GetFlagStatus(DMA2D_FLAG_TC) ==RESET);
  
  
}

//ʹ��DMA2D������
void DIS_RECT(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_ARGB8888;
  
  //Ҫ�������ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputRed = 0xff;
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = 0xFF;
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //Ҫ���䵽���Դ��ַ
  DMA2D_InitTypeStruct.DMA2D_OutputMemoryAdd = LCD_LAYER2_START_ADDR +LCD_WIDTH*200*4 + 350*4;
  DMA2D_InitTypeStruct.DMA2D_OutputOffset = 800-100; 
  DMA2D_InitTypeStruct.DMA2D_PixelPerLine = 100;
  DMA2D_InitTypeStruct.DMA2D_NumberOfLine = 100;
  
  DMA2D_Init(&DMA2D_InitTypeStruct);  

  DMA2D_StartTransfer();
  
  while( DMA2D_GetFlagStatus(DMA2D_FLAG_TC) ==RESET);
  
  
}


//ʹ��DMA2D��ֱ��
void DIS_Line_DMA2D(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_ARGB8888;
  
  //Ҫ�������ɫֵ
  DMA2D_InitTypeStruct.DMA2D_OutputRed = 0xff;
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //Ҫ���䵽���Դ��ַ
  DMA2D_InitTypeStruct.DMA2D_OutputMemoryAdd = LCD_LAYER2_START_ADDR +LCD_WIDTH*20*4 + 350*4;
  DMA2D_InitTypeStruct.DMA2D_OutputOffset = 800-1; 
  DMA2D_InitTypeStruct.DMA2D_PixelPerLine = 1;
  DMA2D_InitTypeStruct.DMA2D_NumberOfLine = 200;
  
  DMA2D_Init(&DMA2D_InitTypeStruct);  

  DMA2D_StartTransfer();
  
  while( DMA2D_GetFlagStatus(DMA2D_FLAG_TC) ==RESET);
  
  
}

uint8_t charater_data_buffer[72]={0};

//GetCharaterData(charater_data_buffer,0xBABA); 'C'  \0
void GetCharaterData(uint8_t *pBuffer,uint16_t charater)
{
  uint8_t CodeH,CodeL;  
  uint32_t Addr;
  
  CodeH = (charater&0xFF00)>>8;
  CodeL = (charater&0x00FF);
  
  //��ģ�������ļ��е�ƫ�Ƶ�ַ
  Addr = (((CodeH-0xA0-1)*94) +(CodeL-0xA0-1))*24*24/8 ;
  
  //�����ļ���SPI FLASH�ĵ�ַƫ��
  Addr += 1360*4096; 
  
  //����ģ��spi flash�洢�ռ��ж�����ģ����
  SPI_FLASH_BufferRead(pBuffer,Addr,24*24/8);

}



/* ��(0)��ģ����
*/
//24*24
uint8_t charater[] =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x0C,0x18,0x70,0x06,0x18,0x60,0x03,0x18,0x80,0x01,0x19,0x00,
0x00,0x1A,0x00,0x00,0x18,0x08,0x1F,0xFF,0xFC,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x0F,0xFF,0xF8,
0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x1F,0xFF,0xF8,0x00,0x00,0x18,0x00,0x00,0x00};/*"��",0*/


//x��yΪ������ʾ����ʼ���꣬charaterΪ���ֵ�gb2312����
void dis_charater(uint16_t x, uint16_t y, uint16_t charater) 
{
  uint8_t i,j ;
  
  
  GetCharaterData(charater_data_buffer,charater);
  
  uint32_t *p = (uint32_t *)(LCD_LAYER2_START_ADDR + x*4+(y*LCD_WIDTH*4) );
  
  for(i=0;i<24;i++)  //ɨ��N��
  {
    //ɨ��һ���ڵĵ�һ���ֽ�����
    for(j=0;j<8;j++)  //ɨ��������ص�
    {
      if(((charater_data_buffer[3*i] << j )&0x80) ) //���������Ϊ��0ֵ����ʾ���ص��бʼ���Ϊ0��ʾ�հ�
        //printf("*");    //�ʼ����ص㣬���*��
        *p = 0xFFFF0000;  //�ʼ����ص㣬�����ɫ
      
      else  
        //printf(" ");    //�հ����ص㣬����ո�
        *p = 0xFF000000;  //�ʼ����ص㣬�����ɫ
      
      p++;  //ָ����һ�����ص���Դ�ռ�
    }
  
    //ɨ��һ���ڵĵڶ����ֽ�����
    for(j=0;j<8;j++)  //ɨ��������ص�
    {
      if(((charater_data_buffer[3*i+1] << j )&0x80) ) //���������Ϊ��0ֵ����ʾ���ص��бʼ���Ϊ0��ʾ�հ�
        //printf("*");    //�ʼ����ص㣬���*��
        *p = 0xFFFF0000;  //�ʼ����ص㣬�����ɫ
      else  
        //printf(" ");    //�հ����ص㣬����ո�
         *p = 0xFF000000;  //�ʼ����ص㣬�����ɫ
      
       p++; //ָ����һ�����ص���Դ�ռ�
      }   

    //ɨ��һ���ڵĵ������ֽ�����
    for(j=0;j<8;j++)  //ɨ��������ص�
    {
      if(((charater_data_buffer[3*i+2] << j )&0x80) ) //���������Ϊ��0ֵ����ʾ���ص��бʼ���Ϊ0��ʾ�հ�
        //printf("*");    //�ʼ����ص㣬���*��
        *p = 0xFFFF0000;  //�ʼ����ص㣬�����ɫ
      else  
        //printf(" ");    //�հ����ص㣬����ո�
         *p = 0xFF000000;  //�ʼ����ص㣬�����ɫ
      
       p++; //ָ����һ�����ص���Դ�ռ�
      
      }      
    
      p += (LCD_WIDTH-24); //ָ����һ����ģ�������ڵ��Դ�ռ�
    //printf("\n");
  }
  
}

//dis_string("������ʾ") // 0xBABA 0xXXXX 0xXXXX 0xXXXX\0
void dis_string(uint16_t x, uint16_t y,char *pString) 
{
  uint16_t charater;
  uint16_t x_dis = x;
  
  while(*pString != '\0')
  {
    charater = *(uint16_t *)pString ;
    charater = ((charater&0x00FF) <<8) | ((charater&0xFF00) >>8);

    dis_charater(x_dis,y,charater);
    
    x_dis += 24;
    
    pString += 2;
  }
}

/*********************************************END OF FILE**********************/

