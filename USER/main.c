#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "timer.h"
#include "key.h"
#include "output.h"
#include "adc.h"
#include "lcd.h"
#include "usart.h"
#include "exti.h"
#include "adc.h"
#include "MPU6050.h"
#include "I2C.h"
 
/************************************************
�̤���Ƕӹ���ģ��

6��27��1.01
�û���--led
����--key
��ʱ���ж�--timer
���--output

6��30��1.02
��ʾ��--lcd��font
���������--exti
����Ԫ��--adc
************************************************/

extern u32 EXTI_DISTANCE;

u8 cycle=0;
u32 adc=0;
ACCEL MPU6050Value;

int main(void)
{		

	 delay_init();//delay��ʼ��
	 //LED_Init();//LED��ʼ��
	 //key_init();//������ʼ��
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //���� NVIC �жϷ��� 2
	 //timer4_init(299,71);
	 //timer4_IRQ_init();//����timer4��ʱ�ж�
	 //OUTPUT1_Init();
	 //timer3_init(9,71);// ���ü�����ֵΪ9��ʱ�ӷ�ƵֵΪ71
	 //timer3_IRQ_init();//����timer3��ʱ�ж�
	
	 //EXTIX_Init();
	
	  ADC1_Init();

   uart_init(9600);
	 LCD_Init();
	 POINT_COLOR=RED;			 	
	
   MPU6050Value=MPU6050_GetValue_ACCEL();
	
   while(1) 
	 {		 
		 
		 POINT_COLOR=RED;	  
	 	 LCD_ShowString(30,50,200,16,16,"SA TA LIU XING");	
		 //LCD_ShowString(30,70,200,16,16,"distance");	
		 //LCD_ShowxNum(60,90,EXTI_DISTANCE,8,16,0);  
		 
     adc=ADC_GetConversionValue(ADC1); 
     LCD_ShowString(30,70,200,16,16,"ADCtext");	
		 LCD_ShowxNum(60,90,adc,8,16,0);  	
   		 
		 delay_ms(500);
		 
	 } 
	 
}








