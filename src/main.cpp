#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"

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
#define DEAD_ZONE 10

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Rectangle Verm (127, 91, 3, 3, RED, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle cursor(1,1,3,3,BLUE, tft);

int rX = 0;
int rY = 0;
int lX = 0;
int lY = 0; 

class Joystick {

#define LIMITE_X_LEFT 2
#define LIMITE_X_RIGTH 127
#define LIMITE_Y_UP 96
#define LIMITE_Y_DOWN 0

  public:
  Joystick () : x(0), y(0) {}
  /*
  ____________
  |1         |      1 - posicao inicial do cursor
  |          |      2 - esquerda (-), direita (+)
  |          |      3 - cima (+), baixo (-)
  |__________|
  */

  void moveLeft(){
    if (this->x != LIMITE_X_LEFT){
        this->x--;
    }
    else{//limite da tela
    }
  }

  void moveRight(){
    if (this->x != LIMITE_X_RIGTH){
        this->x++;
    }
    else{//limite da tela
    }
  }

  void moveUp(){
    if (this->x != LIMITE_Y_UP){
        this->x++;
    }
    else{//limite da tela
    }
  }

  void moveDown(){
    if (this->x != LIMITE_Y_DOWN){
        this->x--;
    }
    else{//limite da tela
    }
  }
  
  mInt x, y;
};

// void pintarRetangulo(Rectangle &rect){
//   tft.fillRect(rect.x, rect.y, rect.l, rect.h, rect.color);
// }

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  pinMode(25,PULLUP);
  pinMode(26,PULLUP);


}

void loop(void){

  Verm.fillColor();
  cursor.fillColor();

    rX = (abs(((analogRead(34))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(34))/20.475)-100) ;
    rY = (abs(((analogRead(35))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(35))/20.475)-100) ;
    lX = (abs(((analogRead(32))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(32))/20.475)-100) ;
    lY = (abs(((analogRead(33))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(33))/20.475)-100) ;

  Serial.print(rX); Serial.print(" "); Serial.print(rY); Serial.print(" "); Serial.print(lX); Serial.print(" "); Serial.println(lY);

  if(rX!=0 || rY!=0){
    if(rX>0){
      cursor.incrementX();
    }
    if(rX<0){
      cursor.decrementX();
    }
    if(rY>0){
      cursor.incrementY();
    }
    if(rY<0){
      cursor.decrementY();
    }
  }

  if(lX!=0 || lY!=0){
    if(lX>0){
      Verm.incrementX();
    }
    if(lX<0){
      Verm.decrementX();
    }
    if(lY>0){
      Verm.incrementY();
    }
    if(lY<0){
      Verm.decrementY();
    }
  }
  delay(50);

}
