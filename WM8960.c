#include "WM8960.h"

unsigned short createControlPacket(unsigned char regAddress, unsigned short dataBits)
{
	unsigned short packet = 0x00;

	packet |= (regAddress << 9);
	packet |= dataBits;
	//packet |= (dataBits << 9);

	return packet;
}

unsigned short audioDataFormatSetup(enum bitDepth bd)
{
	unsigned short reg = 0x0000;

	switch (bd)
	{
		case BD_16_BIT:
		{
			//00 for 16 bit
			break;
		}
		case BD_20_BIT:
		{
			reg |= (1 << 3);
			break;
		}
		case BD_24_BIT:
		{
			reg |= (1 << 4);
			break;
		}
		case BD_32_BIT:
		{
			reg |= (1 << 3);
			reg |= (1 << 4);
			break;
		}
	}

	//i2s mode
	reg |= (1 << 2);

	return reg;
}