#include "pid.h"

float PID_P(float target, float current, float kp)
{
    float error = target - current;
    float output = kp * error;

    return output;
}
