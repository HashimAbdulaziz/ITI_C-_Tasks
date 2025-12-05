#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"
#include <cmath>

class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(Point c, double r);

    Point getCenter() const;
    double getRadius() const;

    void setCenter(Point c);
    void setRadius(double r);

    virtual void draw() const override;
    virtual double area() const override;

    virtual ~Circle() {}
};

#endif
