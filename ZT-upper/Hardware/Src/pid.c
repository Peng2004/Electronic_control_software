#include "pid.h"

//定义全局变量
_pid pid;

/* PID参数初始化 */
void PID_init(void)
{
    pid.target_val=0.0;
    pid.actual_val=0.0;
    pid.err=0.0;
    pid.err_last=0.0;
    pid.integral=0.0;
    pid.Kp = 5.0;
    pid.Ki = 2.0;
    pid.Kd = 0.0;
}
/* 设置目标值 */
void PID_TargetSet(float temp_val)
{
  pid.target_val = temp_val;
}
/* 获取目标值 */
float PID_TargetGet(void)
{
  return pid.target_val;
}
/* 设置比例、积分、微分系数 */
void PID_Set(float p, float i, float d)
{
    pid.Kp = p;
    pid.Ki = i;
    pid.Kd = d;
}
/* 位置式PID算法实现 */
float PID_Realize(float actual_val)
{
    pid.err=pid.target_val-actual_val;
    pid.integral+=pid.err;
    pid.actual_val=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);
    pid.err_last=pid.err;

    return pid.actual_val;
}
