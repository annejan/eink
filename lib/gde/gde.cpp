#include <Arduino.h>
#include <SPI.h>
#include "gde.h"

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
