#ifndef CURSOR
#define CURSOR
#include <functional>
#include "Display.hpp"
#include "Joystick.hpp"

class Cursor
{
    private:
        Joystick& joystick;
        Display_obj* Shape;
    public:
        Cursor(Joystick& joystick_, Display_obj* Shape_);
        void move();
        void setShape(Display_obj* newShape_);
};


#endif