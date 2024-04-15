#include "stm32f10x.h"   
// Device header
#include "timer.h"
#include "led.h"

int main()
{
	timer1_Init();
	led_Init();
	while(1)
	{
		//GPIO_SetBits(GPIOA,GPIO_Pin_2);
		//GPIO_SetBits(GPIOB,GPIO_Pin_13);
		//GPIO_SetBits(GPIOB,GPIO_Pin_1);
		//GPIO_SetBits(GPIOB,GPIO_Pin_2);
		numberone();
		//delay(50);
		
		//numbertwo();
		//delay(50);
		
	}


}
