#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle(Point c, double r) : center(c), radius(r) {}

Point Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }

void Circle::setCenter(Point c) { center = c; }
void Circle::setRadius(double r) { radius = r; }

void Circle::draw() const {
    cout << "Drawing Circle at (" << center.getX() << ", " << center.getY()
              << ") with radius " << radius << endl;
}

double Circle::area() const {
    return M_PI * radius * radius;
}
