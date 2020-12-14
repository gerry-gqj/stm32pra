#include "led.h"
#include "key.h"
#include "delay.h"

int main(){
	
	u8 t;
	led_init();
	key_init();
	delay_init();
	while(1){
		
		t=key_scan(0);
		switch(t)
		{
			case KEY0_PRES:
			LED0=!LED0;
			break;
			
			case KEY1_PRES:
			LED1=!LED1;
			break;
			
			case WKUP_PRES:
			LED0=!LED0;
			LED1=!LED1;
			break;
				
			default:
			delay_ms(10);
		}
	
	}
}
