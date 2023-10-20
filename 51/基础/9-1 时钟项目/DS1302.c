#include "DS1302.h"

char DS1302_Time[] = {23, 12, 31, 23, 59, 57, 29};

/**
  * @brief  DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
	DS1302_SetTime();
}

/**
  * @brief  向DS1302写入数据
  * @param  Command	命令字
  * @param  Data	写入的数据
  * @retval 无
  */
void DS1302_WriteByte(unsigned char Command, Data)
{
	unsigned char i;
	DS1302_CE = 1;
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Data&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}	
	DS1302_CE = 0;
}

/**
  * @brief  DS1302读一个字节
  * @param  Command	指令
  * @retval 读出的数据
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
	
	Command |= 0x01;	
	DS1302_CE = 1;
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	
	DS1302_IO = 0;
	DS1302_CE = 0;
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP, 0x00);
	DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DAY, DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE, DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND, DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_WEEK, DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP, 0x80);
}

void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;//BCD码转十进制后读取
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_WEEK);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}