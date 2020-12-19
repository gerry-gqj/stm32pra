#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
//#include "myusart1.h"

int main(void)
{
	//中断分组2
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//my_usart1_init();
	//while(1);
	u8 len;
	u8 t;
	u16 times=0; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	led_init();
	uart_init(115200);
	while(1){
		if(USART_RX_STA&0x8000){					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n");
			for(t=0;t<len;t++){
				//USART_SendData(USART1,USART_RX_BUF[t]);
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else{
			times++;
			if(times%5000==0){
				printf("\r\nALIENTEK MiniSTM32开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n\r\n");
			}
			if(times%300==0)printf("请输入数据,以回车键结束\r\n");  
			if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
			delay_ms(10);   
		}
	}
}	
