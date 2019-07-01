#ifndef __TIMER_H
#define __TIMER_H	 
#include "sys.h"
#include "led.h"
#include "key.h"

void timer3_init(u16 arr,u16 psc);//timer3初始化函数
void timer4_init(u16 arr,u16 psc);//timer4初始化函数
void timer3_IRQ_init(void);//timer3定时中断配置
void timer4_IRQ_init(void);//timer4定时中断配置

#endif
