#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

class Figure {
public:
    virtual double area() = 0; // Чисто виртуальная функция
    virtual void show() = 0;
    virtual ~Figure() {} // Удобно при работе через указатели Figure*
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) {
        if (r <= 0) {
            cout << "Ошибка: радиус должен быть больше 0" << endl;
            exit(1);
        }
        radius = r;
    }
    double area() override { return 3.14159 * radius * radius; }
    void show() override {
        cout << "Круг: радиус = " << radius << ", площадь = " << area() << endl;
    }
    const double* getRadiusAddress() const { return &radius; }
};

class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double side) : Rectangle(side, side) {}
    Rectangle(double x, double y) {
        if (x <= 0 || y <= 0) {
            cout << "Ошибка: стороны должны быть больше 0" << endl;
            exit(1);
        }
        a = x;
        b = y;
    }
    double area() override { return a * b; }
    void show() override {
        cout << (a == b ? "Квадрат" : "Прямоугольник")
             << ": стороны = " << a << ", " << b
             << ", площадь = " << area() << endl;
    }
    const double* getAAddress() const { return &a; }
    const double* getBAddress() const { return &b; }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Circle circle(3);
    Rectangle rectangle(4, 5);
    Rectangle square(6);

    cout << "Размер Circle: " << sizeof(circle) << endl;
    cout << "Объект Circle: " << &circle << ", radius: " << circle.getRadiusAddress() << endl;
    cout << "Размер Rectangle: " << sizeof(rectangle) << endl;
    cout << "Объект Rectangle: " << &rectangle
         << ", a: " << rectangle.getAAddress()
         << ", b: " << rectangle.getBAddress() << endl;

    // Figure f; // Ошибка компиляции: Figure — абстрактный класс.
    Figure* figures[] = {&circle, &rectangle, &square};
    cout << "\nВсе фигуры:" << endl;
    for (int i = 0; i < 3; i++) {
        figures[i]->show(); // Вызов версии метода реального типа фигуры
    }
    return 0;
}
