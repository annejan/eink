#ifndef GDE09_H
#define GDE029_H

#include <Arduino.h>

void writeLUT(bool fast);
void initDisplay(bool fast);
void displayImage(const unsigned char *picture);

const unsigned char lut_vcom0[] =
{
           0x0F,
           0x0F,
           0x01,

           0x20,
           0x20,
           0x05,

           0x03,
           0x03,
           0x0A,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
};

const unsigned char lut_w[] =
{
           0x8F,
           0x8F,
           0x01,

           0xA0,
           0x60,
           0x05,

           0x03,
           0x43,
           0x0A,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
};
const unsigned char lut_b[] =
{
           0x4F,
           0x4F,
           0x01,

           0xA0,
           0x60,
           0x05,

           0x83,
           0x03,
           0x0A,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
};
const unsigned char lut_g1[] =
{
           0x4F,
           0x4F,
           0x01,

           0xA0,
           0x60,
           0x05,

           0x83,
           0x03,
           0x0A,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
};
const unsigned char lut_g2[] =
{           0x4F,
           0x4F,
           0x01,

           0xA0,
           0x60,
           0x05,

           0x83,
           0x03,
           0x0A,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,
           0x00,

};

#endif
