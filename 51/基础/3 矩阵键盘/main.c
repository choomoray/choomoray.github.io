#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keyNum;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"INPUT PASSWORD");
		
	
	
	while(1){
		keyNum = MatrixKey();
		if(keyNum){
			// 判断按键按下才刷新LCD显示，不然会随着循环一直被0覆盖
			LCD_ShowNum(2,1,keyNum,2);
		}
	}
}