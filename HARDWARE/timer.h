#ifndef __TIMER_H
#define __TIMER_H	 
#include "sys.h"
#include "led.h"
#include "key.h"

void timer3_init(u16 arr,u16 psc);//timer3��ʼ������
void timer4_init(u16 arr,u16 psc);//timer4��ʼ������
void timer3_IRQ_init(void);//timer3��ʱ�ж�����
void timer4_IRQ_init(void);//timer4��ʱ�ж�����

#endif
