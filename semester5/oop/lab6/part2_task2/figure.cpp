#include "figure.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Figure::~Figure() {}

Circle::Circle(double r) {
    if (r <= 0) {
        cout << "Ошибка: радиус должен быть больше 0" << endl;
        exit(1);
    }
    radius = r;
}
double Circle::area() { return 3.14159 * radius * radius; }
void Circle::show() {
    cout << "Круг: радиус = " << radius << ", площадь = " << area() << endl;
}
const double* Circle::getRadiusAddress() const { return &radius; }

Rectangle::Rectangle(double side) : Rectangle(side, side) {}
Rectangle::Rectangle(double x, double y) {
    if (x <= 0 || y <= 0) {
        cout << "Ошибка: стороны должны быть больше 0" << endl;
        exit(1);
    }
    a = x;
    b = y;
}
double Rectangle::area() { return a * b; }
void Rectangle::show() {
    cout << (a == b ? "Квадрат" : "Прямоугольник")
         << ": стороны = " << a << ", " << b << ", площадь = " << area() << endl;
}
const double* Rectangle::getAAddress() const { return &a; }
const double* Rectangle::getBAddress() const { return &b; }
