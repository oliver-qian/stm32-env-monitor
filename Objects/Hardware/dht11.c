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

    DHT11_OUT(1);              
}


void DHT11_Start()
{
	DHT11_OUT(0);      /* ① 主机拉低总线 */
    Delay_ms(20);      /* ② 保持 ≥18ms，DHT11 才认这是起始信号 */
    DHT11_OUT(1);      /* ③ 释放总线（开漏，靠 10k 上拉拉高） */
    Delay_us(30);      /* ④ 保持高 20~40us，等 DHT11 回应 */
}


void DHT11_GetData()
{

}
