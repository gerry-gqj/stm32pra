#ifndef __KEY__
#define __KEY__
#include "sys.h"

//#define KEY0 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
//#define KEY1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)
//#define WK_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

//Î»´ø²Ù×÷
#define KEY0 PCin(5)
#define KEY1 PAin(15)
#define WK_UP PAin(0)

#define KEY0_PRES 1
#define KEY1_PRES 2
#define WKUP_PRES 3

void key_init(void);
u8 key_scan(u8 mode);

#endif
