#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

typedef uint8_t mInt;

// Color definitions
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

volatile int16_t curVal1 = 0;
volatile int16_t oldVal1 = 0;

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

class Rectangle{
  public:
    Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor) :  
        x(cx), y(cy), h(ch), l(cl), color(cColor) {} //construtor da classe

    uint8_t x, y; //coordenadas
    uint8_t h, l; //altura e largura
    uint16_t color;
};

void pintarRetangulo(Rectangle &rect){
  tft.fillRect(rect.x, rect.y, rect.l, rect.h, rect.color);
}

void drawPointerHelper(int16_t val,uint8_t x,uint8_t y,uint8_t r,uint16_t color) {

  float dsec, toSecX, toSecY;
  
  int16_t minValue = 0;
  int16_t maxValue = 255;
  
  int fromDegree = 150;//start
  int toDegree = 240;//end
  
  if (val > maxValue) val = maxValue;
  if (val < minValue) val = minValue;
  
  dsec = (((float)(uint16_t)(val - minValue) / (float)(uint16_t)(maxValue - minValue) * toDegree) + fromDegree) * (PI / 180);
  
  toSecX = cos(dsec) * (r / 1.35);
  toSecY = sin(dsec) * (r / 1.35);

  tft.drawLine(x, y, 1 + x + toSecX, 1 + y + toSecY, color);
  tft.fillCircle(x,y,2,color);
}

void faceHelper(uint8_t x,uint8_t y,uint8_t r,int from,int to,float dev){
  float dsec,fromSecX,fromSecY,toSecX,toSecY;
  int i;
  for (i = from;i <= to;i += 30) {
    dsec = i * (PI / 180);
    fromSecX = cos(dsec) * (r / dev);
    fromSecY = sin(dsec) * (r / dev);
    toSecX = cos(dsec) * r;
    toSecY = sin(dsec) * r;
    tft.drawLine(1 + x + fromSecX,1 + y + fromSecY,1 + x + toSecX,1 + y + toSecY,WHITE);
  }
}

void drawGauge(uint8_t x,uint8_t y,uint8_t r) {
  tft.drawCircle(x, y, r,WHITE);//draw instrument container
  faceHelper(x,y,r,126,390,1.3);//draw major ticks
  if (r > 15) faceHelper(x,y,r,150,375,1.1);//draw minor ticks

}

void drawNeedle(int16_t val,uint8_t x,uint8_t y,uint8_t r,uint16_t color,uint16_t bcolor){
  uint8_t i;
  if (curVal1 > oldVal1){
    for (i = oldVal1; i <= curVal1; i++){
      drawPointerHelper(i-1,63,63,63,bcolor);
      drawPointerHelper(i,63,63,63,color);
      if ((curVal1 - oldVal1) < (128)) delay(1);//ballistic
    }
  } 
  else {
    for (i = oldVal1; i >= curVal1; i--){
      drawPointerHelper(i+1,63,63,63,bcolor);
      drawPointerHelper(i,63,63,63,color);
      //ballistic
      if ((oldVal1 - curVal1) >= 128){
        delay(1);
      } else {
        delay(3);
      }
    }
  }
}

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
}

void loop(void){

  Rectangle Verm (1, 1, 2, 3, RED); //coordenas (x,y), tamanho (h, l), cor
  pintarRetangulo(Verm);


  /*for(int i= 0; i<3; i++){
        tft.setRotation(0);
        tft.fillScreen(RED);
        delay(1000);
        tft.fillScreen(BLUE);
        delay(1000);
        tft.fillScreen(GREEN);
        delay(1000);
        tft.fillScreen(CYAN);
        delay(1000);
        tft.fillScreen(MAGENTA);
        delay(1000);
        }
        
    for(int i= 0; i<10; i++){       
        tft.fillRect(0,0,128,80, GREEN);
        tft.fillRect(0,80,128,160, YELLOW);
        delay(1000);
        tft.fillRect(0,0,128,80, YELLOW);
        tft.fillRect(0,80,128,160, GREEN);
        delay(1000);
        }
        */
}
