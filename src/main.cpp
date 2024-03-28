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

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

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

class Rectangle{
  public:
    Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor) :  
        x(cx), y(cy), h(ch), l(cl), color(cColor) {} //construtor da classe

    uint8_t x, y; //coordenadas
    uint8_t h, l; //altura e largura
    uint16_t color;

    void setPosition(mInt x_, mInt y_){
      this->x = x_;
      this->y = y_;
    }

    void setColor(mInt color_){
      this->color = color_;
    }

    void fillColor(mInt color_){
      setColor(color_);
      tft.fillRect(this->x,this->y,this->l,this->h,color_);
    }
};

void pintarRetangulo(Rectangle &rect){
  tft.fillRect(rect.x, rect.y, rect.l, rect.h, rect.color);
}

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
}

void loop(void){

  Rectangle Verm (127, 91, 5, 1, RED); //coordenas (x,y), tamanho (h, l), cor
  pintarRetangulo(Verm);
  Rectangle cursor(1,1,3,3,BLUE);
  pintarRetangulo(cursor);

  for(int i=1; i<127; i++){
    for(int j=1; j<96; j++){
      cursor.fillColor(BLACK);
      cursor.setPosition(i,j);
      cursor.fillColor(BLUE);
      delay(10);
    }
  }


}
