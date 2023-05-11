#include "engine.h"

/* 舵机初始化 */
void Engine_init(void)
{
  //开启PWM
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}
/* 舵机位置控制 */
void Engine_UP(void)
{
  //读取舵机当前位置
  int PWM = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_4);
  //舵机上升
  for(int i = 0;i < 5;i++)
  {
    //顶端判断
    if(PWM == 105)
    {
      __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,105);
      __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,0);
    }
    else
    {
      __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,85+i*5);
    }
    Delay_ms(2500);
  }
}
void Engine_DOWN(void)
{
  //读取舵机当前位置
  int PWM = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_4);
  //舵机下降
  for(int i = 0;i < 5;i++)
  {
    //底端判断
    if(PWM == 85)
    {
      __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,85);
      __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,0);
    }
    else
    {
      __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,105-i*5);
    }
    Delay_ms(2500);
  }
}
/* 舵机位置最值化 */
void Engine_MAX(void)
{
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,105);
}
void Engine_MIN(void)
{
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,85);
}
