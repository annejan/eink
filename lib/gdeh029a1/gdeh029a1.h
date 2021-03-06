#ifndef GDE_DRIVER_H
#define GDE_DRIVER_H
#define GDEH029A1

#include <Arduino.h>

void writeLUT(bool fast);
void initDisplay(bool fast);
void displayImage(const unsigned char *picture, bool partial = false);
void setRamArea(unsigned char Xstart,unsigned char Xend,
						    unsigned char Ystart,unsigned char Ystart1,
								unsigned char Yend,unsigned char Yend1);
void setRamPointer(unsigned char addrX,unsigned char addrY,unsigned char addrY1);
void partialDisplay(unsigned char RAM_XST,unsigned char RAM_XEND,unsigned char RAM_YST,
										unsigned char RAM_YST1,unsigned char RAM_YEND,unsigned char RAM_YEND1);
void updateDisplay(void);
void updateDisplayPartial(void);
void writeRam(void);
void powerOff(void);
void powerOn(void);

const unsigned char LUTDefault_part[30] = {
/*	0x00,0x00,0x00,0x18,
	0x18,0x18,0x18,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x40,0x14,0x34,0x01,
	0x00,0x00,0x00,0x00,
	0x00,0x00,
*/
 0x10 //C221 25C partial update waveform
,0x18
,0x18
,0x08
,0x18
,0x18
,0x08
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x13
,0x14
,0x44
,0x12
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00

};

const unsigned char LUTDefault_full[30] = {
/*	0x11,0x11,0x10,0x02,	// full
	0x02,0x22,0x22,0x22,
	0x22,0x22,0x51,0x51,
	0x55,0x88,0x08,0x08,
    0x88,0x88,0x00,0x00,
	0x34,0x23,0x12,0x21,
	0x24,0x28,0x22,0x21,
	0xA1,0x01
*/
 0x02 //C221 25C Full update waveform
,0x02
,0x01
,0x11
,0x12
,0x12
,0x22
,0x22
,0x66
,0x69
,0x69
,0x59
,0x58
,0x99
,0x99
,0x88
,0x00
,0x00
,0x00
,0x00
,0xF8
,0xB4
,0x13
,0x51
,0x35
,0x51
,0x51
,0x19
,0x01
,0x00
	};

#endif
