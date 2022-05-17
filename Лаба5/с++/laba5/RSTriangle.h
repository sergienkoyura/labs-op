#include "TTriangle.h"
#ifndef LABA5_RSTRIANGLE_H
#define LABA5_RSTRIANGLE_H
class RSTriangle: public TTriangle{ //рівносторонній трикутник
public:
    void print(); // наслідуємо від класу TTriangle атрибути (об'єкти класу точки) та методи
    double getSquare();
    RSTriangle();
    RSTriangle(Point, Point, Point);
};
#endif
