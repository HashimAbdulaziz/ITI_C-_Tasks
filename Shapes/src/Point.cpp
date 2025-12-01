#include "Point.h"

Point::Point()
{
    public:
        Point();

        void Point(double x, double y) : x(x), y(y){

        }

        void setX(double x){ this->x = x; }
        void setY(double y){ this->y = y; }

        double getX(){ return this->x;}
        double gety(){ return this->y;}


        virtual ~Point();
}

Point::~Point()
{
    //dtor
}
