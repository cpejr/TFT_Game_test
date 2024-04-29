/*Nesse arquivo é criado o cursor*/

#ifndef CURSOR
#define CURSOR
#include "Display.hpp"
#include "Joystick.hpp"

/*Essa classe define um cursor associando uma forma do tipo Display_obj (e consequentemente de qualquer das suas classes derivadas)
e um joystick, de forma que a movimentação do joystick mova a forma pela tela*/

class Cursor
{
    private:
        Joystick& joystick; //Objeto joystick passado como referência
        Display_obj* Shape; //Objeto representando a forma a ser controlada pelo cursor. Ela é definida como um ponteiro para possibilitar que a forma controlada por um joystick possa ser trocada.
        uint16_t color; //A cor da forma controlada pelo cursor. Qualquer forma passada para esse cursor é preenchida com essa cor
    public:
        Cursor(Joystick& joystick_, Display_obj* Shape_, uint16_t color_); //Construtor da classe
        void move(); //Esse método associa a movimentação do joystick à movimentação do objeto. Ele checa a inclinação do joystick e move o objeto de forma correspondente.
        void setShape(Display_obj* newShape_); //Esse método possibilita trocar a forma do cursor
        int getX(); //Retorna a coordenada X do cursor
        int getY(); //Retorna a coordenada Y do cursor
};


#endif