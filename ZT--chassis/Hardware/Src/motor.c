#include "motor.h"

static uint16_t    dutyfactor = 0;
static uint8_t     is_motor_en = 0;
/* 电机初始化 */
void Motor_init(void)
{
  is_motor_en = 1;
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}
/* 电机失能 */
void Motor_Disable(void)
{
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
}
/* 设置电机速度 */
void Motor_SpeedSet(uint16_t v)
{
  v = (v > 2000) ? 2000 : v;
  dutyfactor =v;
  
  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,dutyfactor);
  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,dutyfactor);
  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,dutyfactor);
  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,dutyfactor);
}
/* 正转 */
void Motor_Colckwise_Rotation(int num)
{
    switch(num)
    {
        case 1:
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);
        break;
        case 2:
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);
        break;
        case 3:
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
        break;
        case 4:
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
        break;
    }
}
/* 反转 */
void Motor_AntiColckwise_Rotation(int num)
{
    switch(num)
    {
        case 1:
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);
        break;
        case 2:
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);
        break;
        case 3:
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
        break;
        case 4:
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
        break;
    }
}
/* 前进 */
void Motor_UP(int PWM)
{
    Motor_Colckwise_Rotation(1);
    Motor_Colckwise_Rotation(2);
    Motor_Colckwise_Rotation(3);
    Motor_Colckwise_Rotation(4);
    PID_TargetSet(PWM);
}
/* 后退 */
void Motor_DOWN(int PWM)
{
    Motor_AntiColckwise_Rotation(1);
    Motor_AntiColckwise_Rotation(2);
    Motor_AntiColckwise_Rotation(3);
    Motor_AntiColckwise_Rotation(4);
    PID_TargetSet(PWM);
}
/* 左行 */
void Motor_LEFT(int PWM)
{
    Motor_Colckwise_Rotation(1);
    Motor_AntiColckwise_Rotation(2);
    Motor_AntiColckwise_Rotation(3);
    Motor_Colckwise_Rotation(4);
    PID_TargetSet(PWM);
}
/* 右行 */
void Motor_RIGHT(int PWM)
{
    Motor_AntiColckwise_Rotation(1);
    Motor_Colckwise_Rotation(2);
    Motor_Colckwise_Rotation(3);
    Motor_AntiColckwise_Rotation(4);
    PID_TargetSet(PWM);
}
/* 自转 */
void Motor_Colckwise(int PWM)
{
    Motor_Colckwise_Rotation(1);
    Motor_Colckwise_Rotation(2);
    Motor_AntiColckwise_Rotation(3);
    Motor_AntiColckwise_Rotation(4);
    PID_TargetSet(PWM);
}
void Motor_AntiColckwise(int PWM)
{
    Motor_AntiColckwise_Rotation(1);
    Motor_AntiColckwise_Rotation(2);
    Motor_Colckwise_Rotation(3);
    Motor_Colckwise_Rotation(4);
    PID_TargetSet(PWM);
}
/* 电机位置式PID控制实现 */
void Motor_PID_Control(int num)
{
  float   cont_val      = 0;
  int32_t Capture_Count = 0;
  int32_t Last_Count    = 0;
  int32_t actual_speed  = 0;
  int8_t  x = num+1;
  if (is_motor_en == 1)
  {
    if(x == 2)
        Capture_Count = __HAL_TIM_GET_COUNTER(&htim2) + (Encoder_Overflow_Count * 65535);
    else if(x == 3)
        Capture_Count = __HAL_TIM_GET_COUNTER(&htim3) + (Encoder_Overflow_Count * 65535);
    else if(x == 4)
        Capture_Count = __HAL_TIM_GET_COUNTER(&htim4) + (Encoder_Overflow_Count * 65535);
    else if(x == 5)
        Capture_Count = __HAL_TIM_GET_COUNTER(&htim5) + (Encoder_Overflow_Count * 65535);
    actual_speed  = ((float)(Capture_Count - Last_Count) / ENCODER_TOTAL_RESOLUTION / REDUCTION_RATIO) / (GET_TIM7_PERIOD()/1000.0/60.0);
    Last_Count    = Capture_Count;
    cont_val      = PID_Realize(actual_speed);
    cont_val = (cont_val > 2000) ? 2000 : cont_val;
    Motor_SpeedSet(cont_val);
  }
}
/* 电机运动控制 */
void Motor_Control(void)
{
    switch(cmd)
    {
        //电机失能（防止失控）
        case '0':
            Motor_Disable();
        break;
        //前进
        case '1':
            Motor_UP(680);
        break;
        //左行
        case '2':
            Motor_LEFT(680);
        break;
        //后退
        case '3':
            Motor_DOWN(680);
        break;
        //右行
        case '4':
            Motor_RIGHT(680);
        break;
        //顺时针自转
        case '5':
            Motor_Colckwise(680);
        break;
        //逆时针自转
        case '6':
            Motor_AntiColckwise(680);
        break;
    }
}
