#ifndef DISPLAY_
#define DISPLAY_

#define MAX_X 126
#define MAX_Y 91
#define MIN_X 2
#define MIN_Y 1

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


class Display_obj
{
    protected:
        mInt x;
        mInt y;
        uint16_t color; //cor
        TFT_ILI9163C& display; //Display de referência onde será exibido o objeto

    public:
        Display_obj(mInt cX, mInt cY, uint16_t cColor, TFT_ILI9163C& Display);
        mInt getX();
        mInt getY();
        void setPosition(mInt x_, mInt y_); //Define a posição do objeto no display
        void setColor(mInt color_); //Define a cor do objeto
        virtual void fillColor(mInt color_); //Método polimófico virtual para preencher a forma com a cor especificada (virtual força que as classes derivadas implementem)
        virtual void fillColor(); //Método polimórfico virtual para preencher a forma com a cor dfinida pro objeto quando nenhuma cor adicional é especificada (virtual força que as classes derivadas implementem)     

        void incrementX(); //incrementa a posição do retângulo em 1 pixel na direção X
        void decrementX(); //decrementa a posição do retângulo em 1 pixel na direção X
        void incrementY(); //incrementa a posição do retângulo em 1 pixel na direção Y
        void decrementY(); //decrementa a posição do retângulo em 1 pixel na direção Y
        

};



class Rectangle : public Display_obj
{
    private:
        uint8_t h, l; //altura e largura

    public:
        Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, TFT_ILI9163C& Display_); //construtor da classe
        void fillColor(mInt color_) override; //Preenche o retângulo com a cor especificada (esse método suprime a declaração do mesmo método na classe base se existir)
        void fillColor() override; //Preenche o retângulo com a cor dfinida pro objeto quando nenhuma cor adicional é especificada (esse método suprime a declaração do mesmo método na classe base se existir)
};

#endif