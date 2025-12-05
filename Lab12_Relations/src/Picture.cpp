#include "Picture.h"

Picture::Picture() {
    lineCount = 0; recCount = 0; sqCount = 0; circCount = 0;

    lineMax = 50; recMax = 50; sqMax = 50; circMax = 50;

    lineArr = new Line[lineMax];
    recArr = new Rectangle[recMax];
    sqArr = new Square[sqMax];
    circArr = new Circle[circMax];
}

Picture::Picture(int lMax, int rMax, int sMax, int cMax) {
    lineCount = 0; recCount = 0; sqCount = 0; circCount = 0;

    lineMax = lMax;
    recMax = rMax;
    sqMax = sMax;
    circMax = cMax;

    lineArr = new Line[lineMax];
    recArr = new Rectangle[recMax];
    sqArr = new Square[sqMax];
    circArr = new Circle[circMax];
}

// --- Add Methods ---

void Picture::addLine(Line line){
    if(lineCount < lineMax){
        lineArr[lineCount] = line;
        lineCount++;
    }
}

void Picture::addRectangle(Rectangle rec){
    if(recCount < recMax){
        recArr[recCount] = rec;
        recCount++;
    }
}

void Picture::addSquare(Square sq){
    if(sqCount < sqMax){
        sqArr[sqCount] = sq;
        sqCount++;
    }
}

void Picture::addCircle(Circle circ){
    if(circCount < circMax){
        circArr[circCount] = circ;
        circCount++;
    }
}


void Picture::setLines(int count, Line* pLines){
    lineCount = (count > lineMax) ? lineMax : count;

    for(int i = 0; i < lineCount; i++){
        lineArr[i] = pLines[i];
    }
}

void Picture::setRects(int count, Rectangle* pRects){
    recCount = (count > recMax) ? recMax : count;

    for(int i = 0; i < recCount; i++){
        recArr[i] = pRects[i];
    }
}

void Picture::setSquares(int count, Square* pSquares){
    sqCount = (count > sqMax) ? sqMax : count;

    for(int i = 0; i < sqCount; i++){
        sqArr[i] = pSquares[i];
    }
}

void Picture::setCircles(int count, Circle* pCircles){
    circCount = (count > circMax) ? circMax : count;

    for(int i = 0; i < circCount; i++){
        circArr[i] = pCircles[i];
    }
}



Line* Picture::getLines(){
    return lineArr;
}

Rectangle* Picture::getRects(){
    return recArr;
}

Square* Picture::getSquares(){
    return sqArr;
}

Circle* Picture::getCircles(){
    return circArr;
}


Picture::~Picture()
{
    if(lineArr != nullptr) delete[] lineArr;
    if(recArr != nullptr) delete[] recArr;
    if(sqArr != nullptr) delete[] sqArr;
    if(circArr != nullptr) delete[] circArr;
}
