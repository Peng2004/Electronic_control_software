#include "main.h"
#include "tim.h"

/* 编码器接口倍频数 */
#define ENCODER_MODE                           TIM_ENCODERMODE_TI12
/* 编码器物理分辨率 */
#define ENCODER_RESOLUTION                     16
/* 经过倍频之后的总分辨率 */
#if (ENCODER_MODE == TIM_ENCODERMODE_TI12)
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 4)  /* 4倍频后的总分辨率 */
#else
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 2)  /* 2倍频后的总分辨率 */
#endif
/* 减速电机减速比 */
#define REDUCTION_RATIO                        30

extern int16_t Encoder_Overflow_Count;

void Encoder_init(void);
void Encoder_Count(TIM_HandleTypeDef *htim);
