#ifndef LINE_H
#define LINE_H
#include "Point.h"

class Line
{
    private:
        Point start;
        Point end;

    public:
        Line();
        Line(Point p1, Point p2);
        Line(int x1, int x2, int y1, int y2);

        void setStart(Point p1);
        void setEnd(Point p2);

        Point getStart();
        Point getEnd();

        ~Line();
};

#endif
