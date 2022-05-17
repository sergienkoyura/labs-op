#include "TTriangle.h"
#ifndef LABA5_PTRIANGLE_H
#define LABA5_PTRIANGLE_H
class PTriangle: public TTriangle{ // прямокутний трикутник
public:
    void print(); // наслідуємо від класу TTriangle атрибути (об'єкти класу точки) та методи
    double getSquare();
    PTriangle();
    PTriangle(Point, Point, Point);
};
#endif
