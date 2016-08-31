#include <util/delay.h>
//172*72
#define nDC_H digitalWrite(8,HIGH)
#define nDC_L digitalWrite(8,LOW)
#define nCS_H digitalWrite(10,HIGH)
#define nCS_L digitalWrite(10,LOW)
#define SDA_H digitalWrite(11,HIGH)
#define SDA_L digitalWrite(11,LOW)
#define SCLK_H digitalWrite(13,HIGH)
#define SCLK_L digitalWrite(13,LOW)
#define nRST_H digitalWrite(12,HIGH)
#define nRST_L digitalWrite(12,LOW)
#define a digitalRead(9)
 
const unsigned char init_data[]={ 
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
0x00,0x00,};//waveform 
 
const unsigned char PROGMEM gImage[3096] = { /* 0X11,0X02,0X00,0XAC,0X00,0X48, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X00,0X0F,0X40,0X00,0X00,0X02,0XC0,0X0B,0XE0,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X01,0XF8,0X0F,0XC0,0X00,0X00,0X0F,0X80,0X3F,0XF0,
0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X0B,0XFE,0X02,0XE0,0X00,0X00,0X1E,0X00,
0XF4,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,0X1F,0X00,0XF0,0X00,0X00,
0X3C,0X01,0XC0,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X3D,0X0F,0X00,0XF0,
0X00,0X00,0X3C,0X03,0X80,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X3C,0X0F,
0X00,0XF0,0X00,0X00,0X3E,0X1F,0X00,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
0X3C,0X0F,0X41,0XE0,0X00,0X00,0X1F,0XFC,0X00,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X3C,0X0B,0XC3,0XD0,0X00,0X00,0X0B,0XE0,0X00,0XB0,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X1C,0X03,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0XFD,0X00,0X00,0X00,0X00,0XBF,0XF8,0X00,
0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,
0XFF,0X80,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X1F,0X80,0X0B,0XD0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0XFF,0XF0,
0X00,0X00,0X3D,0X00,0X01,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0XBF,0XFF,
0XFF,0XF0,0X00,0X00,0X3C,0X00,0X00,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
0X00,0X0B,0X40,0X00,0X00,0X00,0X3C,0X00,0X01,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X2D,0X00,0X00,0X00,0X00,0X2F,0X40,0X1B,0XD0,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X0B,0XFF,0XFF,0X80,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X00,0X01,0XBF,0XF8,0X00,
0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X1F,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X02,0XC0,0X00,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X3C,0X3F,
0XFF,0XF0,0X00,0X00,0X0B,0X40,0X00,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
0X3C,0X3F,0XFF,0XF0,0X00,0X00,0X2F,0XFF,0XFF,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF0,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF0,
0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X00,
0X38,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X0B,0XFF,0XFF,0XE0,
0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3C,
0X00,0X00,0X00,0X00,0X3C,0X00,0X01,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
0X00,0X38,0X00,0X00,0X00,0X00,0X3C,0X00,0X2F,0XD0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X02,0XFD,0X00,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X2F,0XD0,0X00,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3D,0XFD,0X00,0X00,
0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XD0,
0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X3F,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,
0X3F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X03,0XBF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X02,0XD0,0X00,0X00,0X00,
0XBF,0XFF,0XFF,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X03,0XC0,0X00,
0X00,0X00,0XFF,0XFF,0XFF,0XE0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X03,
0XC0,0X00,0X00,0X00,0X00,0X1E,0X01,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,
0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X3C,0X00,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,
0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X3C,0X00,0XF0,0X00,0X02,0XAA,0XAA,
0XAA,0XAA,0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X3E,0X03,0XE0,0X00,0X02,
0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XC0,
0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,
0XFE,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X01,0XFF,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X0B,0XFF,0XD0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X1F,
0X42,0XF0,0X00,0X00,0X00,0X01,0XFF,0X40,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,
0X00,0X3C,0X00,0XF0,0X00,0X00,0X00,0X0B,0XFF,0XD0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,
0X00,0X00,0X00,0X3C,0X01,0XF0,0X00,0X00,0X00,0X1F,0X42,0XF0,0X00,0X02,0XAA,0XAA,
0XAA,0XAA,0X00,0X00,0X00,0X3F,0XFF,0XD0,0X00,0X00,0X00,0X3C,0X00,0XF0,0X00,0X02,
0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X1F,0XFF,0XD0,0X00,0X00,0X00,0X3C,0X01,0XF0,
0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X04,0X00,0XB0,0X00,0X00,0X00,0X3F,
0XFF,0XD0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X1F,0XFF,0XD0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0XBF,0XFF,0XFF,
0XFC,0X00,0X00,0X04,0X00,0XB0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0XBF,
0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,
0X00,0X1E,0X00,0XF0,0X00,0X00,0X00,0X02,0XFE,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,
0X00,0X00,0X00,0X3C,0X00,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XD0,0X00,0X02,0XAA,0XAA,
0XAA,0XAA,0X00,0X00,0X00,0X3D,0X02,0XF0,0X00,0X00,0X00,0X2F,0X03,0XF0,0X00,0X02,
0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X2F,0XFF,0XD0,0X00,0X00,0X00,0X3C,0X00,0XF0,
0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X06,0XFE,0X00,0X00,0X00,0X00,0X3C,
0X00,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X2D,0X02,0XE0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X7F,0XFF,0XFF,0XE0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0XBF,
0XFF,0XFF,0XFC,0X00,0XFF,0XFF,0XFF,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,
0X00,0XBF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,0XAA,0XAA,
0X00,0X00,0X00,0X1E,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,
0XAA,0XAA,0X00,0X00,0X00,0X3C,0X00,0XF0,0X00,0X00,0X00,0X01,0XFF,0X40,0X34,0X02,
0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X3D,0X02,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XE0,
0X3C,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X2F,0XFF,0XD0,0X00,0X00,0X00,0X2F,
0X41,0XF0,0X3C,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X06,0XFE,0X00,0X00,0X00,
0X00,0X3C,0X00,0XF0,0X3C,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X3C,0X07,0XC1,0XF8,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X2F,0XFF,0XFF,0XF0,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,
0X00,0X01,0XFF,0X40,0X00,0X00,0X00,0X0F,0XFF,0XFA,0X40,0X02,0XAA,0XAA,0XAA,0XAA,
0X00,0X00,0X00,0X0F,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XAA,0XAA,
0XAA,0XAA,0X00,0X00,0X00,0X2F,0X6F,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,
0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X3C,0X38,0XF0,0X00,0X00,0X00,0X01,0XFF,0X40,
0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X3C,0XB0,0XF0,0X00,0X00,0X00,0X0F,
0XFF,0XC0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X3D,0XE0,0XF0,0X00,0X00,
0X00,0X2F,0X6F,0XE0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X2F,0XC1,0XD0,
0X00,0X00,0X00,0X3C,0X38,0XF0,0X00,0X02,0XAA,0XAA,0XAA,0XAA,0X00,0X00,0X00,0X0F,
0X43,0X80,0X00,0X00,0X00,0X3C,0XB0,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3D,0XE0,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2F,0XC1,0XD0,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,0X00,0X0F,0X43,0X80,0X00,0X01,
0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X2F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X0B,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X2C,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X3C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X3F,
0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X00,0X0B,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X01,
0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X02,0XE0,0XE0,0X00,0X00,0X00,0X3C,0X00,0X00,
0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X0B,0XF4,0XF0,0X00,0X00,0X0F,0XFF,
0XFF,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X0E,0X78,0XF0,0X00,0X00,
0X0B,0XFF,0XFF,0XE0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X2C,0X3C,0XF0,
0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X3F,
0X2F,0XE0,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X00,0X3F,0X0B,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X40,0X00,0X01,
0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XC0,
0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2F,
0X6F,0XE0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X3C,0X38,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X3C,0XB0,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X3D,0XE0,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X00,0X00,0X01,0XF0,0X00,0X00,0X00,0X2F,0XC1,0XD0,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X00,0X2F,0XE0,0X00,0X00,0X00,0X0F,0X43,0X80,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X01,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X1F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0XBF,0XF0,0X00,0X00,0X00,0X00,0X02,
0XE0,0XE0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X07,0XE1,0XE0,0X00,0X00,0X00,
0X00,0X0B,0XF4,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X1F,0X93,0XC0,0X00,
0X00,0X00,0X00,0X0E,0X78,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X3F,0XFF,
0XF9,0X00,0X00,0X00,0X00,0X2C,0X3C,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X05,0XAF,0XFF,0XE0,0X00,0X00,0X00,0X3F,0X2F,0XE0,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X00,0X5A,0XF0,0X00,0X00,0X00,0X3F,0X0B,0XC0,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,0X00,0X38,
0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X2F,0XFF,0XF0,0X00,0X00,
0X00,0X3C,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X0B,0X00,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,0X00,0X2C,
0X00,0X00,0X00,0X00,0X0B,0XFF,0XFF,0XE0,0X00,0X01,0X55,0X55,0X55,0X55,0X00,0X00,
0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X01,0X55,0X55,0X55,0X55,
0X00,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X01,0X55,0X55,
0X55,0X55,0X00,0X00,0X00,0X0B,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2D,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2F,0XD0,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFD,0X01,
0XBC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X7F,0XEF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X07,0XFD,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X7F,0X90,0X00,0X00,0X00,0X3F,0XFF,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X07,0XF8,0X00,0X00,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X28,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0X90,0X00,
0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,
0XFF,0X80,0X00,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0X6B,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X06,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X06,0XFE,0X00,0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XE5,0X00,0X00,0X00,0X00,0X2F,0XFF,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,0X00,0X0B,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X05,0X5B,0XF0,0X00,0X00,
0X00,0X2C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XBF,0XE0,
0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,
0XFE,0X40,0X00,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X3E,0X40,0X00,0X00,0X00,0X00,0X0B,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X40,0X00,0X00,0X3C,0X3F,0XFF,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0B,0XFF,0XD0,0X00,0X00,0X3C,0X3F,
0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0X42,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,
0X01,0XF0,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X3F,0XFF,0XD0,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X1F,0XFF,0XD0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X04,0X00,0XB0,0X00,0X00,0X0B,0XFF,0XFF,0XE0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2D,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2F,0XD0,0X00,0X00,0X00,0X00,0X38,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFD,0X01,0XBC,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XEF,
0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X07,0XFD,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X7F,0X90,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X07,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X3F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X28,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char PROGMEM ajImage[3096] = { /* 0X11,0X02,0X00,0XAC,0X00,0X48, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0XD0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X07,0XD0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X2F,0XC0,0X00,0X1D,0XB8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XF0,0X00,0X74,0X1F,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XBF,0XFF,0XF8,0X00,0XD0,0X03,0XC0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0B,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X40,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XBF,0XFF,0XFF,0XFC,0X00,0X55,
0X55,0X40,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XEF,0XFF,0XFF,0XFF,0XF8,
0X00,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,
0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,
0XFF,0XFF,0XFF,0X40,0X00,0X00,0X68,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0XFF,0XFF,0XFF,0XFF,0XF4,0X00,0X00,0X01,0XFB,0X40,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X1F,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X03,0X71,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X03,0X30,0XC0,0X00,0X00,
0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X02,0XB2,0X80,
0X00,0X00,0X00,0X00,0X00,0X00,0XBF,0XFF,0XFF,0XFF,0XD0,0X00,0X00,0X00,0X00,0X00,
0XB3,0X00,0X00,0X00,0X00,0X00,0X00,0X0B,0XFF,0XFF,0XFF,0XFD,0X00,0X00,0X00,0X00,
0X00,0X41,0X55,0X40,0X00,0X00,0X00,0X00,0X00,0XBF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,
0X00,0X00,0X00,0XE3,0XFF,0XC0,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0XFF,0XFF,0XF4,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,
0XFF,0XF4,0X00,0X00,0X00,0X00,0X00,0X01,0X55,0X40,0X00,0X00,0X00,0X02,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XD0,0X00,0X00,0X00,0X2F,
0XFF,0XFF,0XFF,0XEF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X02,0X80,0X00,0X00,0X00,
0X00,0XFF,0XFF,0XFF,0XFF,0X1F,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,
0X00,0X00,0X07,0XFF,0XFF,0XFF,0XF4,0X2F,0XFF,0XD0,0X00,0X00,0X00,0X00,0X00,0X03,
0X95,0X00,0X00,0X00,0X2F,0XFF,0XFF,0XFF,0X80,0X3F,0XFF,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0XFF,0XC0,0X00,0X00,0XFF,0XFF,0XFF,0XFD,0X00,0X3F,0XFF,0XC0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0XFF,0XE0,0X00,0X3F,0XFF,0XC0,
0X00,0X00,0X00,0X00,0X00,0X00,0X68,0X00,0X00,0X2F,0XFF,0XFF,0XFE,0X00,0X00,0X7F,
0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X01,0XFB,0X40,0X00,0XBF,0XFF,0XFF,0XF4,0X00,
0X00,0XBF,0XFF,0X40,0X00,0X00,0X00,0X00,0X00,0X03,0X71,0XC0,0X03,0XFF,0XFF,0XFF,
0X80,0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X30,0XC0,0X0F,0XFF,
0XFF,0XFC,0X00,0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XB2,0X80,
0X3F,0XFF,0XFF,0XF4,0X00,0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XB3,0X00,0XBF,0XFF,0XFF,0XFF,0XE9,0X00,0X01,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X41,0XFF,0XFD,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFD,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFD,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFE,0X50,0X00,0X00,0X00,0X00,0X55,0X55,0X40,0X02,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X90,0X00,0X00,0X00,0XFF,0XFF,0XC0,0X00,0X01,
0X6F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X1A,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,
0X68,0X00,0X00,0X00,0X00,0X00,0X05,0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X00,0X01,0XFB,0X40,0X00,0X00,0X00,0X00,0X00,0X01,0X6F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF0,0X00,0X03,0X71,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1B,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF8,0X00,0X03,0X30,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X06,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X02,0XB2,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0XBF,0XFF,0XFF,0XFC,0X00,0X00,0XB3,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XF8,0X00,0X03,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0B,0XFF,0XF0,0X00,0X1B,0XEA,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X6F,0XC0,0X00,0X1B,
0XAA,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X03,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X03,0X00,0X40,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X1B,0XEA,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1B,0XAA,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X01,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X69,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFB,0X40,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0X71,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X03,0X30,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X02,0XB2,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XB3,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X55,0XAB,0XFF,0XFF,0XEA,0X90,0X00,0X03,0XFF,0XC0,0X00,0X00,0X00,0X00,
0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X02,0X80,0X00,0X00,0X00,
0X00,0X02,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X03,0X00,0X00,
0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X02,
0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFE,0X00,0X1B,0XEA,0X00,0X00,0X00,0X00,0X00,0X2F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFC,0X00,0X1B,0XAA,0XC0,0X00,0X00,0X00,0X00,0X00,0X02,0XFF,0XFF,
0XFF,0XFA,0X50,0X00,0X15,0X40,0X00,0X03,0X01,0XCC,0X00,0X00,0X00,0X00,0X00,0X0B,
0XFF,0XFF,0XFE,0X40,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X4C,0X00,0X00,0X00,0X00,
0X00,0X3F,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0XE3,0XFF,0XFC,0X00,0X00,
0X00,0X00,0X00,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X41,0X55,0X50,
0X00,0X00,0X00,0X00,0X02,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X68,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0XFB,0X40,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFD,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X03,0X71,0XC0,0X00,0X00,0X00,0X00,0X2F,0XFF,0XF4,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X03,0X30,0XC0,0X00,0X00,0X00,0X00,0X3F,0XFF,0XD0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XB2,0X80,0X00,0X00,0X00,0X00,0X7F,0XFF,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XB3,0X00,0X00,0X00,0X00,0X00,
0XBF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X52,0X00,0X00,0X00,
0X00,0X00,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XF3,0X80,
0X00,0X00,0X00,0X00,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0X24,0XC0,0X00,0X00,0X00,0X00,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X03,0X58,0XC0,0X00,0X00,0X00,0X00,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0XCF,0X80,0X00,0X00,0X00,0X00,0XBF,0XFE,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X05,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XD0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XEA,0X54,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X40,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X01,
0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X1B,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF0,0X03,0X07,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X5A,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE0,0X03,0X2D,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X56,0XBF,0XFF,0X40,0X03,0XB0,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X41,0X55,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE3,0XFF,0XC0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0XE3,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X41,0X55,0X50,0X00,0X00,0X00,0X00,0X00,0X16,0XBF,0XFF,
0XFF,0XFA,0XA5,0X40,0X00,0X00,0X00,0X01,0X55,0X40,0X00,0X00,0X00,0X00,0X1F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X90,0X00,0X00,0X03,0XFF,0XD0,0X00,0X00,0X00,0X00,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFD,0X00,0X00,0X02,0X80,0X00,0X00,0X00,
0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X03,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XD0,0X00,0X03,
0X95,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X00,0XFF,0XC0,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFE,0X94,0X00,0X00,0X00,
0X15,0XAF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0XFD,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XBF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0X00,0X00,0X29,0X04,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0X00,0X01,
0XEB,0X4E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
0X00,0X03,0X40,0XC7,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X3F,0XFF,0X00,0X03,0X00,0XC3,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X3F,0XFF,0X00,0X01,0X82,0X8A,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X3F,0XFF,0X00,0X03,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFD,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XBF,0XFC,0X00,0X03,0XFF,0XC0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFC,0X00,0X02,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XF8,
0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XF0,0X00,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0XFF,0XF0,0X00,0X00,0X0A,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X40,0X01,0XEF,0XC0,0X00,0X00,0X00,0X00,0X7F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XD0,0X03,0X70,0XC0,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X03,0X71,0XC0,0X00,0X00,
0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X02,0XFB,0X80,
0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X6A,0X80,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XD0,0X01,0X55,0X54,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X40,0X03,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X02,0X82,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X41,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X14,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X55,0X54,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF8,0X00,
0X00,0X03,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,
0XFF,0X00,0X00,0X02,0X82,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X2F,0XFF,0XC0,0X00,0X03,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X6F,0XFD,
0X00,0X00,0X00,0X3F,0XFF,0XD0,0X00,0X03,0X41,0XC0,0X00,0X00,0X00,0X00,0X00,0X07,
0XFF,0XFF,0XD0,0X00,0X00,0X3F,0XFF,0XF0,0X00,0X01,0XFF,0X40,0X00,0X00,0X00,0X00,
0X00,0X2F,0XFF,0XFF,0XF4,0X00,0X00,0X0F,0XFF,0XF4,0X00,0X00,0X14,0X00,0X00,0X00,
0X00,0X00,0X00,0XBF,0XFF,0XFF,0XFC,0X00,0X00,0X07,0XFF,0XF8,0X00,0X41,0X55,0X40,
0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XFD,0X00,0X00,0X02,0XFF,0XFC,0X00,0XE3,
0XFF,0XC0,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0XFF,0XFC,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0B,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,
0XFF,0XFD,0X00,0X00,0X29,0X04,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF8,0X7F,0XFF,0X40,
0X00,0X00,0XBF,0XFE,0X00,0X01,0XEB,0X4E,0X00,0X00,0X00,0X00,0X1F,0XFF,0XD0,0X3F,
0XFF,0X80,0X00,0X00,0X7F,0XFF,0X00,0X03,0X40,0XC7,0X00,0X00,0X00,0X00,0X2F,0XFF,
0X80,0X3F,0XFF,0XC0,0X00,0X00,0X3F,0XFF,0X00,0X03,0X00,0XC3,0X00,0X00,0X00,0X00,
0X3F,0XFF,0X00,0X2F,0XFF,0XC0,0X00,0X00,0X3F,0XFF,0X00,0X01,0X82,0X8A,0X00,0X00,
0X00,0X00,0X7F,0XFD,0X00,0X1F,0XFF,0XD0,0X00,0X00,0X3F,0XFF,0X00,0X03,0XFF,0XF8,
0X00,0X00,0X00,0X00,0XBF,0XFC,0X00,0X0F,0XFF,0XE0,0X00,0X00,0X3F,0XFF,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XF8,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X3F,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XF0,0X00,0X0B,0XFF,0XF0,0X00,0X00,
0X3F,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XF0,0X00,0X07,0XFF,0XF4,
0X00,0X00,0X7F,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XFF,0XE0,0X00,0X03,
0XFF,0XFC,0X00,0X00,0XBF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XD0,
0X00,0X03,0XFF,0XFD,0X00,0X00,0XFF,0XFD,0X00,0X00,0X01,0X80,0X00,0X00,0X00,0X07,
0XFF,0XC0,0X00,0X01,0XFF,0XFF,0X00,0X00,0XFF,0XFC,0X00,0X00,0X6F,0X40,0X00,0X00,
0X00,0X0B,0XFF,0X80,0X00,0X00,0XFF,0XFF,0XC0,0X02,0XFF,0XFC,0X00,0X07,0XF4,0X00,
0X00,0X00,0X00,0X0F,0XFF,0X40,0X00,0X00,0XBF,0XFF,0XF4,0X0B,0XFF,0XF8,0X00,0XB9,
0X30,0X00,0X00,0X00,0X00,0X1F,0XFF,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0XF4,0X30,0X00,0X00,0X00,0X00,0X2F,0XFF,0XFA,0X40,0X00,0X1F,0XFF,0XFF,0XFF,
0XFF,0XE0,0X00,0X1F,0XB0,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X00,0X0B,0XFF,
0XFF,0XFF,0XFF,0XC0,0X00,0X00,0XBE,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XFC,0X00,
0X02,0XFF,0XFF,0XFF,0XFF,0X40,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,0X3F,0XFF,0XFF,
0XFC,0X00,0X00,0X7F,0XFF,0XFF,0XFD,0X00,0X00,0X00,0X03,0X40,0X00,0X00,0X00,0X1F,
0XFF,0XFF,0XFC,0X00,0X00,0X0B,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X02,0XC0,0X00,0X00,
0X00,0X07,0XFF,0XFF,0XF4,0X00,0X00,0X00,0X6F,0XFE,0X40,0X00,0X00,0X00,0X01,0XC0,
0X00,0X00,0X00,0X00,0X01,0XBF,0XD0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X55,
0X57,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

void DELAY_mS(int delaytime) //???? 
{ 
   while(delaytime--)_delay_ms(1);
}
 
void RESET() 
{ 
  nRST_L; 
  DELAY_mS(1);//1ms 
  nRST_H; 
  DELAY_mS(1);//1ms 
} 
 
void SPI4W_WRITECOM(unsigned char INIT_COM) 
{ 
  unsigned char TEMPCOM; 
  unsigned char scnt; 
 
  TEMPCOM=INIT_COM; 
  nCS_H; 
  nCS_L; 
  SCLK_L; 
  nDC_L; 
  for(scnt=0;scnt<8;scnt++) 
  { 
    if(TEMPCOM&0x80)  SDA_H; 
    else SDA_L; 
    SCLK_H; 
    SCLK_L; 
    TEMPCOM=TEMPCOM<<1; 
  } 
  nCS_H; 
} 
 
void SPI4W_WRITEDATA(unsigned char INIT_DATA) 
{ 
  unsigned char TEMPCOM; 
  unsigned char scnt; 
  TEMPCOM=INIT_DATA; 
  nCS_H; 
  nCS_L; 
  SCLK_L; 
  nDC_H; 
  for(scnt=0;scnt<8;scnt++) 
  { 
    if(TEMPCOM&0x80)   SDA_H; 
    else  SDA_L; 
    SCLK_H; 
    SCLK_L; 
    TEMPCOM=TEMPCOM<<1; 
  } 
  nCS_H; 
  nDC_L; 
} 
 
void WRITE_LUT() 
{ 
  unsigned char i; 
  SPI4W_WRITECOM(0x32);//write LUT register 
  for(i=0;i<90;i++) 
  {
    SPI4W_WRITEDATA(init_data[i]);
  }
} 
 
void INIT_SPD2701() 
{ 
  SPI4W_WRITECOM(0x03);//set PREVGH,PREVGL
  SPI4W_WRITEDATA(0x00); 
  SPI4W_WRITECOM(0x10);//set no deep sleep mode 
  SPI4W_WRITEDATA(0x00); 
  SPI4W_WRITECOM(0x11);//data enter mode 
  SPI4W_WRITEDATA(0x01); 
  SPI4W_WRITECOM(0x44);//setRAM x address start/end 
  SPI4W_WRITEDATA(0x00);//RAM x address start at 00h; 
  SPI4W_WRITEDATA(0x11);//RAMx address end at 11h(17)->72  
  SPI4W_WRITECOM(0x45);//set RAM y address start/end 
  SPI4W_WRITEDATA(0xAB);//RAM y address start at 00h; 
  SPI4W_WRITEDATA(0x00);//RAM y address start at ABh(171)->172 
  SPI4W_WRITECOM(0x4E);//set RAM x address count to 0; 
  SPI4W_WRITEDATA(0x00); 
  SPI4W_WRITECOM(0x4F);//set RAM y address count to 0; 
  SPI4W_WRITEDATA(0xAB); 
  SPI4W_WRITECOM(0x21);//bypass RAM data 
  SPI4W_WRITEDATA(0x03); 
  SPI4W_WRITECOM(0xF0);//booster feedback used 
  SPI4W_WRITEDATA(0x1F); 
  SPI4W_WRITECOM(0x2C);//vcom voltage 
  SPI4W_WRITEDATA(0xA0); 
  SPI4W_WRITECOM(0x3C);//board voltage 
  SPI4W_WRITEDATA(0x63); 
  SPI4W_WRITECOM(0x22);//display updata sequence option ,in page 33 
  SPI4W_WRITEDATA(0xC4);//enable sequence: clk -> CP -> LUT -> pattern display 
  WRITE_LUT(); 
} 
 
void entersleep() 
{ 
  SPI4W_WRITECOM(0x22);//display updata sequence option 
  SPI4W_WRITEDATA(0x03); 
  SPI4W_WRITECOM(0x20); 
} 
 
void image_display(int wut) 
{ 
  char data;
  int i; 
  SPI4W_WRITECOM(0x24); 
  for(i=0;i<3096;i++) 
  { 
    if (wut == 1) {
      data = pgm_read_byte(&gImage[i]);
    } else {
       data = pgm_read_byte(&ajImage[i]);
    }
    SPI4W_WRITEDATA(~data); 
  } 
  SPI4W_WRITECOM(0x20); 
  entersleep(); 
} 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
  RESET(); 
  INIT_SPD2701(); //while(1);
  image_display(1); 
}
 
void loop() {
  delay(5000);
  image_display(2); 
  delay(5000);
  image_display(1); 
}
