
// PH10 输出高电平
GPIOH_ODR |= (1<<10);

// 让一个GPIO输出低电平
void GPIO_ResetBis(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH = 	GPIO_Pin;
}