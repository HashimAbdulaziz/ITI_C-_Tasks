#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
    private:
        Point leftUpp;
        int width;
        int height;

    public:
        Rectangle();
        Rectangle(Point leftUpp, int width, int height);

        void setLeftUpp(Point leftUpp);
        void setWidth(int width);
        void setHeight(int height);


        Point getLeftUpp();
        int getWidth();
        int getHeight();


        ~Rectangle();
};

#endif
