#include <REGX52.H>

void Delay(unsigned int ms);

void main(){	
	unsigned char LEDNUM = 0;
	P2 = ~0x01;
	while(1){		
		if (P3_0 == 0){
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			LEDNUM++;
			if (LEDNUM >= 8){
				LEDNUM = 0;
			}
			P2 = ~(0x01<<LEDNUM);
		}else if (P3_1 == 0){
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			
			if (LEDNUM == 0){
				LEDNUM = 7;
			}else{
				LEDNUM--;
			}
			/*
			LED只亮一个，所以初始状态为亮一个的最小值
			根据LEDNUM记录的亮点位置来对P2进行位操作
			然后又因为高低电平的缘故，需要对P2进行取反，让其单独亮一个
			*/
			P2 = ~(0x01<<LEDNUM);
		}
	}
}

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}
