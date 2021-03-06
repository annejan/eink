#ifndef GDE_DRIVER_H
#define GDE_DRIVER_H
#define GDE021A1

#include <Arduino.h>

void writeLUT(bool fast);
void initDisplay(bool fast);
void displayImage(const unsigned char *picture);

const unsigned char init_data[90] = {
  0x82,0x00,0x00,0x00,0xAA,0x00,0x00,0x00,
  0xAA,0xAA,0x00,0x00,0xAA,0xAA,0xAA,0x00,
  0x55,0xAA,0xAA,0x00,0x55,0x55,0x55,0x55,
  0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
  0xAA,0xAA,0xAA,0xAA,0x15,0x15,0x15,0x15,
  0x05,0x05,0x05,0x05,0x01,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x41,0x45,0xF1,0xFF,0x5F,0x55,0x01,0x00,
  0x00,0x00,
}; // supplied with most demo code

const unsigned char fast_lut[90] = {
    /* VS[0-(00 to 33)] */
    0x00,0x00,0x00,0x55,
    /* VS[1-(00 to 33)] */
    0x00,0x00,0x55,0x55,
    /* VS[2-] */
    0x00,0x55,0x55,0x55,
    /* VS[3-] */
    0x55,0x55,0x55,0x55,
    /* VS[4-] */
    0x55,0xAA,0x55,0x55,
    /* VS[5-] */
    0xAA,0xAA,0xAA,0xAA,
    /* VS[6-] */
    0x05,0x05,0x05,0x05,
    /* VS[7-] */
    0x15,0x15,0x15,0x15,
    /* VS[8-] */
    0x01,0x01,0x01,0x01,
    /* VS[9-] (only the first 8 phases are used) */
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    /* 20 phase times: TP[0] to TP[19] */
    0x34,0x32,0xF1,0x74,0x14,0x00,0x00,0x00,
    0x00,0x00,
}; // found at https://github.com/jsyk/PIP-Watch/blob/master/pipwatch_zero-fw/epd.c
// at-least twice as fast as original

const unsigned char test_lut[90] = {
    0x00,0x00,0x00,0x55,0x00,0x00,0x55,0x55,0x00,0x55,0x55,0x55,0xAA,0xAA,0xAA,0xAA,
    0x15,0x15,0x15,0x15,0x05,0x05,0x05,0x05,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x22,0xFB,0x22,0x1B,0x00,0x00,0x00,0x00,0x00,0x00
}; // found at http://www.espruino.com/modules/SSD1606.js doesn't work too well :(

#endif
