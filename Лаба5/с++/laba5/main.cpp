#include "RBTriangle.h"
#include "RSTriangle.h"
#include "PTriangle.h"
#include <ctime>
int main() {
    srand(time(NULL));
    cout << "How many triangles you want to create?\n";
    int n;
    cin >> n;
    PTriangle pArr[n]; //масиви об'єктів трикутників
    RSTriangle rsArr[n];
    RBTriangle rbArr[n];
    for (int i = 0; i < n; i++) {
        // генеруємо вершини прямокутного трикутника
        Point p1(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                 round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p2(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                   round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p3;
        p3.setX(p1.getX());
        p3.setY(p2.getY());
        pArr[i] = {p1, p2, p3};
    }
    for (int i = 0; i < n; i++) {
        // генеруємо вершини рівнобедренного трикутника
        Point p1(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                 round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p2(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                   round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p3;
        p3.setX(p1.getX() > p2.getX() ? p2.getX() - fabs(p1.getX() - p2.getX()) : fabs(p1.getX() - p2.getX()) + p2.getX());
        p3.setY(p1.getY());
        rbArr[i] = {p1, p2, p3};
    }
    for (int i = 0; i < n; i++) {
        // генеруємо вершини рівностороннього трикутника
        Point p1(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                 round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p2(round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10,
                   round(((double) rand() / RAND_MAX * 20 - 10) * 10) / 10),
                p3;
        p3.setX((p2.getX() - p1.getX()) * 0.5 - (p2.getY() - p1.getY()) * sqrt(3) / 2 + p1.getX());
        p3.setY((p2.getX() - p1.getX()) * sqrt(3) / 2 + (p2.getY() - p1.getY()) * 0.5 + p1.getY());
        rsArr[i] = {p1, p2, p3};
    }
    for (int i = 0; i < n; i++) {
        pArr[i].print();
    }
    cout << "------------------------\n";
    for (int i = 0; i < n; i++) {
        rsArr[i].print();
    }
    cout << "------------------------\n";
    for (int i = 0; i < n; i++) {
        rbArr[i].print();
    }
    cout << "------------------------\n";

    double sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += pArr[i].getSquare();
        sum2 += rsArr[i].getSquare();
        sum3 += rbArr[i].getPerimeter();
    }

    cout << "Sum of squares of right triangles: " << sum1 << ";\nSum of squares of equilateral triangles: " << sum2
         << ";\nSum of perimeters of isosceles triangles: " << sum3 << ".\n";
}
