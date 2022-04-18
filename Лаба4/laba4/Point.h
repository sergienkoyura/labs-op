#ifndef LABA4_POINT_H
#define LABA4_POINT_H
#include <iostream>
using namespace std;
class Point {
    double x;
    double y;
public:
    Point(); //конструктор за замовчуванням
    Point(double, double); //з параметрами
    Point(int); //задається за чвертю
    double GetX();
    double GetY();
    void SetX(double);
    void SetY(double);
    int GetQuadrant(); //знаходимо якій чверті належить точка
    Point& operator++(); //префіксний інкремент для X
    Point operator++(int); //постфіксний інкремент для Y
    friend double operator-(Point, Point); //використовуємо дружню функцію щоб використати 2 параметри для знаходження відстані
};

void Show(Point[]); //виведення масиву точок

#endif //LABA4_POINT_H
