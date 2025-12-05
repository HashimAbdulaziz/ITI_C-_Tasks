#include "Rectangle.h"
#include <iostream>

using namespace std;


Rectangle::Rectangle(Point tl, double w, double h) : topLeft(tl), width(w), height(h) {}

void Rectangle::setWidth(double w) { width = w; }
void Rectangle::setHeight(double h) { height = h; }

double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }


void Rectangle::draw() const {
    cout << "Drawing Rectangle at (" << topLeft.getX() << ", " << topLeft.getY()
              << ") width=" << width
              << " height=" << height << endl;
}


double Rectangle::area() const {
    return width * height;
}
