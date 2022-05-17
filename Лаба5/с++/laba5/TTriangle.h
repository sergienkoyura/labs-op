#ifndef LABA5_TTRIANGLE_H
#define LABA5_TTRIANGLE_H


#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;
class TTriangle{
protected:
    Point P1, P2, P3; // використовуємо об'єкти класу точки як атрибути класу трикутника (вершини)
public:
    TTriangle();
    double getA(); // знаходимо сторони трикутника
    double getB();
    double getC();

    //створюємо абстрактні функції для їх перевизначення
    virtual double getPerimeter() {return 0;}
    virtual double getSquare() {return 0;}
    virtual void print() {}
};



#endif
