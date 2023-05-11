#include "pid.h"

//����ȫ�ֱ���
_pid pid;

/* PID������ʼ�� */
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
/* ����Ŀ��ֵ */
void PID_TargetSet(float temp_val)
{
  pid.target_val = temp_val;
}
/* ��ȡĿ��ֵ */
float PID_TargetGet(void)
{
  return pid.target_val;
}
/* ���ñ��������֡�΢��ϵ�� */
void PID_Set(float p, float i, float d)
{
    pid.Kp = p;
    pid.Ki = i;
    pid.Kd = d;
}
/* λ��ʽPID�㷨ʵ�� */
float PID_Realize(float actual_val)
{
    pid.err=pid.target_val-actual_val;
    pid.integral+=pid.err;
    pid.actual_val=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);
    pid.err_last=pid.err;

    return pid.actual_val;
}
