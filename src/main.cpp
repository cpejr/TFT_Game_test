/*Os comentários estão na main e nos arquivos de cabeçalho (.hpp). Esse código cria um joguinho utilizando um ESP32, um display TFT (ILI9163C) e dois joysticks.
O jogo consiste em dois players disputarem quem move um cursor até uma forma randômica exibida na tela primeiro. O jogador que chegar a forma e clicar primeiro,
marca ponto e o seu cursor muda para a mesma forma do objeto em que ele clicou. Uma nova forma aparece na tela.*/

#include <Arduino.h>
#include <SPI.h>
#include "Display.hpp"
#include "Joystick.hpp"
#include "Cursor.hpp"
#include "ShapeRandomizer.hpp"

#define __CS 2
#define __DC 4

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC); //Display onde será exibido o joguinho

/*As pontuações dos dois jogadores*/
int ScoreA = 0;
int ScoreV = 0;

//A declaração dos dois joysticks
Joystick Joy(34,35,26); //pinos para X e Y e pino para o botão
Joystick Joy2(32,33,25);

//A declaração das formas iniciais dos cursores
Rectangle Verde(63, 12, 3, 3, GREEN, tft); //coordenas (x,y), tamanho (h, l), cor
Rectangle azul(4, 12, 3, 3, BLUE, tft);

Display_obj* randomico = ShapeRandomizer(tft); //A forma aleatória mostrada na tela

//Declaração dos dois cursores, nas cores verde e azul, com os objetos criados anteriormente
Cursor cursor(Joy, &Verde, GREEN);
Cursor cursor2(Joy2, &azul, BLUE);

void setup(){
  Serial.begin(115200);
  Serial.println("Hello!");
  tft.begin();
  tft.setBitrate(50000000);

  /*O pino a seguir quando colocado em LOW, reseta o display*/
  pinMode(14,OUTPUT);
  digitalWrite(14,HIGH);
}

void loop(void){
  //As formas são desenhadas no display na ordem que aparecem aqui. Formas desenhadas primeiro são encobertas por quaisquer formas desenhadas posteriormente na mesma posição.

  randomico->fillColor(); //Preenche a forma aleatória na tela. Isso faz com que ela sempre apareça no display.

  /*A lógica do IF a seguir é executada quando o botão do joystick é pressionado e o cursor está a no máximo a 5 pixels de distância do objeto randômico desenhado na tela.
  Quando executado, esse código altera a forma do cursor para a forma randômica exibida e imediatamente cria outra forma randômica na tela. Também atualiza a pontuação no topo do display*/
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

  /*Executa a mesma lógica anterior, mas para o cursor 2*/
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

  //Redesenha as potuações na tela a cada execução do loop
  tft.setCursor(2,1);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print(ScoreA);

  tft.setCursor(63,1);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.print(ScoreV);

  //Desenha uma linha branca para separar a área de pontuações da área onde os cursores podem se mover
  tft.fillRect(1,9,130,1,WHITE);

  //Possibilita a movimentação dos cursores em 1 pixel a cada execução do loop
  cursor.move();
  cursor2.move();

  //Esse delay basicamente define o tempo mínimo entre as execuções do loop e consequentemente entre as movimentações do cursor, portanto, define a velocidade do cursor.
  delay(50);
}
