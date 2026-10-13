#ifndef SOFT_I2C_H
#define SOFT_I2C_H

#include <stdint.h>

void SoftI2C_Start(void);
void SoftI2C_Stop(void);

void SoftI2C_WriteByte(uint8_t data);
uint8_t SoftI2C_ReadByte(void);

uint8_t SoftI2C_WaitAck(void);
void SoftI2C_SendAck(uint8_t ack);

#endif
