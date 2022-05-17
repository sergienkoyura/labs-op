#include "TTriangle.h"
#include "RBTriangle.h"
#include "RSTriangle.h"
#include "PTriangle.h"
#include "Point.h"


Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

string Point::toString() const { // перетворюємо інформацію про точку в рядок
    return "X: " + to_string(x) + "; Y: " + to_string(y) + ";\n";
}

Point::Point() : x(0), y(0) {}


TTriangle::TTriangle() : P1(0, 0), P2(0, 0), P3(0, 0) {}

double TTriangle::getA() {
    return sqrt(pow(P2.getX() - P1.getX(), 2) + pow(P2.getY() - P1.getY(), 2));;
}

double TTriangle::getB() {
    return sqrt(pow(P3.getX() - P1.getX(), 2) + pow(P3.getY() - P1.getY(), 2));;
}

double TTriangle::getC() {
    return sqrt(pow(P3.getX() - P2.getX(), 2) + pow(P3.getY() - P2.getY(), 2));;
}


RSTriangle::RSTriangle() {
    P1 = {0, 0};
    P2 = {0, 0};
    P3 = {0, 0};
}

double RSTriangle::getSquare() {
    return getA() * getA() * sqrt(3) / 4;
}

void RSTriangle::print() {
    cout << "RSTriangle:\n" << P1.toString() << P2.toString() << P3.toString();
}

RSTriangle::RSTriangle(Point p1, Point p2, Point p3) {
    P1 = p1;
    P2 = p2;
    P3 = p3;
}


PTriangle::PTriangle() {
    P1 = {0, 0};
    P2 = {0, 0};
    P3 = {0, 0};
}

double PTriangle::getSquare() {
    return 0.5 *
           (getA() > getB() ? (getA() > getC() ? getB() * getC() : getA() * getB()) : (getB() > getC() ? getC() * getA() : getA() * getB()));
}

void PTriangle::print() {
    cout << "PTriangle:\n" << P1.toString() << P2.toString() << P3.toString();
}

PTriangle::PTriangle(Point p1, Point p2, Point p3) {
    P1 = p1;
    P2 = p2;
    P3 = p3;
}


RBTriangle::RBTriangle() {
    P1 = {0, 0};
    P2 = {0, 0};
    P3 = {0, 0};
}

double RBTriangle::getPerimeter() {
    return getA() + getB() + getC();
}

void RBTriangle::print() {
    cout << "RBTriangle:\n" << P1.toString() << P2.toString() << P3.toString();
}

RBTriangle::RBTriangle(Point p1, Point p2, Point p3) {
    P1 = p1;
    P2 = p2;
    P3 = p3;
}

