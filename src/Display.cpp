#include "Display.hpp"

Display_obj::Display_obj(mInt cX, mInt cY, uint16_t cColor, TFT_ILI9163C& Display) : x(cX), y(cY),color(cColor), display(Display), original_color(cColor) {}

void Display_obj::setPosition(mInt x_, mInt y_){
    this->x = x_;
    this->y = y_;
}

void Display_obj::setColor(mInt color_){
    this->color = color_;
}

void Display_obj::incrementX(){
    this->x<MAX_X?this->x++:this->x=this->x;
}

void Display_obj::decrementX(){
    this->x>MIN_X?this->x--:this->x=this->x;
}

void Display_obj::incrementY(){
    this->y<MAX_Y?this->y++:this->y=this->y;
}

void Display_obj::decrementY(){
    this->y>MIN_Y?this->y--:this->y=this->y;
}



Rectangle::Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, TFT_ILI9163C& Display_) : Display_obj(cx, cy, cColor, Display_), h(ch), l(cl) {}

void Rectangle::fillColor(mInt color_){
    this->display.fillRect(this->x,this->y,this->l,this->h,color_);
}

void Rectangle::fillColor(){
    this->display.fillRect(this->x,this->y,this->l,this->h,this->original_color);
}