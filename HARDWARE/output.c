#include "output.h"

//LED��IO�ڳ�ʼ������
void OUTPUT1_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PC�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC
	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//ʧ��STM32 JTAG��д���ܣ�ֻ����SWDģʽ��д����ų�PA15��PB�в���IO��
	
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



