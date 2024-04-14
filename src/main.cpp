#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"
#include "Cursor.hpp"

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Rectangle whiteCursor(127, 91, 3, 3, WHITE, tft);
Joystick Joy(34,35,26);
Cursor cursor(Joy,&whiteCursor);


Rectangle verm(127, 91, 3, 3, RED, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle azul(1, 1, 10, 10, BLUE, tft);
Rectangle verd(12, 1, 10, 10, GREEN, tft);

Joystick Joy(34,35,26);
Cursor cursor(Joy,&whiteCursor);


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
  
  cursor.move();
  if(Joy.get_button()){
    tft.fillScreen(CYAN);
  }
  delay(50);
}
