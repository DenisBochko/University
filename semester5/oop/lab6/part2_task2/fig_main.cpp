#include <iostream>
#include <windows.h>
#include "new_fig.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Circle circle(3);
    Rectangle rectangle(4, 5);
    Rectangle square(6);
    Triangle triangle(3, 4, 5);

    cout << "Circle: размер = " << sizeof(circle) << ", объект = " << &circle
         << ", radius = " << circle.getRadiusAddress() << endl;
    cout << "Rectangle: размер = " << sizeof(rectangle) << ", объект = " << &rectangle
         << ", a = " << rectangle.getAAddress()
         << ", b = " << rectangle.getBAddress() << endl;
    cout << "Triangle: размер = " << sizeof(triangle) << ", объект = " << &triangle << endl;

    Figure* figures[] = {&circle, &rectangle, &square, &triangle};
    cout << "\nВсе фигуры:" << endl;
    for (int i = 0; i < 4; i++) {
        figures[i]->show();
    }
    // Figure f; // Ошибка: абстрактный класс.
    return 0;
}
