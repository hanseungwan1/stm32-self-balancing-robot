#ifndef ATTITUDE_H
#define ATTITUDE_H

#include <stdint.h>

float Attitude_GetAccelAngle(int16_t accel_y, int16_t accel_z);
float Attitude_GetGyroRate(int16_t gyro_x, float bias);
float Attitude_IntegrateGyro(float previous_angle,
                             float gyro_rate,
                             float dt);
float Attitude_ComplementaryFilter(float previous_angle,
                                   float gyro_rate,
                                   float accel_angle,
                                   float dt);

#endif
