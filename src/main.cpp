#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"
#include "Cursor.hpp"
#include "ShapeRandomizer.hpp"

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Joystick Joy(34,35,26);
Joystick Joy2(32,33,25);


Rectangle verm(50, 50, 3, 3, YELLOW, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle azul(1, 1, 3, 3, BLUE, tft);
Display_obj* randomico = ShapeRandomizer(tft);

Cursor cursor(Joy, &verm, YELLOW);
Cursor cursor2(Joy2, &azul, BLUE);

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
}

void loop(void){
    randomico->fillColor();
  if(Joy.get_button()&& abs(randomico->getX() - cursor.getX()) < 5 && abs(randomico->getY() - cursor.getY())<5){
    cursor.setShape(randomico); 
    randomico = ShapeRandomizer(tft);   
  }
  if(Joy2.get_button()&& abs(randomico->getX() - cursor2.getX()) < 5 && abs(randomico->getY() - cursor2.getY())<5){
    cursor2.setShape(randomico); 
    randomico = ShapeRandomizer(tft);   
  }
  cursor.move();
  cursor2.move();

  delay(50);
}
