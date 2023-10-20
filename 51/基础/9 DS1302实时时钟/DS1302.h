#ifndef _DS1302_H_
#define _DS1302_H_

#include <REGX52.H>

#define DS1302_SECOND	0x80
#define DS1302_MINUTE	0x82
#define DS1302_HOUR		0x84
#define DS1302_DAY		0x86
#define DS1302_MONTH	0x88
#define DS1302_WEEK		0x8A
#define DS1302_YEAR		0x8C
#define DS1302_WP		0x8E	// 写入保护

sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

// 年月日 时分秒 星期
extern unsigned char DS1302_Time[7];

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command, Data);
unsigned char DS1302_ReadByte(unsigned char Command);
#endif