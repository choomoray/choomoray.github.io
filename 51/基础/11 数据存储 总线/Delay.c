#include "Delay.h"

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)	//@12.000MHz
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
