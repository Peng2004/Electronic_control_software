#include "engine.h"

/* �����ʼ�� */
void Engine_init(void)
{
  //����PWM
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}
/* ���λ�ÿ��� */
void Engine_UP(void)
{
  //��ȡ�����ǰλ��
  int PWM = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_4);
  //�������
  for(int i = 0;i < 5;i++)
  {
    //�����ж�
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
  //��ȡ�����ǰλ��
  int PWM = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_4);
  //����½�
  for(int i = 0;i < 5;i++)
  {
    //�׶��ж�
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
/* ���λ����ֵ�� */
void Engine_MAX(void)
{
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,105);
}
void Engine_MIN(void)
{
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,85);
}
