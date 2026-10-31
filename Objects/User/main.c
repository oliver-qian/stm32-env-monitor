#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "KEY.h"
#include "OLED.h"
#include "Serial.h"
#include "dht11.h"
#include "delay.h"
/*************************************************************************
main.o   [U: LED_Init, OLED_Init, Key_GetNum ...]   ← 我要这些
led.o    [T: LED_Init, LED1_ON, LED2_TURN ...]      ← 我有这些
oled.o   [T: OLED_Init, OLED_ShowString ...]        ← 我有这些

key.o    [T: Key_Init, Key_GetNum ...]
                    ↓  链接器按名字配对
                 object.axf
**************************************************************************/

uint8_t KeyNum;
int main(void)
{
	LED_Init();
	Key_Init();
	OLED_Init();
	Serial_Init();
	DHT11_Init();
	
	OLED_ShowString(1,1,"Oliver Qian");
	OLED_ShowString(2,1,"Frank Underwood");
	
	Serial_SendByte(0x41);
	LED1_OFF();
	while(1)
	{
		
		/*
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			LED1_ON();
			LED2_TURN();
		}
			
		if(KeyNum == 2)
			LED1_OFF();
		*/
		if (DHT11_Start() == 0)
			LED1_ON();
		else
			LED1_OFF();
		
		Delay_ms(1000);

	}	
}
