#include "stepper.h"

/* 步进电机初始化 */
void Stepper_init(void)
{
  //开启PWM
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
  //解除步进电机脱机状态
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
}
/* 步进电机失能 */
void Stepper_Disable(void)
{
  //设置PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,0);
}
/* 步进电机位置控制 */
void Stepper_UP(void)
{
  //步进电机正转
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
  //设置PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,900);
}
void Stepper_DOWN(void)
{
  //步进电机反转
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
  //设置PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,900);
}
