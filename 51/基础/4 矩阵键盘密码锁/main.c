#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char key;
unsigned int Password,Count;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"INPUT PASSWORD");
		
	
	
	while(1){
		key = MatrixKey();
		if(key){
			// 判断按键按下才刷新LCD显示，不然会随着循环一直被0覆盖
			if (key <= 10)
			{
				if(Count < 4)
				{
					Password *= 10;
					Password += key%10;
					Count++;
				}				
			}
			if (key == 11)
			{
				// 确认密码
				if(Password == 9527 && Count == 4){
					LCD_ShowString(2,6,"SUCCESS");
				}else{
					LCD_ShowString(2,6,"ERROR  ");
					Password = 0;
					Count = 0;
				}
			}
			if (key == 12)
			{
				//重置密码
				Password = 0;
				Count = 0;
				LCD_ShowString(2,6,"             ");
			}
			LCD_ShowNum(2,1,Password,4);
		}
		
	}
}