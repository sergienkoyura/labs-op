#include "TTriangle.h"
#ifndef LABA5_RBTRIANGLE_H
#define LABA5_RBTRIANGLE_H
class RBTriangle: public TTriangle{ // рівнобедренний трикутник
public:
    void print(); // наслідуємо від класу TTriangle атрибути (об'єкти класу точки) та методи
    double getPerimeter();
    RBTriangle();
    RBTriangle(Point, Point, Point);
};

#endif