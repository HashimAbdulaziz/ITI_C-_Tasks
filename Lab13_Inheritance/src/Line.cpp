#include "Line.h"
#include <iostream>
#include <cmath>

using namespace std;

Line::Line(Point s, Point e) : start(s), end(e) {}

Point Line::getStart() const { return start; }
Point Line::getEnd() const { return end; }

void Line::setStart(Point s) { start = s; }
void Line::setEnd(Point e) { end = e; }

void Line::draw() const {
    cout << "Drawing Line from ("  << start.getX() << ", " << start.getY()  << ") to ("
            << end.getX() << ", " << end.getY()
            << ")" << endl;
}

double Line::area() const {
    return 0.0;
}

double Line::length() const {
    double dx = end.getX() - start.getX();
    double dy = end.getY() - start.getY();
    return std::sqrt(dx * dx + dy * dy);
}
