 // include "PaoMaoDeng.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

void PaoMaDeng_Init()
{
	delay_init();
	LED_Init();
	while(1){
		LED3_ON();
		LED2_OFF();
		delay_ms(500);
		LED3_OFF();
		LED2_ON();
		delay_ms(500);
	}
}