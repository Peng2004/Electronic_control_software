#include "main.h"
#include "tim.h"
#include "stm32f1xx_it.h"
#include "usart.h"
#include "encoder.h"
#include "pid.h"

#define GET_TIM7_PERIOD()      ((__HAL_TIM_GET_AUTORELOAD(&htim7)+1)/100.0f)
/* 电机方向控制枚举 */
typedef enum
{
  MOTOR_FWD = 0,
  MOTOR_REV,
}motor_dir_t;

void Motor_init(void);
void Motor_Disable(void);
void Motor_SpeedSet(uint16_t v);
void Motor_Colckwise_Rotation(int num);
void Motor_AntiColckwise_Rotation(int num);
void Motor_UP(int PWM);
void Motor_DOWN(int PWM);
void Motor_LEFT(int PWM);
void Motor_RIGHT(int PWM);
void Motor_Colckwise(int PWM);
void Motor_AntiColckwise(int PWM);
void Motor_PID_Control(int num);
void Motor_Control(void);
