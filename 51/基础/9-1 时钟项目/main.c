#include <REGX52.H>
#include "include.h"
#include "LCD1602.h"
#include "Delay.h"
#incldue "MatrixKey.h"
#include "DS1302.h"
#include "Buzzer.h"

unsigned char Bell;

void Timer0Init(void)		//1毫秒@11.0592MHz
{
//	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}



void main()
{
	unsigned char key, Data;
	
	// 先初始化LCD显示屏，打印不变的数据
	LCD_Init();
	DS1302_Init();
	Timer0Init();
	LCD_ShowString(1, 1, "  -  -");
	LCD_ShowString(2, 1, "  :  :");
	Bell = 1;
	while(1)
	{
		DS1302_ReadTime();//读取时间
		LCD_ShowNum(1,1,DS1302_Time[0],2);//显示年
		LCD_ShowNum(1,4,DS1302_Time[1],2);//显示月
		LCD_ShowNum(1,7,DS1302_Time[2],2);//显示日
		LCD_ShowNum(2,1,DS1302_Time[3],2);//显示时
		LCD_ShowNum(2,4,DS1302_Time[4],2);//显示分
		LCD_ShowNum(2,7,DS1302_Time[5],2);//显示秒
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned char Timer0_Count, Bell_Count;
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	Timer0_Count++;
	if (Timer0_Count > 20)
	{
		Timer0_Count = 0;
	}
	
}