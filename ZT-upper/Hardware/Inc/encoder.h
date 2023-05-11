#include "main.h"
#include "tim.h"

/* �������ӿڱ�Ƶ�� */
#define ENCODER_MODE                           TIM_ENCODERMODE_TI12
/* ����������ֱ��� */
#define ENCODER_RESOLUTION                     13
/* ������Ƶ֮����ֱܷ��� */
#if (ENCODER_MODE == TIM_ENCODERMODE_TI12)
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 4)  /* 4��Ƶ����ֱܷ��� */
#else
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 2)  /* 2��Ƶ����ֱܷ��� */
#endif
/* ���ٵ�����ٱ� */
#define REDUCTION_RATIO                        45
/* ���һȦ���Բ����������� */
#define pulse                                  ENCODER_TOTAL_RESOLUTION*REDUCTION_RATIO
extern int16_t Encoder_Overflow_Count;

void Encoder_init(void);
void Encoder_Count(TIM_HandleTypeDef *htim);
