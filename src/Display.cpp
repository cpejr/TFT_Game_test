#include "Display.hpp"

Display_obj::Display_obj(mInt cX, mInt cY, uint16_t cColor, TFT_ILI9163C& Display) : x(cX), y(cY),color(cColor), display(Display) {}

mInt Display_obj::getX(){
    return this->x;
}
mInt Display_obj::getY(){
    return this->y;
}

uint16_t Display_obj::getColor(){
    return this->color;
}

void Display_obj::setPosition(mInt x_, mInt y_){
    this->x = x_;
    this->y = y_;
}

void Display_obj::setColor(mInt color_){
    this->color = color_;
}

void Display_obj::incrementX(){
    fillColor(BLACK);
    this->x<MAX_X?this->x++:this->x=this->x;
    fillColor();
}

void Display_obj::decrementX(){
    fillColor(BLACK);
    this->x>MIN_X?this->x--:this->x=this->x;
    fillColor();
}

void Display_obj::incrementY(){
    fillColor(BLACK);
    this->y<MAX_Y?this->y++:this->y=this->y;
    fillColor();
}

void Display_obj::decrementY(){
    fillColor(BLACK);
    this->y>MIN_Y?this->y--:this->y=this->y;
    fillColor();
}

void Display_obj::fillColor(mInt color_){}
void Display_obj::fillColor(){}

Rectangle::Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, TFT_ILI9163C& Display_) : Display_obj(cx, cy, cColor, Display_), h(ch), l(cl) {}

void Rectangle::fillColor(mInt color_){
    this->display.fillRect(this->x,this->y,this->l,this->h,color_);
}

void Rectangle::fillColor(){
    this->display.fillRect(this->x,this->y,this->l,this->h,this->color);
}

Circle::Circle (mInt cx, mInt cy, mInt cr, uint16_t cColor, TFT_ILI9163C &Display_):
    Display_obj(cx, cy, cColor, Display_), r(cr) {}

void Circle::fillColor(mInt color_) {
    this->display.fillCircle(this->x, this->y, this->r, color_);
}

void Circle::fillColor(){
    this->display.fillCircle(this->x, this->y, this->r,this->color);
}

Triangle :: Triangle (mInt cx, mInt cy, uint16_t cColor, TFT_ILI9163C &Display_):
    Display_obj(cx, cy, cColor, Display_) {
        x1 = x-2;
        x2 = x;
        x3 = x+2;
        y1 = y-2;
        y2 = y+2;
        y3 = y-2;
    }

void Triangle::fillColor(mInt color_){
    this->display.fillTriangle(x1, y1, x2, y2, x3, y3, color_);
}

void Triangle::fillColor(){
    this->display.fillTriangle(x1, y1, x2, y2, x3, y3,this->color);
}

void Triangle::incrementX(){
    fillColor(BLACK);
    this->x<MAX_X?x1++, x2++, x3++ :this->x=this->x;
    fillColor();
}

void Triangle::decrementX(){
    fillColor(BLACK);
    this->x>MIN_X?this->x1--, x2--, x3-- :this->x=this->x;
    fillColor();
}

void Triangle::incrementY(){
    fillColor(BLACK);
    this->y<MAX_Y?y1++, y2++, y3++ :this->y=this->y;
    fillColor();
}

void Triangle::decrementY(){
    fillColor(BLACK);
    this->y>MIN_Y?y1--, y2--, y3--:this->y=this->y;
    fillColor();
}




