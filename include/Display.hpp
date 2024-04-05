#ifndef DISPLAY_
#define DISPLAY_

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

typedef uint8_t mini8;
typedef uint16_t mini16;

class Rectangle
{
    private:
        uint8_t x, y; //coordenadas
        uint8_t h, l; //altura e largura
        uint16_t color; //cor
        TFT_ILI9163C& display; //Display de referência onde será exibido o objeto

    public:
        Rectangle (mini8 cx, mini8 cy, mini8 ch, mini8 cl, mini16 cColor, TFT_ILI9163C& Display_); //construtor da classe
        void setPosition(mini8 x_, mini8 y_); //Define a posição do objeto no display
        void setColor(mini16 color_); //Define a cor do objeto
        void fillColor(mini16 color_); //Preenche o retângulo com a cor especificada
        void fillColor(); //Preenche o retângulo com a cor dfinida pro objeto quando nenhuma cor adicional é especificada
        void incrementX();
        void decrementX();
        void incrementY();
        void decrementY();
};

#endif