#ifndef CURSOR
#define CURSOR
#include "Display.hpp"
#include "Joystick.hpp"

class Cursor
{
    private:
        Joystick& joystick;
        Display_obj* Shape;
        uint16_t color;
    public:
        Cursor(Joystick& joystick_, Display_obj* Shape_, uint16_t color_);
        void move();
        void setShape(Display_obj* newShape_);
        int getX();
        int getY();
};


#endif