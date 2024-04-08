#ifndef JOYSTICK_
#define JOYSTICK_
#define DEAD_ZONE 10


class Joystick
{
    private:
        int pin_rX, pin_rY, pin_lX, pin_lY, button_l, button_r; //pinos do joystick (funciona como quatro potenciômetros e dois botões)
        int rX, rY, lX, lY; //Inclinação do joystick

    public:
        Joystick(int cpin_rX, int cpin_rY, int cpin_lX, int cpin_lY, int cbutton_l, int cbutton_r); //construtor da classe

        /*Os quatro métodos abaixo retornam as inclinações dos joysticks, em porcentagem valores de -100 a 100,
        onde -100 o Joystick está totalmente inclinado pra esquerda (quando na direção X) ou para cima (quando na direção Y)
        e 100 indica que o Joystick está totalmente inclinado para a direita (quando na direção X) ou para baixo, (quando
        na direção Y) */
        
        int get_rX();
        int get_rY();
        int get_lX();
        int get_lY();
};


#endif