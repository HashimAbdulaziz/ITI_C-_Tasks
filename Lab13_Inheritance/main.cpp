#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

int main() {
    Point p1(1, 2);
    Point p2(4, 6);
    Point p3(0, 0);

    Rectangle rect(p1, 5, 10);
    rect.draw();
    cout << "Rectangle area: " << rect.area() << "\n\n";

    Line line(p1, p2);
    line.draw();
    cout << "Line length: " << line.length() << "\n";

    Circle circle(p3, 3);
    circle.draw();
    cout << "Circle area: " << circle.area() << "\n";

    return 0;
}
