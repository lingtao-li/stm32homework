#include "timer.h"
#include "stm32f10x.h" 
void timer1_Init(){

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM3_InitStructure;
	TIM3_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;//设置为向上计数模式
	TIM3_InitStructure.TIM_Period=(1000)-1;//设置周期
	TIM3_InitStructure.TIM_Prescaler=7199;//设置分频
	//TIM2_InitStructure
	//TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInit(TIM3,&TIM3_InitStructure);//对通用定时器进行初始化
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
}
void TIM3_IRQHandler(void)
	{
		if(TIM_GetITStatus(TIM3,TIM_IT_Update)==1)
			{
			if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13)==1)
				{
				GPIO_ResetBits(GPIOB,GPIO_Pin_13);
				}
				else
				{
					GPIO_SetBits(GPIOB,GPIO_Pin_13);
				}
			}
		
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

	}
