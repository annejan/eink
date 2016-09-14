#include <pins.h>
#include <gde.h>

// #include <gde021A1.h>
// #include <gde021A1-pictures.h>
#include <gdeh029a1.h>
// #include <menu-test.h>
#include <sha-images.h>

#include <Arduino.h>
#include <SPI.h>

void setup() {
  SPI.begin();
  pinMode(PIN_DATA, OUTPUT);
  initDisplay(false);
  displayImage(pictures[0]);
}

#ifdef GDE_DRIVER_H
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

    for(h=0;h<8;h++)
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

bool faster = false;

void loop() {
  delay(faster ? 500 : 2000);
  for (unsigned int picture = 1; picture < num_pictures; picture++) {
    displayImage(pictures[picture]);
    delay(faster ? 500 : 2000);
  }
#ifdef GDE_DRIVER_H
  parttest();
#else
  faster = !faster;
  initDisplay(faster); // go faster ;)
  if (!faster) {
    delay(1500);
  }
#endif
  displayImage(pictures[0]);
}
