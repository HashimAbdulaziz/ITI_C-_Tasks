#include "Square.h"

Square::Square(){}
Square::Square(Point leftUpp, int side) : leftUpp(leftUpp), side(side){}



void Square::setLeftUpp(Point leftUpp){
    this->leftUpp = leftUpp;
}

void Square::setSide(int side){
    this->side = side;
}


Point Square::getLeftUpp(){
    return leftUpp;
}

int Square::getSide(){
    return side;
}





Square::~Square(){}
