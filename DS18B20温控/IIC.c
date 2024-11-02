#include <STC89C5xRC.H>

sbit SDA = P2^0;
sbit SCL = P2^1;

void I2C_Start()
{
	SCL = 1;
	SDA = 1;
	SDA = 0;
	SCL = 0;
}

void I2C_Stop()
{
	SDA = 0;
	SCL = 1;
	SDA = 1;
}

void I2C_SendAck(bit Ack)
{
	SDA = Ack;
	SCL = 1;
	SCL = 0;
}

void I2C_ReceiveAck()
{
	SDA = 1;
	SCL = 1;
	SCL = 0;
}

void I2C_SendByte(unsigned char Data)
{
	unsigned char i;
	for(i = 0; i < 8; i ++)
	{
		SDA = Data & (0x80 >> i);
		SCL = 1;
		SCL = 0;
	}
}

unsigned char I2C_ReceiveByte()
{
	unsigned char i, Data = 0x00;
	SDA = 1;
	for(i = 0; i < 8; i++)
	{
		SCL = 1;
		if(SDA)
			Data |= (0x80 >> i);
		SCL = 0;
	}
	return Data;
}
