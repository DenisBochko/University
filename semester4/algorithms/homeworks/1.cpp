#include <iostream>

int main() {
    int x = 2;
    int y = 3;

    int* p = &x;
    int* q = &y;

    std::cout << "x: " << *p << ", y: " << *q << "\n";
    std::cout << "(p) значение: " << p << ", размер: " << sizeof(p) << "\n";
    std::cout << "(q) значение: " << q << ", размер: " << sizeof(q) << "\n";

    int** pp = &p;
    int** qq = &q;

    x = **qq;
    y = **pp;

    std::cout << "x: " << x << ", y: " << y << "\n";

    return 0;
}
