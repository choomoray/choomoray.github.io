#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include <REGX52.H>

/* 引脚定义 */

// DS1302
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

// Buzzer
sbit Buzzer = P2^5;

/* 寄存器写入地址/指令定义 */

// DS1302
#define DS1302_SECOND		0x80	// 秒
#define DS1302_MINUTE		0x82	// 分
#define DS1302_HOUR			0x84	// 时
#define DS1302_DAY			0x86	// 天
#define DS1302_MONTH		0x88	// 月
#define DS1302_WEEK			0x8A	// 周
#define DS1302_YEAR			0x8C	// 年
#define DS1302_WP			0x8E	// 写保护


#endif