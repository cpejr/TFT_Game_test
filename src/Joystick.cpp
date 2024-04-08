#include "Joystick.hpp"
#include <Arduino.h>

Joystick::Joystick(int cpin_X, int cpin_Y, int cbutton): 
    pin_X(cpin_X), pin_Y(cpin_Y), button(cbutton){
        pinMode(pin_X,INPUT);
        pinMode(pin_Y,INPUT);
        pinMode(button,INPUT_PULLUP);
}

int Joystick::get_X(){
    this->X = (abs(((analogRead(pin_X))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(pin_X))/20.475)-100);
    return this->X;
}

int Joystick::get_Y(){
    this->Y = (abs(((analogRead(pin_Y))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(pin_Y))/20.475)-100);
    return this->Y;
}

bool Joystick::get_button(){
    return !digitalRead(button);
}