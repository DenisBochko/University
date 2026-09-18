#include <cmath>
#include <iostream>

using namespace std;

// Расстояние между двумя точками на плоскости.
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Расстояние между двумя точками в пространстве.
double distance(double x1, double y1, double z1,
                double x2, double y2, double z2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) +
                (z2 - z1) * (z2 - z1));
}

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab4/task1/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab4/task1/main && \
/Users/dabochko/Documents/University/semester5/oop/lab4/task1/main
*/

int main() {
    // Треугольник на плоскости: (0, 0), (3, 0), (0, 4).
    double perimeter2D = distance(0, 0, 3, 0) +
                         distance(3, 0, 0, 4) +
                         distance(0, 4, 0, 0);
    cout << "Периметр треугольника в 2D: " << perimeter2D << '\n';

    // Треугольник в пространстве: (0, 0, 0), (3, 0, 0), (0, 4, 0).
    double perimeter3D = distance(0, 0, 0, 3, 0, 0) +
                         distance(3, 0, 0, 0, 4, 0) +
                         distance(0, 4, 0, 0, 0, 0);
    cout << "Периметр треугольника в 3D: " << perimeter3D << '\n';
}
