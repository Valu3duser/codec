#include "WM8960.h"

unsigned short createControlPacket(unsigned char regAddress, unsigned short dataBits)
{
	unsigned short packet = 0x00;

	packet |= (regAddress << 13);
	packet |= dataBits;
	//packet |= (dataBits << 9);

	return packet;
}

/**
*	@brief Setup the audio data Format register
*
*	This funtion allows a selectable word length and sets the following 
*	configuration:
*
*	ALRSWAP		: 0 = Output left and right data as normal
*	BCLKINV		: 0 = BCLK not inverted
*	MS			: 0 = Enable slave mode
*	DLRSWAP		: 0 = Output left and right data as normal
*	LRP			: 0 = normal LRCLK polarity
*	WL[1:0]		: Word length is selectable via passed argument
*	Format[1:0]	: 10 = I2S
*
*	@param enum bitDepth	Slect between 16, 20, 24 and 32 bits
*
*	@returns unsigned short	represents the register address and the 9 bit 
*				configuration register
*/
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
			reg |= 0x04;
			break;
		}
		case BD_24_BIT:
		{
			reg |= 0x08;
			break;
		}
		case BD_32_BIT:
		{
			reg |= 0x0C;
			break;
		}
	}
	//i2s mode
	reg |= 0x02;

	return createControlPacket(AUDIO_INTERFACE_1,reg);
}

