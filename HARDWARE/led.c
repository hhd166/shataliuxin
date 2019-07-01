#include "led.h"

//LED��IO�ڳ�ʼ������
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PC�˿�ʱ��
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PC.14 LED1-->PC.15 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC
 GPIO_Init(GPIOE, &GPIO_InitStructure);
	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//ʧ��STM32 JTAG��д���ܣ�ֻ����SWDģʽ��д����ų�PA15��PB�в���IO��
	
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


