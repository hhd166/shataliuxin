#include "stm32f10x_exti.h"

u8 EXTI_STATUS=0;
u16 EXTI_TIME=0;
u16 EXTI_DISTANCE=0;

																
void EXTI4_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PC�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC
	
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//ʧ��STM32 JTAG��д���ܣ�ֻ����SWDģʽ��д����ų�PA15��PB�в���IO��
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //ʹ�� AFIO ʱ��

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);//ӳ�亯��
	
  EXTI_InitStructure.EXTI_Line=EXTI_Line4;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//�����½��ش���
  EXTI_Init(&EXTI_InitStructure); //��ʼ�� EXTI �Ĵ���
	
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; //ʹ���ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; //��ռ���ȼ� 2��
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02; //�����ȼ� 2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//��ʼ�� NVIC

}



void EXTI4_IRQHandler(void)
{
   EXTI_ClearITPendingBit(EXTI_Line4); //��� LINE3 �ϵ��жϱ�־λ
	 EXTI_STATUS=!EXTI_STATUS;
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0){
		 EXTI_DISTANCE=EXTI_TIME;
		 EXTI_TIME=0;
	 }
}









