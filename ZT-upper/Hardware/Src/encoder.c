#include "encoder.h"

/* 定时器溢出次数 */
int16_t Encoder_Overflow_Count = 0;

/* 编码器初始化 */
void Encoder_init(void)
{
  __HAL_TIM_CLEAR_IT(&htim3,TIM_IT_UPDATE);
  __HAL_TIM_ENABLE_IT(&htim3,TIM_IT_UPDATE);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}
/* 编码器计数 */
void Encoder_Count(TIM_HandleTypeDef *htim)
{
  if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3))
    Encoder_Overflow_Count--;
  else
    Encoder_Overflow_Count++;
}
