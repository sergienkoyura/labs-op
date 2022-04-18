#include <iostream>
#include "Point.h"
int main() {
    Point T1, T2(3), T3(3.5, -2.2);
    Point T[3]{T1, T2, T3};
    cout<<"Started points:\n";
    Show(T);
    ++T[0];
    T[1]++;
    cout<<"Changed points:\n";
    Show(T);
    cout<<"The distance between T1 and T2 is "<<T[0]-T[1]<<endl;
    cout<<"T3 belongs to the "<<T[2].GetQuadrant()<<" quadrant"<<endl;
}
