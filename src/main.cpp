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

#define PIN_JOY_BTN 2
#define PIN_JOY_X A5
#define PIN_JOY_Y A4

void setup() {
  SPI.begin();
  pinMode(PIN_DATA, OUTPUT);

  pinMode(3, OUTPUT); // joystick
  digitalWrite(3, HIGH); // VCC
  pinMode(4, OUTPUT); // joystick
  digitalWrite(4, LOW); // GND

  pinMode(PIN_JOY_BTN, INPUT_PULLUP); // joystick button
  pinMode(PIN_JOY_X, INPUT); // joystick X
  pinMode(PIN_JOY_Y, INPUT); // joystick Y

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
	while(digitalRead(PIN_JOY_BTN) == HIGH)
	{
	  partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x0);	// set ram
		writeDispRam(128,296, pictures[4]);
		updateDisplayPartial();
		delay(speed);
		partialDisplay(0x00,0x0f,0x27,0x01,0x00,0x00);	// set ram
    writeDispRam(128,296, pictures[4]);
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

      if (menuItem == 1) {
        if (i > 8 && i < 140 && j > 2 && j < 8) {
          data = ~data;
        }
      } else if (menuItem == 2) {
        if (i > 8 && i < 140 && j > 8 && j < 14) {
          data = ~data;
        }
      } else if (menuItem == 3) {
        if (i > 156 && i < 288 && j > 2 && j < 8) {
          data = ~data;
        }
      } else if (menuItem == 4) {
        if (i > 156 && i < 288 && j > 8 && j < 14) {
          data = ~data;
        }
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

bool menuX = false;
bool menuY = false;
bool active = false;
bool button = true;
int menuItem = 1;
bool animu = false;
bool flip = false;

void loop() {
  bool escape = false;
  while (digitalRead(PIN_JOY_BTN) == HIGH) {
    if (animu) {
      if (flip) {
        displayImage(pictures[0]);
      } else {
        displayImage(pictures[4]);
      }
      flip = !flip;
      delay(600);
    }
  }
  animu = false;
  menuImage(pictures[1],0);
  delay(2000);
  initDisplay(true);
  menuImage(pictures[1], menuItem);

  while (!escape) {
    int x = analogRead(PIN_JOY_X);
    int y = analogRead(PIN_JOY_Y);
    // center is aprox 520, minus 3 max 1018 (pretty good)
    if (x < 30 || x > 990) {
      active = true;
      menuX = !menuX;
    }
    if (y < 30 || y > 990) {
      active = true;
      menuY = !menuY;
    }
    if (!active && digitalRead(PIN_JOY_BTN) == LOW) {
      button = true;
      active = true;
    }
    if (active) {
      active = false;
      if (menuX && menuY) {
        menuItem = 4;
      } else if (menuX && !menuY) {
        menuItem = 2;
      } else if (!menuX && !menuY) {
        menuItem = 1;
      } else if (!menuX && menuY) {
        menuItem = 3;
      }
      menuImage(pictures[1], menuItem);
      if (button == true) {
        button = false;
        delay(300);
        menuImage(pictures[1], 0);
        delay(300);
        if (menuItem == 1) {
          resetDisplay();
          delay(200);
          initDisplay(false);
          displayImage(pictures[2]);
          escape = true;
        } else if (menuItem == 2) {
          resetDisplay();
          delay(200);
          initDisplay(false);
          displayImage(pictures[3]);
          escape = true;
        } else if (menuItem == 3) {
          parttest();
          resetDisplay();
          delay(200);
          initDisplay(false);
          displayImage(pictures[4]);
          escape = true;
        } if (menuItem == 4) {
          displayImage(pictures[4]);
          animu = true;
          escape = true;
        }
      }
    }
    delay(600);
  }
}
