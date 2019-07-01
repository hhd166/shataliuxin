#include "led.h"

//LED的IO口初始化程序
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PC端口时钟
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PC.14 LED1-->PC.15 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC
 GPIO_Init(GPIOE, &GPIO_InitStructure);
	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB中部分IO口
	
}
 

void LED3_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
}


void LED3_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
}


void LED2_OFF(void)
{
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}


void LED2_ON(void)
{
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
}


