/** @file WM8960.h
*	@brief Function prototypes and defines for Wolfson (Cirrus) Wm8960 
*
*	This file contains the macros, function protypes and data structures for use 
*	in configuring and controlling the WM8960 codec.
*
*	@author Dave Renzo
	@bug No Known Bugs
*/

#ifndef WM8960_H
#define WM8960_H


/********************************* #DEFINES **********************************/

/*definitions for register addresses*/

#define LEFT_INPUT_VOULME		0x00
#define RIGHT_INPUT_VOULME		0x01
#define LOUT_1_VOLUME			0x02
#define ROUT_1_VOLUME			0x03
#define CLOCKING_1				0x04
#define ADC_DAC_CONTROL_1		0x05
#define ADC_DAC_CONTROL_2		0x06
#define AUDIO_INTERFACE_1		0x07
#define CLOCKING_2				0x08
#define	AUDIO_INTERFACE_2		0x09
#define LEFT_DAC_VOLUME			0x0A
#define RIGHT_DAC_VOLUME		0x0B
#define RESET					0x0F
#define THREE_D_CONTROL			0x10
#define ALC1					0x11
#define ALC2					0x12
#define ALC3					0x13
#define NOISE_GATE				0x14
#define LEFT_ADC_VOLUME			0x15
#define RIGHT_ADC_VOLUME		0x16
#define ADDITIONAL_CONTROL_1	0x17
#define ADDITIONAL_CONTROL_2	0x18
#define PWR_MANAGEMENT_1		0x19
#define PWR_MANAGEMENT_2		0x1A
#define ADDITIONAL_CONTROL_3	0x1B
#define ANTI_POP_1				0x1C
#define	ANTI_POP_2				0x1D
#define ADCL_SIGNAL_PATH		0x20
#define ADCR_SIGNAL_PATH		0x21
#define L_OUTMIX_1				0x22
#define	RIGHT_OUT_MIX_2			0x25
#define MONO_OUT_MIX_1			0x26
#define MONO_OUT_MIX_2			0x27
#define LOUT_2_VOLUME			0x28
#define ROUT_2_VOLUME			0x29
#define MONO_OUT_VOLUME			0x2A
#define INPUT_BOOST_MIXER_1		0x2B
#define INPUT_BOOST_MIXER_2		0x2C
#define BYPASS_1				0x2D
#define BYPASS_2				0x2E
#define PWR_MANAGEMENT_3		0x2F
#define ADDITIONAL_CONTROL_4	0x30
#define CLASS_D_CONTROL_1		0x31
#define CLASS_D_CONTROL_3		0x33
#define PLL_N					0x34
#define PLL_K_1					0x35
#define PLL_K_2					0x36
#define PLL_K_3					0x37
/*end register addresses*/

#define DEVICE_ADDRESS			0x34
#define DATA_MASK				0x1FF


enum bitDepth
{
	BD_16_BIT,
	BD_20_BIT,
	BD_24_BIT,
	BD_32_BIT
};

/*Function Prototypes*/
unsigned short createControlPacket(unsigned char regAddress, unsigned short dataBits);
unsigned short audioDataFormatSetup(enum bitDepth bd);


#endif