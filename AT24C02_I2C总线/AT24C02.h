#ifndef __AT24C02_H__
#define __AT24C02_H__

void Delay(int time);
void AT24C02_WriteByte(unsigned char Address, Data);
unsigned char AT24C02_ReadByte(unsigned char Address);

#endif
