#ifndef INC_PID_H_
#define INC_PID_H_

float PID_P(float target, float current, float kp);
float PID_D(float gyro_rate, float kd);

#endif
