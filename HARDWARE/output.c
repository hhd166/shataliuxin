#include "output.h"

//LED的IO口初始化程序
void OUTPUT1_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PC端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC
	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB中部分IO口
	
 GPIO_ResetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
}
 

void PA10_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
}


void PA10_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_10);
}

void PA11_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_11);
}


void PA11_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
}

void PA12_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
}


void PA12_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
}

void PA13_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_13);
}


void PA13_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_13);
}


void PA14_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_14);
}


void PA14_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_14);
}

void PA15_OUT(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
}


void PA15_DOWN(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);
}



