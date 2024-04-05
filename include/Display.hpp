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

typedef uint8_t mInt;

class Rectangle
{
    private:
        uint8_t x, y; //coordenadas
        uint8_t h, l; //altura e largura
        uint16_t color; //cor
        TFT_ILI9163C& display; //Display de referência onde será exibido o objeto

    public:
        Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, TFT_ILI9163C& Display_); //construtor da classe
        void setPosition(mInt x_, mInt y_); //Define a posição do objeto no display
        void setColor(mInt color_); //Define a cor do objeto
        void fillColor(mInt color_); //Preenche o retângulo com a cor especificada
        void fillColor(); //Preenche o retângulo com a cor dfinida pro objeto quando nenhuma cor adicional é especificada
        void incrementX();
        void decrementX();
        void incrementY();
        void decrementY();
};

#endif