#include "stm32f10x.h"
#include "myusart1.h"

void my_usart1_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//IO��ʹ��|��������ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	//IO�ڳ�ʼ��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; //���ù����������ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING; //��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//���ڳ�ʼ��
	USART_InitStructure.USART_BaudRate=115200; //������
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //Ӳ������
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx; //�����������
	USART_InitStructure.USART_Parity=USART_Parity_No; //����żУ��
	USART_InitStructure.USART_StopBits=USART_StopBits_1; //ֹͣλΪ1
	USART_InitStructure.USART_WordLength=USART_WordLength_8b; //�ַ�������Ϊ8
	USART_Init(USART1,&USART_InitStructure);
	
	//����ʹ��
	USART_Cmd(USART1,ENABLE);
	
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//���������ж�
	
	//�ж����ȼ�����
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
	if(USART_GetITStatus(USART1,USART_IT_RXNE))//��ȡ�ж�״̬��־λ
	{
		res=USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
	
}*/

