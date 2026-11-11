#include <iostream>
#include "new_fig.h"
using namespace std;

int main() {
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

/*
    clang++ -std=c++17 -Wall -Wextra -Wpedantic \
    -c /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/figure.cpp \
    -o /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/figure.o && \
    clang++ -std=c++17 -Wall -Wextra -Wpedantic \
    -c /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/triangle.cpp \
    -o /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/triangle.o && \
    clang++ -std=c++17 -Wall -Wextra -Wpedantic \
    -c /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/fig_main.cpp \
    -o /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/fig_main.o && \
    clang++ \
    /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/fig_main.o \
    /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/figure.o \
    /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/triangle.o \
    -o /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/main && \
    /Users/denis/Documents/programming/University/semester5/oop/lab6/part2_task2/main
 */