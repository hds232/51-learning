#include <INTRINS.H>
#include "I2C.h"

#define AT24C02_Address 0xA0

void Delay(int time)
{
	unsigned char data i, j;
	while(time--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void AT24C02_WriteByte(unsigned char Address, Data)
{
	I2C_Start();
	I2C_SendByte(AT24C02_Address);
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
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_Address);
	I2C_ReceiveAck();
	I2C_SendByte(Address);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(AT24C02_Address | 0x01);
	I2C_ReceiveAck();
	Data = I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
