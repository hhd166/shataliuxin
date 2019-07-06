#ifndef __TIMER_H
#define __TIMER_H	 

/*
定时器，包含模块：
	步进电机驱动 timer3

*/



void timer3_Init();
void timer4_Init();
void timer3_IRQ_Init(void);//timer3定时中断配置
void timer4_IRQ_Init(void);


#endif
