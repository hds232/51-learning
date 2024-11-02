#include "IIC.h"
#include "Delay.h"

void AT24C02_WriteByte(unsigned char Address, Data)
{
	I2C_Start();
	I2C_SendByte(0xA0);
	I2C_ReceiveAck();
	I2C_SendByte(Address);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
	Delay(5);
}

unsigned char AT24C02_ReadByte(unsigned char Address)
{
	unsigned char Data = 0x00;
	I2C_Start();
	I2C_SendByte(0xA0);
	I2C_ReceiveAck();
	I2C_SendByte(Address);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(0xA1);
	I2C_ReceiveAck();
	Data = I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
