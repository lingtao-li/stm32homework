#include "led.h"
#include "stm32f10x.h" 
void delay(unsigned int n)
{
    unsigned int i=0,j=0;
    for(i=0;i<n;i++)
{
for(j=0;j<120;j++){
}
}
}

void led_Init(void){
	GPIO_InitTypeDef GPIO_InitStrcture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4
	|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
	GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrcture);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4
	|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_13;
	GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStrcture);
	
}
void numberone(){
		
		
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
		GPIO_SetBits(GPIOA,GPIO_Pin_3);
	  delay(20);
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
		GPIO_ResetBits(GPIOA,GPIO_Pin_3);
		delay(20);
	
}
void numbertwo(){

		
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
	
}
