#include "Cursor.hpp"

Cursor::Cursor(Joystick& joystick_, Display_obj* Shape_, uint16_t color_): joystick(joystick_),Shape(Shape_), color(color_){
  Shape->setColor(color);
}

void Cursor::move(){
    Shape->fillColor();
    if(joystick.get_X()!=0 || joystick.get_Y()!=0){
    if(joystick.get_X()>0){
      Shape->incrementX();
    }
    if(joystick.get_X()<0){
      Shape->decrementX();
    }
    if(joystick.get_Y()>0){
      Shape->incrementY();
    }
    if(joystick.get_Y()<0){
      Shape->decrementY();
    }
  }
}

void Cursor::setShape(Display_obj* newShape_){
    newShape_->setPosition(Shape->getX(),Shape->getY());
    Shape->fillColor(BLACK);
    Shape = newShape_;      
    Shape->setColor(color);
}

int Cursor::getX(){
  return Shape->getX();
}

int Cursor::getY(){
  return Shape->getY();
}


