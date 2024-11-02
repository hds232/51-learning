#ifndef __BUS_H__
#define __BUS_H__

void BUS_Init();
void BUS_SendByte(unsigned char Data);
unsigned char BUS_ReceiveByte();

#endif
