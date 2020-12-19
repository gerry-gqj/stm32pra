#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
//#include "myusart1.h"

int main(void)
{
	//�жϷ���2
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
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\n�����͵���ϢΪ:\r\n");
			for(t=0;t<len;t++){
				//USART_SendData(USART1,USART_RX_BUF[t]);
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
			}
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
		}else{
			times++;
			if(times%5000==0){
				printf("\r\nALIENTEK MiniSTM32������ ����ʵ��\r\n");
				printf("����ԭ��@ALIENTEK\r\n\r\n\r\n");
			}
			if(times%300==0)printf("����������,�Իس�������\r\n");  
			if(times%30==0)LED0=!LED0;//��˸LED,��ʾϵͳ��������.
			delay_ms(10);   
		}
	}
}	
