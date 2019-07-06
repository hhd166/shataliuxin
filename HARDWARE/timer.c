#include "sys.h"
#include "led.h"
#include "key.h"
#include "output.h"

extern u8 EXTI_STATUS;

//timer3�ĳ�ʼ������
//arr��������ֵ��������Ϊ9������ʱ���Զ����㣬�������ж�
//psc��ʱ��Ԥ��Ƶֵ��������Ϊ71
//TIM_CKD_DIV1��ʱ������Ƶ������Ϊ72M
//TIM_CounterMode_Up�����ϼ���
//��������timer3 10us����һ��

u8 counter=0,i=0;
																				
void timer3_Init(u16 arr,u16 psc)
{
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʹ��timer3ʱ��
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //���TIM3����жϱ�־
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx	
	
}
 
void timer3_IRQ_Init()
{
	NVIC_InitTypeDef NVIC_InitStructure;
		
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //�����ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
}

//timer4�ĳ�ʼ������
//arr��������ֵ��������Ϊ9999������ʱ���Զ����㣬�������ж�
//psc��ʱ��Ԥ��Ƶֵ��������Ϊ71��72��Ƶ
//TIM_CKD_DIV1��ʱ������Ƶ������Ϊ72M
//TIM_CounterMode_Up�����ϼ���
//��������timer4 10ms����һ��
void timer4_Init(u16 arr,u16 psc)
{
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʹ��timer4ʱ��
	
	//��ʱ��TIM4��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIM4��ʱ�������λ
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update); //���TIM4����жϱ�־
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM4�ж�,��������ж�

	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4	
	
}

void timer4_IRQ_Init()
{
	NVIC_InitTypeDef NVIC_InitStructure;
		
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
}

//�жϴ�����������Ҫ����
//TIM4����������ж���Ӧ���� ����ȡ��������ֵ�������������pwm��ռ�ձ�
void TIM4_IRQHandler(void)	 
{
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);//	 ���TIM4����ж���Ӧ������־λ
	  
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


//�жϴ�����������Ҫ����
//TIM3����������ж���Ӧ����������pwm��
void TIM3_IRQHandler(void)	  
{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	//	 ���TIM3����ж���Ӧ������־λ


}














