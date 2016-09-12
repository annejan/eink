#include <pins.h>
#include <gde.h>

#include <gde021A1.h>
#include <gde021A1-pictures.h>
// #include <gde029.h>
// #include <gdeh029a1.h>
// #include <gde029-pictures.h>

#include <Arduino.h>
#include <SPI.h>


void setup() {
  SPI.begin();
  pinMode(PIN_DATA, OUTPUT);
  initDisplay(false);
  displayImage(pictures[0]);
}

#ifdef GDEH029A1_H
void parttest()
{
	unsigned int i,j,k;
	writeLUT(true);
	powerOn();
	setRamArea(0x00,0x0f,0x27,0x01,0x00,0x00);
	setRamPointer(0x00,0x27,0x01);	// set ram
  writeDispRamMono(128, 296, 0xff);	// white
  delay(10000);
  writeDispRamMono(128, 296, 0xff);	// white
  updateDisplayPartial();
  delay(10000);
	while(1)
	{
	  partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x0);	// set ram
		writeDispRam(128,296, gImage_logo);
		updateDisplayPartial();
		delay(10000);
		partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x00);	// set ram
    writeDispRam(128,296, gImage_logo);
		delay(10000);

		for(i=0;i<8;i++)
		{
		  k=0x127-i*32-20;
			j=k-32;
			partialDisplay(0x0e,0x0e,k%256,k/256,j%256,j/256);	// set ram
			writeDispRamMono(8, 32, 0x00);	// white
	 		updateDisplayPartial();
			delay(2000);
			partialDisplay(0x0e,0x0e,k%256,k/256,j%256,j/256);	// set ram
			writeDispRamMono(8, 32, 0x00);	// white
			delay(1000);
		}
	}
}
#endif

void loop() {
  delay(5000);
  for (unsigned int picture = 1; picture < num_pictures; picture++) {
    displayImage(pictures[picture]);
    delay(5000);
  }
#ifdef GDEH029A1_H
  parttest();
#else
  initDisplay(true); // go faster ;)
#endif
  displayImage(pictures[0]);
}
