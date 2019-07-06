#include "sys.h" //#1


void key_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;   //定义格式为GPIO_InitTypeDef的结构体的名字为GPIO_InitStructure 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //使能PE端口时钟

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 //配置IO口的工作模式为上拉输入（该io口内部外接电阻到电源）
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //配置IO口最高的输出速率为50M
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;  //配置被选中的管脚，|表示同时被选中
  GPIO_Init(GPIOE, &GPIO_InitStructure);			        //初始化GPIOC的相应IO口为上述配置，用于按键检测
	
	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB3、PB4中部分IO口
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	
}


int key1_STATUS(void)
{
	u8 status;
	status=GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4);
	return(status);
}

int key2_STATUS(void)
{
	u8 status;
	status=GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3);
	return(status);
}

