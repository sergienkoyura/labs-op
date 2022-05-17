#include <iostream>
using namespace std;
#ifndef LABA5_POINT_H
#define LABA5_POINT_H
class Point{
    double x, y;
public:
    Point();
    Point(double, double);
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    string toString() const;
};

#endif
