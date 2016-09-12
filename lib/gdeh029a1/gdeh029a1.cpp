#include <gde.h>
#include "gdeh029a1.h"

// GDEH029A1
// SSD1608

unsigned char GDOControl[]={0x01,0x27,0x01,0x00}; //for 2.9inch
unsigned char softstart[]={0x0c,0xd7,0xd6,0x9d};
unsigned char Rambypass[] = {0x21,0x8f};		// Display update
unsigned char MAsequency[] = {0x22,0xf0};		// clock
unsigned char GDVol[] = {0x03,0x00};	// Gate voltage +15V/-15V
unsigned char SDVol[] = {0x04,0x0a};	// Source voltage +15V/-15V
unsigned char VCOMVol[] = {0x2c,0xa8};	// VCOM 7c
unsigned char BOOSTERFB[] = {0xf0,0x1f};	// Source voltage +15V/-15V
unsigned char DummyLine[] = {0x3a,0x1a};	// 4 dummy line per gate
unsigned char Gatetime[] = {0x3b,0x08};	// 2us per line
unsigned char BorderWavefrom[] = {0x3c,0x33};	// Border
unsigned char RamDataEntryMode[] = {0x11,0x01};	// Ram data entry mode

void writeLUT(bool fast = false)
{
  unsigned char i;
  writeCommand(0x32);//write LUT register
  for (i = 0; i < 30; i++)
  {
    if (fast) {
      writeData(LUTDefault_part[i]);
    } else {
      writeData(LUTDefault_full[i]);
    }
  }
}

void initDisplay(bool fast = false)
{
  resetDisplay();
  writeStream(GDOControl, sizeof(GDOControl)); // Pannel configuration, Gate selection
  writeStream(softstart, sizeof(softstart));   // X decrease, Y decrease
  writeStream(VCOMVol, sizeof(VCOMVol));       // VCOM setting
  writeStream(DummyLine, sizeof(DummyLine));   // dummy line per gate
  writeStream(Gatetime, sizeof(Gatetime));     // Gage time setting
  writeStream(RamDataEntryMode, sizeof(RamDataEntryMode));	// X increase, Y decrease
  setRamArea(0x00,0x0f,0x27,0x01,0x00,0x00);	// X-source area,Y-gage area
  setRamPointer(0x00,0xC7,0x00);	// set ram

  writeLUT(fast);
}

void displayImage(const unsigned char *picture)
{
  setRamPointer(0x00,0x27,0x01);	// set ram
	writeDispRam(128, 296, picture);
	updateDisplay();
}

void setRamArea(unsigned char Xstart,unsigned char Xend,
						    unsigned char Ystart,unsigned char Ystart1,
                unsigned char Yend,unsigned char Yend1)
{
  unsigned char RamAreaX[3];	// X start and end
	unsigned char RamAreaY[5]; 	// Y start and end
	RamAreaX[0] = 0x44;	// command
	RamAreaX[1] = Xstart;
	RamAreaX[2] = Xend;
	RamAreaY[0] = 0x45;	// command
	RamAreaY[1] = Ystart;
	RamAreaY[2] = Ystart1;
	RamAreaY[3] = Yend;
  RamAreaY[4] = Yend1;
	writeStream(RamAreaX, sizeof(RamAreaX));
	writeStream(RamAreaY, sizeof(RamAreaY));
}

void setRamPointer(unsigned char addrX,unsigned char addrY,unsigned char addrY1)
{
  unsigned char RamPointerX[2];	// default (0,0)
	unsigned char RamPointerY[3];
	RamPointerX[0] = 0x4e;
	RamPointerX[1] = addrX;
	RamPointerY[0] = 0x4f;
	RamPointerY[1] = addrY;
	RamPointerY[2] = addrY1;
	writeStream(RamPointerX, sizeof(RamPointerX));
	writeStream(RamPointerY, sizeof(RamPointerY));
}

void updateDisplay(void)
{
	writeCMD_p1(0x22,0xc7);
	writeCommand(0x20);
	writeCommand(0xff);
}

 void updateDisplayPartial(void)
{
	writeCMD_p1(0x22,0x04);
	//EPD_W21_WriteCMD_p1(0x22,0x08);
	writeCommand(0x20);
	writeCommand(0xff);
}

void powerOn(void)
{
	writeCMD_p1(0x22,0xc0);
	writeCommand(0x20);
//	writeCommand(0xff);
}

void powerOff(void)
{
  writeCMD_p1(0x22,0xc3);
	writeCommand(0x20);
//  writeCommand(0xff);
}

void partialDisplay(unsigned char RAM_XST,unsigned char RAM_XEND,unsigned char RAM_YST,unsigned char RAM_YST1,unsigned char RAM_YEND,unsigned char RAM_YEND1)
 {
   setRamArea(RAM_XST,RAM_XEND,RAM_YST,RAM_YST1,RAM_YEND,RAM_YEND1);  	/*set w h*/
   setRamPointer (RAM_XST,RAM_YST,RAM_YST1);		 /*set orginal*/
 }

// Currently unused functions

void writeRam(void)
{
	writeCommand(0x24);
}

void enableChargepump(void)
{
	writeCMD_p1(0xf0,0x8f);
	writeCMD_p1(0x22,0xc0);
	writeCommand(0x20);
	writeCommand(0xff);
}

void disableChargepump(void)
{
	writeCMD_p1(0x22,0xf0);
	writeCommand(0x20);
	writeCommand(0xff);
}
