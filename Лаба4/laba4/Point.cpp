#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

Point::Point() {
    cout<<"Input x for T1:\n";
    cin>>x;
    cout<<"Input y for T1:\n";
    cin>>y;
}

Point::Point(double x, double y) {
    SetX(x);
    SetY(y);
}

Point::Point(int quadrant) { //задання точки за чвертю
    srand(time(NULL));
    switch (quadrant) {
        case 1:
            SetX(round((double)rand()/RAND_MAX*10*10)/10);
            SetY(round((double)rand()/RAND_MAX*10*10)/10);
            break;
        case 2:
            SetX(round(((double)rand()/RAND_MAX*10-10)*10)/10);
            SetY(round((double)rand()/RAND_MAX*10*10)/10);
            break;
        case 3:
            SetX(round(((double)rand()/RAND_MAX*10-10)*10)/10);
            SetY(round(((double)rand()/RAND_MAX*10-10)*10)/10);
            break;
        case 4:
            SetX(round((double)rand()/RAND_MAX*10*10)/10);
            SetY(round(((double)rand()/RAND_MAX*10-10)*10)/10);
            break;
        default:
            cout<<"Incorrect quadrant in constructor!\n";
    }
}

double Point::GetX() {
    return x;
}

double Point::GetY() {
    return y;
}

void Point::SetX(double x) {
    this->x = x;
}

void Point::SetY(double y) {
    this->y = y;
}

int Point::GetQuadrant() { //знаходження якій чверті належить точка
    if (x > 0 && y > 0) return 1;
    else if (x < 0 && y > 0) return 2;
    else if (x < 0 && y < 0) return 3;
    else return 4;
}

Point& Point::operator++() { //інкремент X, префікс
    ++x;
    return (*this);
}

Point Point::operator++(int) { //інкремент Y, постфікс
    return {x, y++};
}

double operator-(Point p1, Point p2) { //знаходження відстані між точками
    return sqrt(pow(p2.GetX()-p1.GetX(), 2) + pow(p2.GetY()-p1.GetY(), 2));
}

void Show(Point p[]) {
    for(int i = 0;i<3;i++){
        cout<<"T"<<i+1<<": X -> "<<p[i].GetX()<<", Y -> "<<p[i].GetY()<<endl;
    }
}