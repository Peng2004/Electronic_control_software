#include "motor.h"

static uint8_t  is_motor_en = 0;
/* �����ʼ�� */
void Motor_init(void)
{
  is_motor_en = 1;
  //����PWM
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_3);
}
/* ���ȡ�� */
void Motor_Extraction(int angle)
{
  float radio = (float)angle/360;
  //�����ת
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
  //λ�ÿ���
  PID_TargetSet(radio*pulse);
}
/* ����ſ� */
void Motor_AntiExtraction(int angle)
{
  float radio = (float)angle/360;
  //�����ת
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
  //λ�ÿ���
  PID_TargetSet(radio*pulse);
}
/* ���λ��ʽPID����ʵ�� */
void Motor_PID_Control(void)
{
  float   cont_val      = 0;
  int32_t Capture_Count = 0;
  
  if (is_motor_en == 1)
  {
    Capture_Count = __HAL_TIM_GET_COUNTER(&htim3) + (Encoder_Overflow_Count * 65535);
    cont_val = PID_Realize(Capture_Count);
    cont_val = (cont_val > 2000) ? 2000 : cont_val;
    __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_3,cont_val);
  }
}
