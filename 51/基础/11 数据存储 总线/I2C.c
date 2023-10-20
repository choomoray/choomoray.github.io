#include <REGX52.H>
#include "I2C.h"

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;


void I2C_Start(void)
{	
	I2C_SDA = 1;	// 初始化SDA, SCL
	I2C_SCL = 1;
	
	I2C_SDA = 0;	// 开始
	I2C_SCL = 0;
}

void I2C_Stop(void)
{
	I2C_SDA = 0;	// 结束
	
	I2C_SCL = 1;	// 初始化SDA, SCL
	I2C_SDA = 1;
}


void I2C_SendByte(unsigned char byte)
{
	unsigned char i;
	
	for(i=0;i<8;i++)
	{
		I2C_SDA=byte&(0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}	
}

unsigned char I2C_ReceiveByte(void)
{
	unsigned char byte=0x00, i;
	
	I2C_SDA = 1;
	
	for(i=0;i<8;i++)
	{
		I2C_SCL = 1;
		if (I2C_SDA){byte|=(0x80>>i);}	// 如果是1，把最高位置为1，否则默认为0不执行
		I2C_SCL = 0;
	}	
	return byte;
}

void I2C_SendAck(unsigned char ask)
{
	I2C_SDA = ask;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

unsigned char I2C_ReceiveAck(void)
{
	unsigned char ask;
	
	I2C_SDA = 1;
	I2C_SCL = 1;
	ask = I2C_SDA;	
	I2C_SCL = 0;
	return ask;
}