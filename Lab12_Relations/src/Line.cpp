#include "Line.h"

Line::Line(){}

Line::Line(Point p1, Point p2) : start(p1), end(p2){}

Line::Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2){}


void Line::setStart(Point p1){
    start = p1;
}

void Line::setEnd(Point p1){
    end = p1;
}

Point Line::getStart(){
    return start;
}

Point Line::getEnd(){
    return end;
}

Line::~Line()
{

}
