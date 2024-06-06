//Nesse arquivo são definidas as formas que aparecem na tela.

#ifndef DISPLAY_
#define DISPLAY_

/*As seguintes definições estipulam os limites do display onde as formas podem aparecer e se mover*/

#define MAX_X 160
#define MAX_Y 128
#define MIN_X 2
#define MIN_Y 13

/*As seguintes definições especificam as cores no formato uint16_t, em hexadecimal*/

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xFF00
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
/*A próxima definição apenas facilita a legibilidade do código*/

typedef uint8_t mInt;

/*A próxima classe define um objeto base para a forma a ser desenhada na tela. Ela, em si, não cria nenhuma forma, mas contém todas as propriedades e métodos
básicos que uma forma deve ter para que possa ser passada como parâmetro às outras funções e objetos*/

class Display_obj
{
    protected:
        mInt x; //Coordenada x da forma
        mInt y; //Coordenada y da forma
        uint16_t color; //cor
        Adafruit_ST7735& display; //Display de referência onde será exibido o objeto

    public:
        Display_obj(mInt cX, mInt cY, uint16_t cColor, Adafruit_ST7735& Display); //Construtor do objeto
        mInt getX(); //retorna a coordenada x da posição do objeto
        mInt getY(); //retorna a coordernada y da posição do objeto
        uint16_t getColor(); //retorna a cor do objeto, definida pelo construtor ou pelo método "setColor()"
        void setPosition(mInt x_, mInt y_); //Define a posição do objeto no display
        virtual void setColor(uint16_t color_); //Define a cor do objeto
        virtual void fillColor(uint16_t color_); //Método para preencher a forma com a cor especificada (virtual para que as classes derivadas implementem)
        virtual void fillColor(); //Método para preencher a forma com a cor dfinida pro objeto quando nenhuma cor adicional é especificada (virtual para que as classes derivadas implementem)     

        virtual void incrementX(); //incrementa a posição da forma em 1 pixel na direção X (virtual para que as classes derivadas implementem)
        virtual void decrementX(); //decrementa a posição da forma em 1 pixel na direção X (virtual para que as classes derivadas implementem)
        virtual void incrementY(); //incrementa a posição da forma em 1 pixel na direção Y (virtual para que as classes derivadas implementem)
        virtual void decrementY(); //decrementa a posição da forma em 1 pixel na direção Y (virtual para que as classes derivadas implementem)
        

};

/*A classe a seguir desenha um pequeno retângulo na tela*/

class Rectangle : public Display_obj
{
    private:
        uint8_t h, l; //altura e largura

    public:
        Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, Adafruit_ST7735& Display_); //construtor da classe
        void fillColor(uint16_t color_) override; //Preenche o retângulo com a cor especificada (esse método suprime a declaração do mesmo método na classe base se existir)
        void fillColor() override; //Preenche o retângulo com a cor dfinida pro objeto quando nenhuma cor adicional é especificada (esse método suprime a declaração do mesmo método na classe base se existir)
};

/*A classe a seguir desenha um pequeno círculo na tela*/

class Circle : public Display_obj
{
    private:
        uint8_t r; //raio

    public:
       Circle (mInt cx, mInt cy, mInt cr, uint16_t cColor, Adafruit_ST7735 &Display_); //Construtor da classe
       void fillColor(uint16_t color_) override; //Preenche o círculo com a cor especificada (esse método suprime a declaração do mesmo método na classe base, se existir)
       void fillColor() override; //Preenche o círculo com a cor definida pro objeto quando nenhuma cor adicional é especificada (esse método suprime a declaração do mesmo método na classe, base se existir)

};

/*A classe a seguir desenha um triângulo na tela*/

class Triangle : public Display_obj
{
    private:
        mInt x1, x2, x3, y1, y3; //coordenadas dos vértices do triângulo
    public:
        mInt  y2; //coordenada y do vértice inferior do triângulo. Definida separadamente para que possa ser alterada sem a necessidade de um método
        Triangle(mInt cx, mInt cy, uint16_t cColor, Adafruit_ST7735 &Display_); //construtor da classe
        void fillColor (uint16_t color_) override; //Preenche o triângulo com a cor especificada (esse método suprime a declaração do mesmo método na classe base, se existir)
        void fillColor () override; //Preenche o triângulo com a cor definida pro objeto quando nenhuma cor adicional é especificada (esse método suprime a declaração do mesmo método na classe, base se existir)
        void incrementX() override; //incrementa a posição do triângulo em 1 pixel na direção X
        void decrementX() override; //decrementa a posição do triângulo em 1 pixel na direção X
        void incrementY() override; //incrementa a posição do triângulo em 1 pixel na direção Y
        void decrementY() override; //decrementa a posição do triângulo em 1 pixel na direção Y

};

/*A classe a seguir desenha um coração na tela, feito a partir de dois círculos e um triângulo*/

class Heart : public Display_obj
{
    private:

        mInt circle1_x, circle2_x, triangle_x, circle1_y, circle2_y, triangle_y; //Coordenadas posicionais dos dois círculos e do triângulo
        mInt r = 2; //Raio do círculo
        Triangle* triangulo; //objeto triângulo usado na construção da forma utilizando a classe criada anteriormente

    public:
        Heart(mInt cx, mInt cy, uint16_t cColor, Adafruit_ST7735 &Display_); //Construtor da classe
        void fillColor (uint16_t color_) override; //Preenche o coração com a cor especificada (esse método suprime a declaração do mesmo método na classe base, se existir)
        void setColor(uint16_t color_) override; //Define a cor do coração
        void fillColor () override; //Preenche o coração com a cor definida pro objeto quando nenhuma cor adicional é especificada (esse método suprime a declaração do mesmo método na classe, base se existir)
        void incrementX() override; //incrementa a posição do coração em 1 pixel na direção X
        void decrementX() override; //decrementa a posição do coração em 1 pixel na direção X
        void incrementY() override; //incrementa a posição do coração em 1 pixel na direção Y
        void decrementY() override; //decrementa a posição do coração em 1 pixel na direção Y

}
;

#endif