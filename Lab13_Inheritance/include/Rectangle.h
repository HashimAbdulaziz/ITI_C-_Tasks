#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
protected:
    Point topLeft;
    double width;
    double height;

public:
    Rectangle(Point tl, double w, double h);

    void setWidth(double w);
    void setHeight(double h);

    double getWidth() const;
    double getHeight() const;

    virtual void draw() const override;
    virtual double area() const override;

    virtual ~Rectangle() {}
};

#endif
