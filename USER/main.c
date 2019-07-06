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
飒踏流星队工程模板

六月七日1.01
用户灯--led
按键--key
计时器中断--timer
输出--output

六月七日1.02
显示屏--lcd，font
超声波测距--exti
************************************************/
//u8 cycle=0;

int main(void)
{		

//	 u8 lcd_id[12];			//存放LCD ID字符串
//	 delay_init();//delay初始化
//		LED_Init();//LED初始化
//	 //key_init();//按键初始化
//	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置 NVIC 中断分组 2
//	 //timer4_init(60,71);// 配置计数阈值为9999，时钟分频值为71
//	 //timer4_IRQ_init();//配置timer4定时中断
//	 //OUTPUT1_Init();
//	 //timer3_init(9,71);// 配置计数阈值为9，时钟分频值为71
//	 //timer3_IRQ_init();//配置timer3定时中断

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
// 	 	 LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 				 
//		 delay_ms(3000);	
//		 LCD_DisplayOff();
//	 } 
}








