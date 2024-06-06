#include "Display.hpp"

Display_obj::Display_obj(mInt cX, mInt cY, uint16_t cColor, Adafruit_ST7735& Display) : x(cX), y(cY),color(cColor), display(Display) {}

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

void Display_obj::setColor(uint16_t color_){
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

void Display_obj::fillColor(uint16_t color_){}
void Display_obj::fillColor(){}

Rectangle::Rectangle (mInt cx, mInt cy, mInt ch, mInt cl, uint16_t cColor, Adafruit_ST7735& Display_) : Display_obj(cx, cy, cColor, Display_), h(ch), l(cl) {}

void Rectangle::fillColor(uint16_t color_){
    this->display.fillRect(this->x,this->y,this->l,this->h,color_);
}

void Rectangle::fillColor(){
    this->display.fillRect(this->x,this->y,this->l,this->h,color);
}

Circle::Circle (mInt cx, mInt cy, mInt cr, uint16_t cColor, Adafruit_ST7735 &Display_):
    Display_obj(cx, cy, cColor, Display_), r(cr) {}

void Circle::fillColor(uint16_t color_) {
    this->display.fillCircle(this->x, this->y, this->r, color_);
}

void Circle::fillColor(){
    this->display.fillCircle(this->x, this->y, this->r,this->color);
}

Triangle :: Triangle (mInt cx, mInt cy, uint16_t cColor, Adafruit_ST7735 &Display_):
    Display_obj(cx, cy, cColor, Display_) {
        x1 = x-3;
        x2 = x;
        x3 = x+3;
        y1 = y-2;
        y2 = y+3;
        y3 = y-2;
    }

void Triangle::fillColor(uint16_t color_){
    this->display.fillTriangle(x1, y1, x2, y2, x3, y3, color_);
}

void Triangle::fillColor(){
    this->display.fillTriangle(x1, y1, x2, y2, x3, y3,this->color);
}

void Triangle::incrementX(){
    fillColor(BLACK);
    this->x<MAX_X?this->x++, x1++, x2++, x3++ :this->x=this->x;
    fillColor();
}

void Triangle::decrementX(){
    fillColor(BLACK);
    this->x>MIN_X?this->x--, x1--, x2--, x3-- :this->x=this->x;
    fillColor();
}

void Triangle::incrementY(){
    fillColor(BLACK);
    this->y<MAX_Y?this->y++, y1++, y2++, y3++ :this->y=this->y;
    fillColor();
}

void Triangle::decrementY(){
    fillColor(BLACK);
    this->y>MIN_Y?this->y--, y1--, y2--, y3--:this->y=this->y;
    fillColor();
}

Heart::Heart(mInt cx, mInt cy, uint16_t cColor, Adafruit_ST7735 &Display_):
    Display_obj(cx, cy, cColor, Display_) {
        circle1_x = x-3;
        circle1_y = y;
        circle2_x = x+1;
        circle2_y = y;
        triangle_x = x-1;
        triangle_y = y+3;
        triangulo = new Triangle(triangle_x,triangle_y,this->color,this->display);
        triangulo->y2 = triangle_y+2;
    }
void Heart::setColor(uint16_t color_){
    this->color = color_;
    triangulo->setColor(color_);
}

void Heart::fillColor(uint16_t color_){
    this->display.fillCircle(this->circle1_x, this->circle1_y, this->r, color_);
    this->display.fillCircle(this->circle2_x, this->circle2_y, this->r, color_);
    triangulo->fillColor(color_);
}

void Heart::fillColor(){
    this->display.fillCircle(this->circle1_x, this->circle1_y, this->r, this->color);
    this->display.fillCircle(this->circle2_x, this->circle2_y, this->r, this->color);
    triangulo->fillColor();
}

void Heart::incrementX(){
    fillColor(BLACK);
    if(this->x<MAX_X){
        this->x++;
        circle1_x++;
        circle2_x++;
        triangulo->incrementX();
    }
    fillColor();
}

void Heart::decrementX(){
    fillColor(BLACK);
    if(this->x>MIN_X){
        this->x--;
        circle1_x--;
        circle2_x--;
        triangulo->decrementX();
    }
    fillColor();
}

void Heart::incrementY(){
    fillColor(BLACK);
    if(this->y<MAX_Y){
        this->y++;
        circle1_y++;
        circle2_y++;
        triangulo->incrementY();
    }
    fillColor();
}

void Heart::decrementY(){
    fillColor(BLACK);
    if(this->y>MIN_Y){
        this->y--;
        circle1_y--;
        circle2_y--;
        triangulo->decrementY();
    }
    fillColor();
}



