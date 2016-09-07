#include <gde.h>
#include <gde021A1.h>
#include <gde021A1-pictures.h>
// #include <gde029.h>
// #include <gde029-pictures.h>

#include <Arduino.h>
#include <SPI.h>


void setup() {
  SPI.begin();
  pinMode(8, OUTPUT);
  initDisplay(false);
  displayImage(pictures[0]);
}

void loop() {
  delay(5000);
  for (unsigned int picture = 1; picture < num_pictures; picture++) {
    displayImage(pictures[picture]);
    delay(5000);
  }
  initDisplay(true); // go faster
  displayImage(0);
}
