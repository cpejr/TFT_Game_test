/*Esse arquivo declara apenas uma função cujo papel é desenhar a forma aleatória na tela*/

#ifndef SHAPE_RANDOMIZER
#define SHAPE_RANDOMIZER
#include "Cursor.hpp"
#include "Display.hpp"
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

/*Essa função serve apenas para criar uma forma aleatória (e de cor aleatória) do tipo Display_obj (suas formas derivadas) em qualquer posição da tela*/

Display_obj* ShapeRandomizer(TFT_ILI9163C& Display);

#endif