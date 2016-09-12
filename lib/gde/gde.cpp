#include <Arduino.h>
#include <SPI.h>
#include "pins.h"
#include "gde.h"

void resetDisplay()
{
  digitalWrite(PIN_RESET, LOW);
  delay(1);
  digitalWrite(PIN_RESET, HIGH);
  delay(1);
}

void writeCommand(unsigned char command)
{
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  SPI.transfer(command);
  digitalWrite(PIN_CS, HIGH);
}

void writeData(unsigned char data)
{
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  digitalWrite(PIN_DATA, HIGH);
  SPI.transfer(data);
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void writeCMD_p1(unsigned char command,unsigned char para)
{
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  SPI.transfer(command);
  digitalWrite(PIN_DATA, HIGH);
  SPI.transfer(para);
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void writeCMD_p2(unsigned char command,unsigned char para1,unsigned char para2)
{
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  SPI.transfer(command);
  digitalWrite(PIN_DATA, HIGH);
  SPI.transfer(para1);
  SPI.transfer(para2);
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void writeStream(unsigned char *value, unsigned char datalen)
{
  unsigned char i = 0;
	unsigned char *ptemp;

	ptemp = value;
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  SPI.transfer(*ptemp);
	ptemp++;
  digitalWrite(PIN_DATA, HIGH);
	for(i= 0;i<datalen-1;i++)	// sub the command
	{
		SPI.transfer(*ptemp);
		ptemp++;
	}
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void writeDispRam(unsigned char xSize,unsigned int ySize, const unsigned char *dispdata)
{
  unsigned int i = 0, j = 0, c = 0;
  char data;

	if(xSize%8 != 0)
	{
		xSize = xSize+(8-xSize%8);
	}
	xSize = xSize/8;

  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
	SPI.transfer(0x24);

  digitalWrite(PIN_DATA, HIGH);
	for(i=0;i<ySize;i++)
	{
		for(j=0;j<xSize;j++)
		{
      data = pgm_read_byte(&dispdata[c]);
			SPI.transfer(~data);
      c++;
		}
	}
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void writeDispRamMono(unsigned char xSize,unsigned int ySize, unsigned char dispdata)
{
  unsigned int i = 0,j = 0;
  if(xSize%8 != 0)
  {
  	xSize = xSize+(8-xSize%8);
  }
  xSize = xSize/8;

  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_CS, LOW);
  SPI.transfer(0x24);

  digitalWrite(PIN_DATA, HIGH);
  for(i=0;i<ySize;i++)
  {
  	for(j=0;j<xSize;j++)
  	{
  	 SPI.transfer(dispdata);
  	}
  }
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}
