#include <pins.h>
#include <gde.h>

// #include <gde021A1.h>
// #include <gde021A1-pictures.h>
#include <gdeh029a1.h>
// #include <menu-test.h>
#include <sha-images.h>

#include <Arduino.h>
#include <SPI.h>

bool faster = false;
unsigned int menu = 0;

void setup() {
  SPI.begin();
  pinMode(PIN_DATA, OUTPUT);
  initDisplay(false);
  displayImage(pictures[0]);
}

#ifdef GDEH029A1
int speed = 500;

void parttest()
{
	unsigned int h,i,j,k;
	writeLUT(true);
	powerOn();
	setRamArea(0x00,0x0f,0x27,0x01,0x00,0x00);
	setRamPointer(0x00,0x27,0x01);	// set ram
  writeDispRamMono(128, 296, 0xff);	// white
  delay(speed);
  writeDispRamMono(128, 296, 0xff);	// white
  updateDisplayPartial();
  delay(speed);
	while(1)
	{
	  partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x0);	// set ram
		writeDispRam(128,296, pictures[0]);
		updateDisplayPartial();
		delay(speed);
		partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x00);	// set ram
    writeDispRam(128,296, pictures[0]);
		delay(speed);

    for(h=0;h<13;h++)
    {
      for(i=0;i<8;i++)
    	{
  		  k=0x127-i*32-20;
  			j=k-32;
  			partialDisplay(0x0e - h,0x0e - h,k%256,k/256,j%256,j/256);	// set ram
  			writeDispRamMono(8, 32, 0x00);	// white
  	 		updateDisplayPartial();
  			delay(speed);
  			partialDisplay(0x0e - h,0x0e - h,k%256,k/256,j%256,j/256);	// set ram
  			writeDispRamMono(8, 32, 0x00);	// white
  			delay(speed);
    	}
    }
  }
}
#endif

void writeDispRamMenu(unsigned char xSize,unsigned int ySize, const unsigned char *dispdata, unsigned int menuItem)
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

      if (menu == 1) {
        if (i > 10 && i < 70 && j > 2 && j < 8) {
          data = ~data;
        }
      } else if (menu == 2) {

      } else if (menu == 3) {

      } else if (menu == 4) {

      }

			SPI.transfer(data);
      c++;
		}
	}
  digitalWrite(PIN_CS, HIGH);
  digitalWrite(PIN_DATA, LOW);
}

void menuImage(const unsigned char *picture, unsigned int menuItem = 0)
{
  setRamPointer(0x00,0x27,0x01);	// set ram
	writeDispRamMenu(128, 296, picture, menuItem);
	updateDisplay();
}

void loop() {
  // TODO wait for button
  //initDisplay(false);
  //menuImage(picture[1]);
  // TODO menu logic
}
