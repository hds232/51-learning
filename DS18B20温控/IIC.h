#ifndef __IIC_H__
#define __IIC_H__

void I2C_Start();
void I2C_Stop();
void I2C_SendAck(bit Ack);
void I2C_ReceiveAck();
void I2C_SendByte(unsigned char Data);
unsigned char I2C_ReceiveByte();

#endif
