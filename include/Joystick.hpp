#ifndef JOYSTICK_
#define JOYSTICK_
#define DEAD_ZONE 10 // O valor mínimo de inclinação do joystick até que ele retorne o primeiro valor


class Joystick
{
    private:
        int pin_X, pin_Y, button; //pinos do joystick (funciona como dois potenciômetros e um botões)
        int X, Y; //Inclinação do joystick

    public:
        Joystick(int cpin_X, int cpin_Y, int cbutton); //construtor da classe

        /*Os métodos abaixo retornam as inclinações dos joysticks, em porcentagem valores de -100 a 100,
        onde -100 o Joystick está totalmente inclinado pra esquerda (quando na direção X) ou para cima (quando na direção Y)
        e 100 indica que o Joystick está totalmente inclinado para a direita (quando na direção X) ou para baixo, (quando
        na direção Y). Zero indica que o Joystick está centralizado */

        int get_X();
        int get_Y();

        bool get_button(); //retorna o acionamento do botão sob o joystick
};


#endif