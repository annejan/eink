#include <gde.h>
#include <gde021A1.h>
#include <gde021A1-pictures.h>

#include <Arduino.h>
#include <SPI.h>

void displayImage(unsigned int picture)
{
  char data;
  int i;
  writeCommand(0x24);
  for (i = 0; i < 3096; i++)
  {
    data = pgm_read_byte(&pictures[picture][i]);
    writeData(~data);
  }
  writeCommand(0x20);
  entersleep();
}

void setup() {
  SPI.begin();
  pinMode(8, OUTPUT);
  initDisplay(false);
  displayImage(0);
}

void loop() {
  delay(5000);
  for (unsigned int picture = 1; picture < num_pictures; picture++) {
    displayImage(picture);
    delay(5000);
  }
  initDisplay(true); // go faster
  displayImage(0);
}
