#include "main.h"
#include "tim.h"
#include "encoder.h"
#include "pid.h"

void Motor_init(void);
void Motor_Extraction(int angle);
void Motor_AntiExtraction(int angle);
void Motor_PID_Control(void);
