
// PH10 ����ߵ�ƽ
GPIOH_ODR |= (1<<10);

// ��һ��GPIO����͵�ƽ
void GPIO_ResetBis(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRRH = 	GPIO_Pin;
}