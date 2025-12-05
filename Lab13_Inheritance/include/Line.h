#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Point.h"
#include <cmath>

class Line : public Shape {
private:
    Point start;
    Point end;

public:
    Line(Point s, Point e);

    Point getStart() const;
    Point getEnd() const;

    void setStart(Point s);
    void setEnd(Point e);

    virtual void draw() const override;
    virtual double area() const override;

    double length() const;

    virtual ~Line() {}
};

#endif
