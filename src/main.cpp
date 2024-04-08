#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"

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

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Rectangle Verm(127, 91, 3, 3, RED, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle cursor(1,1,3,3,BLUE, tft);
Joystick Joy(34,35,32,33,25,26);

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
}

void loop(void){

  Verm.fillColor();
  cursor.fillColor();

  // Serial.print(Joy.get_rX()); Serial.print(" "); Serial.print(Joy.get_rY()); Serial.print(" "); Serial.print(Joy.get_lX()); Serial.print(" "); Serial.println(Joy.get_lY());
  // Serial.print(Joy.get_buttonR()); Serial.print(" "); Serial.println(Joy.get_buttonL()); 

  if(Joy.get_rX()!=0 || Joy.get_rY()!=0){
    if(Joy.get_rX()>0){
      cursor.fillColor(BLACK);
      cursor.incrementX();
      cursor.fillColor();
    }
    if(Joy.get_rX()<0){
      cursor.fillColor(BLACK);
      cursor.decrementX();
      cursor.fillColor();
    }
    if(Joy.get_rY()>0){
      cursor.fillColor(BLACK);
      cursor.incrementY();
      cursor.fillColor();
    }
    if(Joy.get_rY()<0){
      cursor.fillColor(BLACK);
      cursor.decrementY();
      cursor.fillColor();
    }
  }

  if(Joy.get_lX()!=0 || Joy.get_lY()!=0){
    if(Joy.get_lX()>0){
      verm.fillColor(BLACK);
      Verm.incrementX();
      verm.fillColor(BLACK);
    }
    if(Joy.get_lX()<0){
      verm.fillColor(BLACK);
      Verm.decrementX();
      verm.fillColor(BLACK);
    }
    if(Joy.get_lY()>0){
      verm.fillColor(BLACK);
      Verm.incrementY();
      verm.fillColor(BLACK);
    }
    if(Joy.get_lY()<0){
      verm.fillColor(BLACK);
      Verm.decrementY();
      verm.fillColor(BLACK);
    }
  }
  delay(50);

}
