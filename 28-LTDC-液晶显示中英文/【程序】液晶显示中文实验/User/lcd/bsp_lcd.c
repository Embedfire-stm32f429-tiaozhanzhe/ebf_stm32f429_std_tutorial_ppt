/**
  ******************************************************************************
  * @file    bsp_sdram.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   LCD驱动接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板  
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./lcd/bsp_lcd.h"   
#include "./flash/bsp_spi_flash.h"


//1.初始化LCD驱动的引脚
//2.使用LTDC初始化结构体，配置液晶屏的控制参数
//3.使用LTDC的层级初始化结构体，配置各层的控制参数
//4.直接操控显存，控制液晶屏显示图形
//5.使用DMA2D快速绘制直线及矩形



//1.初始化LCD驱动的引脚

static void LCD_GPIO_Config(void)
{
 GPIO_InitTypeDef GPIO_InitStruct;

 /* 使能LCD使用到的引脚时钟 */
                         //红色数据线
 RCC_AHB1PeriphClockCmd(LTDC_R0_GPIO_CLK | LTDC_R1_GPIO_CLK | LTDC_R2_GPIO_CLK|
                        LTDC_R3_GPIO_CLK | LTDC_R4_GPIO_CLK | LTDC_R5_GPIO_CLK|
                        LTDC_R6_GPIO_CLK | LTDC_R7_GPIO_CLK |
                         //绿色数据线
                         LTDC_G0_GPIO_CLK|LTDC_G1_GPIO_CLK|LTDC_G2_GPIO_CLK|
                         LTDC_G3_GPIO_CLK|LTDC_G4_GPIO_CLK|LTDC_G5_GPIO_CLK|
                         LTDC_G6_GPIO_CLK|LTDC_G7_GPIO_CLK|
                         //蓝色数据线
                         LTDC_B0_GPIO_CLK|LTDC_B1_GPIO_CLK|LTDC_B2_GPIO_CLK|
                         LTDC_B3_GPIO_CLK|LTDC_B4_GPIO_CLK|LTDC_B5_GPIO_CLK|
                         LTDC_B6_GPIO_CLK|LTDC_B7_GPIO_CLK|
                         //控制信号线
                         LTDC_CLK_GPIO_CLK | LTDC_HSYNC_GPIO_CLK |LTDC_VSYNC_GPIO_CLK|
                         LTDC_DE_GPIO_CLK  | LTDC_BL_GPIO_CLK    |LTDC_DISP_GPIO_CLK ,ENABLE);


/* GPIO配置 */

/* 红色数据线 */
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

 //绿色数据线
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

 //蓝色数据线
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

 //控制信号线
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

 //拉高使能lcd
 GPIO_SetBits(LTDC_DISP_GPIO_PORT,LTDC_DISP_GPIO_PIN);
 GPIO_SetBits(LTDC_BL_GPIO_PORT,LTDC_BL_GPIO_PIN);
}  



#define HSW    2
#define VSW    2
#define HBP    46
#define VBP    23
#define HFP    210 
#define VFP     22






//2.使用LTDC初始化结构体，配置液晶屏的控制参数
static void LCD_Mode_Config(void)
{
  LTDC_InitTypeDef LTDC_InitTypeStruct;  
  
    //CLK输出25 MHz 
  //N =200
  //Q = 20 //不重要
  //R= 2
  //DIV =4
  
  RCC_PLLSAIConfig(200,20,2);
  
  RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
  
  RCC_PLLSAICmd (ENABLE );
  
  
  //等待RCC时钟使能完成
  while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC,ENABLE);
  
  RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_DMA2D,ENABLE);
  
  //引脚极性
  LTDC_InitTypeStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL ; //HSYNC低电平有效
  LTDC_InitTypeStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL  ;//VSYNC低电平有效
  LTDC_InitTypeStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL; //DE低电平有效
  LTDC_InitTypeStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC ;//上升沿采集数据
  
  //时间参数
  LTDC_InitTypeStruct.LTDC_HorizontalSync = HSW - 1;
  LTDC_InitTypeStruct.LTDC_VerticalSync = VSW - 1;
  LTDC_InitTypeStruct.LTDC_AccumulatedHBP = HSW+HBP -1 ; 
  LTDC_InitTypeStruct.LTDC_AccumulatedVBP = VSW +VBP -1;
  
  LTDC_InitTypeStruct.LTDC_AccumulatedActiveW = HSW+HBP + LCD_WIDTH  -1;
  LTDC_InitTypeStruct.LTDC_AccumulatedActiveH = VSW+VBP+LCD_HEIGHT -1;
  
  LTDC_InitTypeStruct.LTDC_TotalWidth =  HSW+HBP + LCD_WIDTH + HFP -1;; 
  LTDC_InitTypeStruct.LTDC_TotalHeigh = VSW+VBP+LCD_HEIGHT + VFP -1;
  
  
  //最底下的背景层颜色
  LTDC_InitTypeStruct.LTDC_BackgroundRedValue = 0;
  LTDC_InitTypeStruct.LTDC_BackgroundBlueValue = 0;
  LTDC_InitTypeStruct.LTDC_BackgroundGreenValue = 0;  
  
  LTDC_Init(&LTDC_InitTypeStruct);
    
}

//3.使用LTDC的层级初始化结构体，配置各层的控制参数
static void LCD_Layer_Init(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitTypeStruct;
  
  
  //配置层级输出窗口
  LTDC_Layer_InitTypeStruct.LTDC_HorizontalStart = HBP + HSW;
  LTDC_Layer_InitTypeStruct.LTDC_HorizontalStop = HSW+HBP + LCD_WIDTH  -1;  
  LTDC_Layer_InitTypeStruct.LTDC_VerticalStart = VBP + VSW;
  LTDC_Layer_InitTypeStruct.LTDC_VerticalStop =  VSW+VBP+LCD_HEIGHT -1;
  
  LTDC_Layer_InitTypeStruct.LTDC_PixelFormat = LTDC_Pixelformat_RGB565;
  
  //0为透明，0xFF为不透明
  LTDC_Layer_InitTypeStruct.LTDC_ConstantAlpha = 0xFF;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorRed = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorGreen = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorBlue = 0;
  LTDC_Layer_InitTypeStruct.LTDC_DefaultColorAlpha = 0;
  
  //混合因子
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_CA  ;
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_CA  ;

  //配置显存相关的参数
  LTDC_Layer_InitTypeStruct.LTDC_CFBStartAdress  = LCD_LAYER1_START_ADDR;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineLength = LCD_WIDTH * 2 +3;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineNumber = LCD_HEIGHT;  
  LTDC_Layer_InitTypeStruct.LTDC_CFBPitch = LCD_WIDTH * 2;
  
  LTDC_LayerInit(LTDC_Layer1,&LTDC_Layer_InitTypeStruct); 
  
  
  //配置第二层
  
  LTDC_Layer_InitTypeStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;

  //混合因子
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA  ;
  LTDC_Layer_InitTypeStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA  ;

  //配置显存相关的参数
  LTDC_Layer_InitTypeStruct.LTDC_CFBStartAdress  = LCD_LAYER2_START_ADDR;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineLength = LCD_WIDTH * 4 +3;
  LTDC_Layer_InitTypeStruct.LTDC_CFBLineNumber = LCD_HEIGHT;  
  LTDC_Layer_InitTypeStruct.LTDC_CFBPitch = LCD_WIDTH * 4;
  
  LTDC_LayerInit(LTDC_Layer2,&LTDC_Layer_InitTypeStruct); 

  //使能两层数据源
  LTDC_LayerCmd (LTDC_Layer1,ENABLE);
  LTDC_LayerCmd (LTDC_Layer2,ENABLE);

  //更新配置参数
  LTDC_ReloadConfig (LTDC_IMReload);
  
  //使能抖动单元
  LTDC_DitherCmd(ENABLE);
  
  //使能LTDC
  LTDC_Cmd(ENABLE);
}


//初始化函数
void LCD_Init(void)
{ 

  LCD_GPIO_Config();
  LCD_Mode_Config();
  LCD_Layer_Init();
}

//直接画线、矩形
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



//直接画线、矩形
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


//使用DMA2D画矩形
void DIS_RECT_LAYER1(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_RGB565;
  
  
  
  
  //要传输的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputRed = (0xff >>3) & 0x1F ; //把8位的颜色值转成5位的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = (0xFF>>2) & 0x3F ;//把8位的颜色值转成6位的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = (0x00 >>3) & 0x1F;  //把8位的颜色值转成5位的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //要传输到的显存地址
  DMA2D_InitTypeStruct.DMA2D_OutputMemoryAdd = LCD_LAYER1_START_ADDR +LCD_WIDTH*200*2 + 350*2;
  DMA2D_InitTypeStruct.DMA2D_OutputOffset = 800-100; 
  DMA2D_InitTypeStruct.DMA2D_PixelPerLine = 100;
  DMA2D_InitTypeStruct.DMA2D_NumberOfLine = 100;
  
  DMA2D_Init(&DMA2D_InitTypeStruct);  

  DMA2D_StartTransfer();
  
  while( DMA2D_GetFlagStatus(DMA2D_FLAG_TC) ==RESET);
  
  
}

//使用DMA2D画矩形
void DIS_RECT(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_ARGB8888;
  
  //要传输的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputRed = 0xff;
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = 0xFF;
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //要传输到的显存地址
  DMA2D_InitTypeStruct.DMA2D_OutputMemoryAdd = LCD_LAYER2_START_ADDR +LCD_WIDTH*200*4 + 350*4;
  DMA2D_InitTypeStruct.DMA2D_OutputOffset = 800-100; 
  DMA2D_InitTypeStruct.DMA2D_PixelPerLine = 100;
  DMA2D_InitTypeStruct.DMA2D_NumberOfLine = 100;
  
  DMA2D_Init(&DMA2D_InitTypeStruct);  

  DMA2D_StartTransfer();
  
  while( DMA2D_GetFlagStatus(DMA2D_FLAG_TC) ==RESET);
  
  
}


//使用DMA2D画直线
void DIS_Line_DMA2D(void)
{
  DMA2D_InitTypeDef  DMA2D_InitTypeStruct;
  
  DMA2D_InitTypeStruct.DMA2D_Mode = DMA2D_R2M ;
  DMA2D_InitTypeStruct.DMA2D_CMode = DMA2D_ARGB8888;
  
  //要传输的颜色值
  DMA2D_InitTypeStruct.DMA2D_OutputRed = 0xff;
  DMA2D_InitTypeStruct.DMA2D_OutputGreen = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputBlue = 0x00;
  DMA2D_InitTypeStruct.DMA2D_OutputAlpha = 0xff;
  
  //要传输到的显存地址
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
  
  //字模数据在文件中的偏移地址
  Addr = (((CodeH-0xA0-1)*94) +(CodeL-0xA0-1))*24*24/8 ;
  
  //加上文件在SPI FLASH的地址偏移
  Addr += 1360*4096; 
  
  //从字模的spi flash存储空间中读出字模数据
  SPI_FLASH_BufferRead(pBuffer,Addr,24*24/8);

}



/* 当(0)字模数据
*/
//24*24
uint8_t charater[] =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x0C,0x18,0x70,0x06,0x18,0x60,0x03,0x18,0x80,0x01,0x19,0x00,
0x00,0x1A,0x00,0x00,0x18,0x08,0x1F,0xFF,0xFC,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x0F,0xFF,0xF8,
0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x1F,0xFF,0xF8,0x00,0x00,0x18,0x00,0x00,0x00};/*"当",0*/


//x和y为汉字显示的起始坐标，charater为汉字的gb2312编码
void dis_charater(uint16_t x, uint16_t y, uint16_t charater) 
{
  uint8_t i,j ;
  
  
  GetCharaterData(charater_data_buffer,charater);
  
  uint32_t *p = (uint32_t *)(LCD_LAYER2_START_ADDR + x*4+(y*LCD_WIDTH*4) );
  
  for(i=0;i<24;i++)  //扫描N行
  {
    //扫描一行内的第一个字节数据
    for(j=0;j<8;j++)  //扫描各个像素点
    {
      if(((charater_data_buffer[3*i] << j )&0x80) ) //如果运算结果为非0值，表示像素点有笔迹，为0表示空白
        //printf("*");    //笔迹像素点，输出*号
        *p = 0xFFFF0000;  //笔迹像素点，输出红色
      
      else  
        //printf(" ");    //空白像素点，输出空格
        *p = 0xFF000000;  //笔迹像素点，输出黑色
      
      p++;  //指向下一个像素点的显存空间
    }
  
    //扫描一行内的第二个字节数据
    for(j=0;j<8;j++)  //扫描各个像素点
    {
      if(((charater_data_buffer[3*i+1] << j )&0x80) ) //如果运算结果为非0值，表示像素点有笔迹，为0表示空白
        //printf("*");    //笔迹像素点，输出*号
        *p = 0xFFFF0000;  //笔迹像素点，输出红色
      else  
        //printf(" ");    //空白像素点，输出空格
         *p = 0xFF000000;  //笔迹像素点，输出黑色
      
       p++; //指向下一个像素点的显存空间
      }   

    //扫描一行内的第三个字节数据
    for(j=0;j<8;j++)  //扫描各个像素点
    {
      if(((charater_data_buffer[3*i+2] << j )&0x80) ) //如果运算结果为非0值，表示像素点有笔迹，为0表示空白
        //printf("*");    //笔迹像素点，输出*号
        *p = 0xFFFF0000;  //笔迹像素点，输出红色
      else  
        //printf(" ");    //空白像素点，输出空格
         *p = 0xFF000000;  //笔迹像素点，输出黑色
      
       p++; //指向下一个像素点的显存空间
      
      }      
    
      p += (LCD_WIDTH-24); //指向下一行字模矩阵所在的显存空间
    //printf("\n");
  }
  
}

//dis_string("汉字演示") // 0xBABA 0xXXXX 0xXXXX 0xXXXX\0
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

