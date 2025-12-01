#ifndef POINT_H
#define POINT_H


class Point
{
    private:
        double x;
        double y;
    public:
        Point();

        void Point(double x, double y);

        void setX(double x);
        void setY(double y);

        double getX();
        double gety();


        virtual ~Point();
};

#endif // POINT_H
