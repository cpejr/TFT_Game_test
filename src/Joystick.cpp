#include "Joystick.hpp"
#include <Arduino.h>

Joystick::Joystick(int cpin_rX, int cpin_rY, int cpin_lX, int cpin_lY, int cbutton_l, int cbutton_r): 
    pin_rX(cpin_rX), pin_rY(cpin_rY), pin_lX(cpin_lX), pin_lY(cpin_lY), button_l(cbutton_l), button_r(cbutton_r){
        pinMode(pin_rX,INPUT);
        pinMode(pin_rY,INPUT);
        pinMode(pin_lX,INPUT);
        pinMode(pin_lY,INPUT);
        pinMode(button_l,PULLUP);
        pinMode(button_r,PULLUP);
    }

int Joystick::get_rX(){
    this->rX = (abs(((analogRead(34))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(34))/20.475)-100);
    return this->rX;
    }

int Joystick::get_rY(){
    this->rY = (abs(((analogRead(35))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(35))/20.475)-100);
    return this->rY;
    }

int Joystick::get_lX(){
    this->lX = (abs(((analogRead(32))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(32))/20.475)-100);
    return this->lX;
    }

int Joystick::get_lY(){
    this->lY = (abs(((analogRead(33))/20.475)-100)<DEAD_ZONE)? 0 : (((analogRead(33))/20.475)-100);
    return this->lY;
    }