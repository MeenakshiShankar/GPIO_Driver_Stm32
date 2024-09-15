/*
 * ledToggle.c
 *
 *  Created on: Sep 13, 2024
 *      Author: meena
 */

#include "stm32l476xx.h"


void delay(void)
{
	for(uint32_t i = 0;i < 500000 ; i++);

}

int main(void)
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PCLK(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
//		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
//		delay();
	}
	return 0;
}
