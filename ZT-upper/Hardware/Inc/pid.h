#ifndef __PID_H
#define __PID_H

#include "main.h"
#include "usart.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct
{
    float target_val;
    float actual_val;
    float err;
    float err_last;
    float Kp,Ki,Kd;
    float integral;
}_pid;

extern void  PID_init(void);
extern void  PID_TargetSet(float temp_val);
extern float PID_TargetGet(void);
extern void  PID_Set(float p, float i, float d);
extern float PID_Realize(float actual_val);

#endif
