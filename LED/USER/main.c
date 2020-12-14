#include "led.h"
#include "delay.h"

int main()
{
	led_init();
	delay_init();
	
	while(1){
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
		delay_ms(300);
		
		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		delay_ms(300);
	}
}
