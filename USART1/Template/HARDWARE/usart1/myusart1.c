#include "stm32f10x.h"
#include "myusart1.h"

void my_usart1_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//IO口使能|串口外设时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	//IO口初始化
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; //复用功能推挽输出模式
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING; //浮空输入
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//串口初始化
	USART_InitStructure.USART_BaudRate=115200; //波特率
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //硬件控制
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx; //输入输出设置
	USART_InitStructure.USART_Parity=USART_Parity_No; //无奇偶校验
	USART_InitStructure.USART_StopBits=USART_StopBits_1; //停止位为1
	USART_InitStructure.USART_WordLength=USART_WordLength_8b; //字符串长度为8
	USART_Init(USART1,&USART_InitStructure);
	
	//串口使能
	USART_Cmd(USART1,ENABLE);
	
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启接收中断
	
	//中断优先级管理
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);	
}

/*
void USART1_IRQHandler(void)
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))//获取中断状态标志位
	{
		res=USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
	
}*/

