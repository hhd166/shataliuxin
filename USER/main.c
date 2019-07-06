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
飒踏流星队工程模板

6月27日1.01
用户灯--led
按键--key
计时器中断--timer
输出--output

6月30日1.02
显示屏--lcd，font
超声波测距--exti
霍尔元件--adc
************************************************/

extern u32 EXTI_DISTANCE;

u8 cycle=0;
u32 adc=0;
ACCEL MPU6050Value;

int main(void)
{		

	 delay_init();//delay初始化
	 //LED_Init();//LED初始化
	 //key_init();//按键初始化
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置 NVIC 中断分组 2
	 //timer4_init(299,71);
	 //timer4_IRQ_init();//配置timer4定时中断
	 //OUTPUT1_Init();
	 //timer3_init(9,71);// 配置计数阈值为9，时钟分频值为71
	 //timer3_IRQ_init();//配置timer3定时中断
	
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








