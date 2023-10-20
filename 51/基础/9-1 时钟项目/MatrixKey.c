#include <REGX52.H>
#include "MatrixKey.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval 返回按下按键的键值
  */
unsigned char MatrixKeyVolue()
{
	unsigned char KeyVolue = 0;
	
	P1 = 0x0f;
	if(P1 != 0x0f)	// 矩阵按键被按下
	{
		Delay(20);
		if(P1 != 0x0f)	// 矩阵按键被按下
		{
			P1 = 0x0f;		
			switch(P1)
			{
				case(0x07):KeyVolue = 0; break;
				case(0x0b):KeyVolue = 1; break;
				case(0x0d):KeyVolue = 2; break;
				case(0x0e):KeyVolue = 3; break;
			}
			P1 = 0xf0;		
			switch(P1)
			{
				case(0x70):KeyVolue = KeyVolue; break;
				case(0xb0):KeyVolue = KeyVolue + 4; break;
				case(0xd0):KeyVolue = KeyVolue + 8; break;
				case(0xe0):KeyVolue = KeyVolue + 12; break;
			}
			while(P1 != 0xf0)
			{
				Delay(20);
			}
		}
	}
	return KeyVolue;
}