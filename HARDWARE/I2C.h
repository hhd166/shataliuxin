#include "stm32f10x.h"

#define I2C1_SLAVE_ADDRESS7    0x3A
void I2C_INIT_GPIO(void);//IIC的IO初始化
void I2C_INIT(void);//IIC初始化
void I2C_WriteByte(unsigned char id,unsigned char write_address,unsigned char byte);//I2C写数据
unsigned char I2C_ReadByte(unsigned char  id, unsigned char read_address);//I2C读数据
