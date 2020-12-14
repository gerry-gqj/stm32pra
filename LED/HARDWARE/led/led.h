#ifndef __LED__
#define __LED__

//位操作
#define LED0 PAout(8)
#define LED1 PDout(2)

//输出使能
void led_init(void);

#endif
