#include "Rectangle.h"

Rectangle::Rectangle(){}
Rectangle::Rectangle(Point leftUpp, int width, int height) : leftUpp(leftUpp), width(width), height(height){}



void Rectangle::setLeftUpp(Point leftUpp){
    this->leftUpp = leftUpp;
}

void Rectangle::setWidth(int width){
    this->width = width;
}

void Rectangle::setHeight(int height){
    this->height = height;
}


Point Rectangle::getLeftUpp(){
    return leftUpp;
}

int Rectangle::getWidth(){
    return width;
}

int Rectangle::getHeight(){
    return height;
}


Rectangle::~Rectangle(){}
