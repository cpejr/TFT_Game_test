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

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

Rectangle Verm (127, 91, 5, 1, RED, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle cursor(1,1,3,3,BLUE, tft);

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
}

void loop(void){

  Verm.fillColor();
  cursor.fillColor();

  for(int i=1; i<127; i++){
    for(int j=1; j<96; j++){
      cursor.fillColor(BLACK);
      cursor.setPosition(i,j);
      cursor.fillColor(BLUE);
      delay(10);
    }
  }


}
