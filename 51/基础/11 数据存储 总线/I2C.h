//#ifndef _I2C_H_
//#define _I2C_H_

//void I2C_Start(void);
//void I2C_Stop(void);
//void I2C_SendByte(unsigned char byte);
//unsigned char I2C_ReceiveByte(void);
//void I2C_AskSend(unsigned char ask);
//unsigned char I2C_AckReceive(void);


//#endif

#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);
unsigned char I2C_ReceiveByte(void);
void I2C_SendAck(unsigned char AckBit);
unsigned char I2C_ReceiveAck(void);


#endif
