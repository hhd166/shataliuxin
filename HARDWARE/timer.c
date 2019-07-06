#include "sys.h"
#include "led.h"
#include "key.h"
#include "output.h"

extern u8 EXTI_STATUS;

//timer3的初始化程序
//arr：计数阈值，本例程为9，超过时，自动清零，并触发中断
//psc：时钟预分频值，本例程为71
//TIM_CKD_DIV1：时钟总线频率设置为72M
//TIM_CounterMode_Up：向上计数
//本例程中timer3 10us触发一次

u8 counter=0,i=0;
																				
void timer3_Init(u16 arr,u16 psc)
{
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //使能timer3时钟
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //清除TIM3溢出中断标志
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx	
	
}
 
void timer3_IRQ_Init()
{
	NVIC_InitTypeDef NVIC_InitStructure;
		
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级1级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
	
}

//timer4的初始化程序
//arr：计数阈值，本例程为9999，超过时，自动清零，并触发中断
//psc：时钟预分频值，本例程为71，72分频
//TIM_CKD_DIV1：时钟总线频率设置为72M
//TIM_CounterMode_Up：向上计数
//本例程中timer4 10ms触发一次
void timer4_Init(u16 arr,u16 psc)
{
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //使能timer4时钟
	
	//定时器TIM4初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据指定的参数初始化TIM4的时间基数单位
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update); //清除TIM4溢出中断标志
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM4中断,允许更新中断

	TIM_Cmd(TIM4, ENABLE);  //使能TIM4	
	
}

void timer4_IRQ_Init()
{
	NVIC_InitTypeDef NVIC_InitStructure;
		
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
	
}

//中断处理函数，不需要声明
//TIM4的溢出更新中断响应函数 ，读取按键输入值，根据输入控制pwm波占空比
void TIM4_IRQHandler(void)	 
{
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);//	 清空TIM4溢出中断响应函数标志位
	  
    //if(counter==100) {
			//counter=0;
			if(i%2==0){
				PA10_OUT();
				PA11_DOWN();
			}
			else {
			  PA10_DOWN();	
				PA11_OUT();
			}
			i++;
			if(i==100) i=0;
		//}
			counter++;
	
}	


//中断处理函数，不需要声明
//TIM3的溢出更新中断响应函数，产生pwm波
void TIM3_IRQHandler(void)	  
{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	//	 清空TIM3溢出中断响应函数标志位


}














