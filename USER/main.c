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

 
/************************************************
�̤���Ƕӹ���ģ��

��������1.01
�û���--led
����--key
��ʱ���ж�--timer
���--output

��������1.02
��ʾ��--lcd��font
���������--exti
************************************************/
//u8 cycle=0;

int main(void)
{		

//	 u8 lcd_id[12];			//���LCD ID�ַ���
//	 delay_init();//delay��ʼ��
//		LED_Init();//LED��ʼ��
//	 //key_init();//������ʼ��
//	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //���� NVIC �жϷ��� 2
//	 //timer4_init(60,71);// ���ü�����ֵΪ9999��ʱ�ӷ�ƵֵΪ71
//	 //timer4_IRQ_init();//����timer4��ʱ�ж�
//	 //OUTPUT1_Init();
//	 //timer3_init(9,71);// ���ü�����ֵΪ9��ʱ�ӷ�ƵֵΪ71
//	 //timer3_IRQ_init();//����timer3��ʱ�ж�

//   uart_init(9600);
//	 LCD_Init();
//	 POINT_COLOR=RED;			 	
//   while(1) 
//	 {	
//		 delay_ms(3000);
//		 LCD_DisplayOn();
//		 POINT_COLOR=RED;	  
//	 	 LCD_ShowString(30,50,200,16,16,"SA TA LIU XING");	
//		 LCD_ShowString(30,70,200,16,16,"distance");	
//		 LCD_ShowxNum(60,90,1998,4,16,1);
// 	 	 LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 				 
//		 delay_ms(3000);	
//		 LCD_DisplayOff();
//	 } 
}








