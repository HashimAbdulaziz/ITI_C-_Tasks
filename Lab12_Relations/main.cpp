#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main()
{
    Point p1(10, 12);
    Point p2;
    p2.setX(13);
    p2.setY(18);

    Line l1(p1, p2);
    Line l2(8, 17, 4, 7);

    Point p3(20, 30);
    Square sq(p3, 10);

    Point p4(40, 60);
    Point p5(50, 70);
    Rectangle rec1(p4, 10, 5);

    Point p6(30, 15);
    Circle c1(p6, 5);



    return 0;
}
