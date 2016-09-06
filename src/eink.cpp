#include <Arduino.h>
#include <SPI.h>

#include "eink.h"
#include "pictures.h"

void resetDisplay()
{
  digitalWrite(12, LOW);
  delay(1);
  digitalWrite(12, HIGH);
  delay(1);
}

void writeCommand(unsigned char command)
{
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
  SPI.transfer(command);
  digitalWrite(10, HIGH);
}

void writeData(unsigned char data)
{
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);
  SPI.transfer(data);
  digitalWrite(10, HIGH);
  digitalWrite(8, LOW);
}

void writeLUT(bool fast = false)
{
  unsigned char i;
  writeCommand(0x32);//write LUT register
  for (i = 0; i < 90; i++)
  {
    if (fast) {
      writeData(fast_lut[i]);
    } else {
      writeData(init_data[i]);
    }
  }
}

void initSPD2701(bool fast = false)
{
  writeCommand(0x03);//set PREVGH,PREVGL
  writeData(0x00);
  writeCommand(0x10);//set no deep sleep mode
  writeData(0x00);
  writeCommand(0x11);//data enter mode
  writeData(0x01);
  writeCommand(0x44);//setRAM x address start/end
  writeData(0x00);//RAM x address start at 00h;
  writeData(0x11);//RAMx address end at 11h(17)->72
  writeCommand(0x45);//set RAM y address start/end
  writeData(0xAB);//RAM y address start at 00h;
  writeData(0x00);//RAM y address start at ABh(171)->172
  writeCommand(0x4E);//set RAM x address count to 0;
  writeData(0x00);
  writeCommand(0x4F);//set RAM y address count to 0;
  writeData(0xAB);
  writeCommand(0x21);//bypass RAM data
  writeData(0x03);      // InitialUpdate_SourceControl=3=GS0,GS3; Disable Bypass - clear with inverted image, than draw the image.
  // writeData(0x83);      // InitialUpdate_SourceControl=3=GS0,GS3; Enable Bypass (clear with white bg)
  // writeData(0xB3);      // InitialUpdate_SourceControl=3=GS0,GS3; Enable Bypass; A[5:4]=11 (clear with black bg)
  writeCommand(0xF0);//booster feedback used
  writeData(0x1F);
  writeCommand(0x2C);//vcom voltage
  writeData(0xA0);
  writeCommand(0x3C);//board voltage ? border waveform ?
  writeData(0x63);          // fix white; OK
  // writeData(0x43);          // leaves gray border
  // writeData(0x03);          // Black-White transition; OK
  writeCommand(0x22);//display updata sequence option ,in page 33
  // writeData(0xC4);      //enable sequence: clk -> CP -> LUT -> pattern display
  // writeData(0xC0);      // enable clock, enable CP
  // writeData(0xCC);      // enable clock, enable CP, display initial (black/white transient several times), display pattern
  writeData(0xC7);      // enable clock, enable CP, display pattern; Disable CP, disable clock. OK
  writeLUT(fast);
}

void entersleep()
{
  writeCommand(0x22);//display updata sequence option
  writeData(0x03);
  writeCommand(0x20);
}

void displayImage(unsigned int wut)
{
  char data;
  int i;
  writeCommand(0x24);
  for (i = 0; i < 3096; i++)
  {
    data = pgm_read_byte(&pictures[wut][i]);
    writeData(~data);
  }
  writeCommand(0x20);
  entersleep();
}

void setup() {
  SPI.begin();
  pinMode(8, OUTPUT);
  resetDisplay();
  initSPD2701();
  displayImage(0);
}

void loop() {
  delay(5000);
  displayImage(1);
  delay(5000);
  displayImage(2);
  delay(5000);
  displayImage(3);
  delay(5000);
  displayImage(4);
  delay(5000);
  resetDisplay();
  initSPD2701(true); // go faster
  displayImage(0);
}
