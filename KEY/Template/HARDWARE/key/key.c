#include "key.h"
#include "delay.h"

void key_init()
{

  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
  // GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

u8 key_scan(u8 mode)
{
  static u8 key_up = 1;
  if (mode)
  {
    key_up = 1;
  }
  if (key_up && (KEY0 == 0 || KEY1 == 0 || WK_UP == 1))
  {
    delay_ms(10);
    key_up = 0;
    if (KEY0 == 0)
    {
      return KEY0_PRES;
    }
    else if (KEY1 == 0)
    {
      return KEY1_PRES;
    }
    else if (WK_UP == 1)
    {
      return WKUP_PRES;
    }
  }
  else if (KEY0 == 1 && KEY1 == 1 && WK_UP == 0)
    key_up = 1;
  {
    return 0;
  }
}
