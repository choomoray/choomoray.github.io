#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"
void timer0_init()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
//	TH0 = 64535/256;
//	TL0 = 64535%256;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

unsigned char key(){
	unsigned char num = 0;
	if(P3_1 == 0){Delay(20);while(P3_1 == 0);Delay(20);num=1;}
	if(P3_0 == 0){Delay(20);while(P3_0 == 0);Delay(20);num=2;}
	if(P3_2 == 0){Delay(20);while(P3_2 == 0);Delay(20);num=3;}
	if(P3_3 == 0){Delay(20);while(P3_3 == 0);Delay(20);num=4;}
	return num;
}

unsigned char keynum,LEDMod=0;

void main()
{
	timer0_init();
	P2_0 = 0;
	while(1)
	{
		keynum = key();
		if (keynum){
			if(keynum == 1)
			{
				LEDMod++;
				if(LEDMod >= 2)
				{
					LEDMod=0;
				}
			}
		}
	}
}


void timer0_routine() interrupt 1
{
	static unsigned int count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;
	count++;
	if (count >= 500)	// 1秒
	{
		count = 0;
//		P2_5=~P2_5;
		if(LEDMod == 0){
			P2=_crol_(P2, 1);
		}
		if(LEDMod == 1){
			P2=_cror_(P2, 1);
		}
	}
}