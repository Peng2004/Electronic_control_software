#include "stepper.h"

/* ���������ʼ�� */
void Stepper_init(void)
{
  //����PWM
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
  //�����������ѻ�״̬
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
}
/* �������ʧ�� */
void Stepper_Disable(void)
{
  //����PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,0);
}
/* �������λ�ÿ��� */
void Stepper_UP(void)
{
  //���������ת
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
  //����PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,900);
}
void Stepper_DOWN(void)
{
  //���������ת
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
  //����PWM
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,900);
}
