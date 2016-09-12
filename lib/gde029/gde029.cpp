#include "gde029.h"
#include <gde.h>

// GDE029
// UC8157C ?

// WARNING WARNING WARNING WARNING WARNING WARNING //
//                                                 //
// TODO  this driver is not functional (yet)  TODO //
//                                                 //
// WARNING WARNING WARNING WARNING WARNING WARNING //

void writeLUT(bool fast = false)
{
  // NB the fast bool is currently unused
  unsigned int count;
  writeCommand(0x20);
  for(count=0;count<15;count++)
  {
    writeData(lut_vcom0[count]);
  }
  writeCommand(0x21);
  for(count=0;count<15;count++)
  {
    writeData(lut_w[count]);
  }
  writeCommand(0x22);
  for(count=0;count<15;count++)
  {
    writeData(lut_b[count]);
  }
}

void initDisplay(bool fast = false)
{
  // NB the fast bool is currently unused
  writeCommand(0x12);   //  »Ìº˛RESET
  resetDisplay();

  writeCommand(0x04);    //power on
  delay(1000);
  writeCommand(0x00);     //Panel setting
  writeData (0x83);
  writeCommand(0x01);     //power setting
  writeData (0x03);
  writeData (0x00);
  writeData (0x08);
  writeData (0x05);
  writeCommand(0x06);     //booster setting
  writeData (0x07);
  writeData (0x07);
  writeData (0x07);
  writeCommand(0x03);    //PLL setting
  writeData (0x39);

  writeCommand(0x82);   //Vcom DC setting
  writeData(0x08);
  writeCommand(0x60);   //TCON setting
  writeData(0x22);
  writeCommand(0x50);   //Vcom datainterval setting
  writeData(0x17);

  writeCommand(0x61);    //resolution,128x296
  writeData (0x80);
  writeData (0x01);
  writeData (0x28);
  writeLUT();
}

void displayImage(const unsigned char *picture)
{
  char data;
  int i;
  writeCommand(0x10);	       //update grey image
  for (i = 0; i < 3096; i++)
  {
    data = pgm_read_byte(&picture[i]);
    writeData(~data);
  }
  writeCommand(0x12);        //display
  writeCommand(0x02);        //power off
}
