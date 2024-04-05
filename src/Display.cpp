#include "Display.hpp"

Rectangle::Rectangle (mini8 cx, mini8 cy, mini8 ch, mini8 cl, uint16_t cColor, TFT_ILI9163C& Display_) :  
    x(cx), y(cy), h(ch), l(cl), color(cColor), display(Display_) {}

void Rectangle::setPosition(mini8 x_, mini8 y_){
    this->x = x_;
    this->y = y_;
    }

void Rectangle::setColor(mini16 color_){
    this->color = color_;
    }

void Rectangle::fillColor(mini16 color_){
    this->display.fillRect(this->x,this->y,this->l,this->h,color_);
    }

void Rectangle::fillColor(){
    this->display.fillRect(this->x,this->y,this->l,this->h,this->color);
}

void Rectangle::incrementX(){
    fillColor(BLACK);
    this->x++;
    fillColor();
}

void Rectangle::decrementX(){
    fillColor(BLACK);
    this->x--;
    fillColor();
}

void Rectangle::incrementY(){
    fillColor(BLACK);
    this->y++;
    fillColor();
}

void Rectangle::decrementY(){
    fillColor(BLACK);
    this->y--;
    fillColor();
}