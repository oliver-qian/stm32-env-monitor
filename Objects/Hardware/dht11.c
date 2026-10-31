#include "stm32f10x.h"                  // Device header
#include "dht11.h"
#include "delay.h"

void DHT11_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = DHT11_PIN; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;       //开漏,不是推挽因为是单总线
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DHT11_PORT, &GPIO_InitStructure); 

    DHT11_OUT(1);  //开始等待DHT11_Start让dht11接受            
}


uint8_t static DHT11_WaitLevel(uint8_t level,uint8_t timeout_us)		//level是要等timeout_us后变成的
{
	while(DHT11_IN() !=level)		//读取是否和等待的电平一致，当时间耗尽返回1，当变为等待的电平且时间为耗尽返回0
	{
		if(timeout_us == 0)
			{
				return 1;
			}
			
		timeout_us--;
		Delay_us(1);
	}
	return 0; 
}
	
uint8_t DHT11_Check(void)
{
	if (DHT11_WaitLevel(0, 100))  return 1;
    if (DHT11_WaitLevel(1, 100))  return 1;
    if (DHT11_WaitLevel(0, 100))  return 1;

    return 0;
}


uint8_t DHT11_Start(void)
{
	DHT11_OUT(0);
    Delay_ms(20);
    DHT11_OUT(1);
    Delay_us(30);
	
	return DHT11_Check();
}


	
void DHT11_GetData()
{

	
}

void DHT11_ReadData()
{

}
