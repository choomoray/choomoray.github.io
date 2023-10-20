#include <REGX52.H>
#include "LCD1602.h"  
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

unsigned char mod=1, clear=1; // 暂停时间、重置时间
unsigned int sec, min, hour;
void main()
{
	timer0_init();
	LCD_init();
	LCD_ShowString(1, 1, "TIME CLOCK NOW:");
	LCD_ShowString(2, 3, ":  :");
	
	while(1){
		if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);
			if (mod == 0) {
				mod = 1;
			}else{
				mod = 0;
			}
		};
		if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);clear = 0;};
		LCD_ShowNum(2, 1, hour, 2);
		LCD_ShowNum(2, 4, min, 2);
		LCD_ShowNum(2, 7, sec, 2);
	}
}

void timer0_routine() interrupt 1
{
	static unsigned int count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;
	count++;
	
	
	if (count >= 1000){
		count = 0;
		
		if(clear == 0){
			sec = 0;
			min = 0;
			hour = 0;
			clear = 1;
		}
		if (mod == 1){			
			sec++;
		}
		if (sec >= 60){
			sec = 0;
			min++;
			if(min >= 60){
				hour++;
				min = 0;
				if(hour >=24){
					hour = 0;
				}
			}
		}		
	}
}