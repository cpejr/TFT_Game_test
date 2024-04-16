#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"
#include "Cursor.hpp"
#include "ShapeRandomizer.hpp"

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);
int ScoreA = 0;
int ScoreV = 0;

Joystick Joy(34,35,26);
Joystick Joy2(32,33,25);


Rectangle Verde(63, 12, 3, 3, GREEN, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle azul(4, 12, 3, 3, BLUE, tft);
Display_obj* randomico = ShapeRandomizer(tft);

Cursor cursor(Joy, &Verde, GREEN);
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
    randomico->fillColor(BLACK);
    cursor.setShape(randomico); 
    randomico = ShapeRandomizer(tft);
  tft.setCursor(63,1);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.print(ScoreV);
    ScoreV++;
  }
  if(Joy2.get_button()&& abs(randomico->getX() - cursor2.getX()) < 5 && abs(randomico->getY() - cursor2.getY())<5){
    randomico->fillColor(BLACK);
    cursor2.setShape(randomico); 
    randomico = ShapeRandomizer(tft);
  tft.setCursor(2,1);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.print(ScoreA);
    ScoreA++;
  }
  tft.setCursor(2,1);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print(ScoreA);

  tft.setCursor(63,1);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.print(ScoreV);

  tft.fillRect(1,9,130,1,WHITE);

  cursor.move();
  cursor2.move();

  delay(50);
}
