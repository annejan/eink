#include "gde029.h"
#include <gde.h>

// GDE029
// UC8157C ?

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
  resetDisplay();
  writeCommand(0x01);        	//Set VGH VGL   VSH VSL
  writeData (0x03);
  writeData (0x00);
  writeCommand(0x06);         //boost setting
  writeData (0x07);
  writeData (0x06);
  writeData (0x05);
  writeCommand(0x04);         //power up
  //     lcd_chkstatus();                //check ic state
  sleep(20);
  writeCommand(0x60); 		 //TCON Setting
  writeData (0x32);
  writeCommand(0X50);
  writeData(0x07);
  writeCommand(0x30);			//PLL setting
  writeData (0x39);
  writeCommand(0x61);			// resolution setting
  writeData (0x80);
  writeData (0x01);
  writeData (0x28);
  writeCommand(0x82);			//vcom setting
  writeData (0x05);
  writeLUT();
  writeCommand(0x10);	       //update grey image
  //Ultrachip();
  writeCommand(0x12);        //display
}

void entersleep()
{
  // writeCommand(0x22);//display updata sequence option
  // writeData(0x03);
  // writeCommand(0x20);
}
