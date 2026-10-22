#include "new_fig.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

Triangle::Triangle(double x, double y, double z) {
    if (x <= 0 || y <= 0 || z <= 0 || x + y <= z || x + z <= y || y + z <= x) {
        cout << "Ошибка: такого треугольника не существует" << endl;
        exit(1);
    }
    a = x;
    b = y;
    c = z;
}
double Triangle::area() {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::show() {
    cout << "Треугольник: стороны = " << a << ", " << b << ", " << c
         << ", площадь = " << area() << endl;
}
