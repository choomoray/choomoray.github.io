#ifndef _DS1302_H_
#define _DS1302_H_

#include "include.h"

extern char DS1302_Time[7];

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command, Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime(void);
void DS1302_ReadTime(void);

#endif