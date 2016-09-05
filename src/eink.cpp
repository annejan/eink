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

void writeLUT()
{
  unsigned char i;
  writeCommand(0x32);//write LUT register
  for (i = 0; i < 90; i++)
  {
    writeData(init_data[i]);
  }
}

void initSPD2701()
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
  writeData(0x03);
  writeCommand(0xF0);//booster feedback used
  writeData(0x1F);
  writeCommand(0x2C);//vcom voltage
  writeData(0xA0);
  writeCommand(0x3C);//board voltage ? border waveform ?
  writeData(0x63);
  writeCommand(0x22);//display updata sequence option ,in page 33
  writeData(0xC4);//enable sequence: clk -> CP -> LUT -> pattern display
  writeLUT();
}

void entersleep()
{
  writeCommand(0x22);//display updata sequence option
  writeData(0x03);
  writeCommand(0x20);
}

void displayImage(int wut)
{
  char data;
  int i;
  writeCommand(0x24);
  for (i = 0; i < 3096; i++)
  {
    if (wut == 1) {
      data = pgm_read_byte(&gImage[i]);
    } else if (wut == 2) {
      data = pgm_read_byte(&anusImage[i]);
    } else if (wut == 3) {
      data = pgm_read_byte(&ajImage[i]);
    } else if (wut == 4) {
      data = pgm_read_byte(&tiImage[i]);
    } else {
      data = pgm_read_byte(&ogImage[i]);
    }
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
  displayImage(1);
}

void loop() {
  delay(1000);
  displayImage(2);
  delay(1000);
  displayImage(3);
  delay(1000);
  displayImage(4);
  delay(1000);
  displayImage(5);
  delay(1000);
  displayImage(1);
}
