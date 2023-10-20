#include "Delay.h"

/**
  * @brief  延时函数
  * @param  需要延长的时间（单位ms）
  * @retval 无
  */
void Delay(unsigned int ms)
{
	unsigned char i, j;
	while(ms--){	//@11.0592MHz	
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}	
}