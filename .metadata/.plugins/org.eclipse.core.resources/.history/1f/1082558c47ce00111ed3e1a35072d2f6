#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>

uint8_t MPU6050_ReadReg(uint8_t reg);
void MPU6050_WriteReg(uint8_t reg, uint8_t data);
void MPU6050_ReadBytes(uint8_t reg, uint8_t *buffer, uint8_t len);
float MPU6050_CalibrateGyroX(void);

#endif
