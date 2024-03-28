#ifndef DISPLAY_
#define DISPLAY_

#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

typedef uint8_t mInt;

class Rectangle
{
    private:
        uint8_t x, y; //coordenadas
        uint8_t h, l; //altura e largura
        uint16_t color;
        TFT_ILI9163C& display;

    public:
        Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, TFT_ILI9163C& Display_);
        void setPosition(mInt x_, mInt y_);
        void setColor(mInt color_);
        void fillColor(mInt color_);
        void fillColor();
};

#endif