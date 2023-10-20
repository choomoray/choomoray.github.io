#include "Buzzer.h"

/**
  * @brief  响铃
  * @param  count 响铃的频率（每秒钟响几次）
  * @retval 无
  */
void Buzzer_Bell(unsigned char count)
{
	unsigned int i;
	switch(count)
	{
		case 1:
		{
			while(1){
			for(i = 0; i < 1000; i++){
				Buzzer = !Buzzer;
				Delay(1);
			}
			}
			break;
		};
		case 2:
		{
			
			break;
		};
			
	}
		
}