#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"
#include "Cursor.hpp"

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Rectangle Verm(127, 91, 3, 3, RED, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle Blue(1,1,10,3,BLUE, tft);
Joystick Joy(34,35,26);
Joystick Joy1(32,33,25);
Cursor cursor1(Joy,&Verm);
Cursor cursor2(Joy1,&Blue);

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
}

void loop(void){

  // Serial.print(Joy.get_rX()); Serial.print(" "); Serial.print(Joy.get_rY()); Serial.print(" "); Serial.print(Joy.get_lX()); Serial.print(" "); Serial.println(Joy.get_lY());
  // Serial.print(Joy.get_buttonR()); Serial.print(" "); Serial.println(Joy.get_buttonL());
  
  cursor1.move();
  if(Joy.get_button()){
    cursor1.setShape(&Blue);
  }
  delay(50);
}
