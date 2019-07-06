#include "stm32f10x_exti.h"

u8 EXTI_STATUS=0;
u16 EXTI_TIME=0;
u16 EXTI_DISTANCE=0;

																
void EXTI4_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PC端口时钟
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC
	
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB中部分IO口
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //使能 AFIO 时钟

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);//映射函数
	
  EXTI_InitStructure.EXTI_Line=EXTI_Line4;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//上升下降沿触发
  EXTI_Init(&EXTI_InitStructure); //初始化 EXTI 寄存器
	
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; //使能中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; //抢占优先级 2，
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02; //子优先级 2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//初始化 NVIC

}



void EXTI4_IRQHandler(void)
{
   EXTI_ClearITPendingBit(EXTI_Line4); //清除 LINE3 上的中断标志位
	 EXTI_STATUS=!EXTI_STATUS;
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0){
		 EXTI_DISTANCE=EXTI_TIME;
		 EXTI_TIME=0;
	 }
}









