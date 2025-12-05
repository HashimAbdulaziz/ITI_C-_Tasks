#include "Point.h"

Point::Point() : x(0), y(0){}

Point::Point(int x, int y) : x(x), y(y){}


void Point::setX(int x){
    this->x = x;
}


void Point::setY(int y){
    this->y = y;
}


int Point::getX() const {
    return this->x;
}


int Point::getY() const {
    return this->y;
}


Point::~Point(){}
