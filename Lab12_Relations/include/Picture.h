#ifndef PICTURE_H
#define PICTURE_H

#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

class Picture
{
    private:
        Line* lineArr;
        Rectangle* recArr;
        Square* sqArr;
        Circle* circArr;

        int lineCount, recCount, sqCount, circCount;
        int lineMax, recMax, sqMax, circMax;

    public:
        Picture();
        Picture(int lineMax, int recMax, int sqMax, int circMax);

        void addLine(Line line);
        void addRectangle(Rectangle rec);
        void addSquare(Square sq);
        void addCircle(Circle circ);

        void setLines(int count, Line* pLines);
        void setRects(int count, Rectangle* pRects);
        void setSquares(int count, Square* pSquares);
        void setCircles(int count, Circle* pCircles);

        Line* getLines();
        Rectangle* getRects();
        Square* getSquares();
        Circle* getCircles();

        virtual ~Picture();
};

#endif
