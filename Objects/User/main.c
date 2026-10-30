#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "KEY.h"
#include "OLED.h"
#include "Serial.h"


uint8_t KeyNum;
int main(void)
{
	LED_Init();
	Key_Init();
	OLED_Init();
	Serial_Init();
	
	
	OLED_ShowString(1,1,"Oliver Qian");
	OLED_ShowString(2,1,"Frank Underwood");
	
	Serial_SendByte(0x41);
	
	while(1)
	{
		
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			LED1_ON();
			LED2_TURN();
		}
			
		if(KeyNum == 2)
			LED1_OFF();
	}	
}
