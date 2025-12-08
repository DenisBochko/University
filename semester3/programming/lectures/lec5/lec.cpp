#include <iostream>
#include <stdarg.h>
using namespace std;

// Создание собственного типа данных
typedef struct {
    int x, y;
} Point;

void f(Point A, Point B, Point C, Point D);
void f1(Point A, Point B, Point C, Point D);
int sum(int k, ...);
double multi(int k, ...);
void miniprint(char* format, ...);

int main() {
    Point A{0, 1}, B{0, 1}, C{0, 1}, D{0, 1};

    // f(A, B, C, D);
    // f1(A, B, C, D);

    // cout << "sum: " << sum(5, 3, 0, 4, 8, 1) << endl;

    // cout << "multiply: " << multi(3, 1, 4, 2, 1) << endl;

    miniprint((char*)"x = %d, y = %f\n", 10, 3.14);

    return 0;
}

/*

Функции с переменным числом параметров
Например, printf();

Некоторые вводные:
- Должна иметь хотя бы один явный параметр для выяснения адресов неявных параметров;
- Должны иметь механизм определения количества парамтров и их типов, для этого существует два способа.
Способ первый: информация о количестве использованных фактических параметров и их типов размещается в начале списка явных параметров.
Способ второй: в конце списка неявных параметров размещается специальный индикатор с уникальным значением, сигнализирущий о конце списка.
- Во всех случаях переход от первого параметра к последующему выполняется через инкрементирование указателя. Существует опасность выхода за границы при неограниченной инкрементации указателя;
- Необходимо знать и понимать правила размещения переменных в стеке функции: 
Классический подход: Большее значение адреса у первого параметра, остальные размещаются по убыванию (НО ЭТО ЗАВИСИТ ОТ КОМПИЛЯТОРА).

*/

void f(Point A, Point B, Point C, Point D) {
    Point* p = &A;

    cout << "f: &A = " << &A << " (" << ++p << ")" << endl; 
    cout << "f: &B = " << &B << " (" << ++p << ")" << endl; 
    cout << "f: &C = " << &C << " (" << ++p << ")" << endl; 
    cout << "f: &D = " << &D << " (" << ++p << ")" << endl; 
}

void f1(Point A, Point B, Point C, Point D) {
    Point* p = &D;

    cout << "f1: &D = " << &D << "(" << ++p << ")" << endl; 
    cout << "f1: &C = " << &C << "(" << ++p << ")" << endl;
    cout << "f1: &B = " << &B << "(" << ++p << ")" << endl; 
    cout << "f1: &A = " << &A << "(" << ++p << ")" << endl;  
}

/*
Это не работает

int sum(int k, ...) {
    int* pick = &k;
    int sum = 0;

    for (; k; k--) {
        sum += *(pick++);
    }

    return sum;
}
*/

int sum(int k, ...) {
    va_list pick;
    va_start(pick, k);

    int result = 0;

    for (int i = 0; i < k; i++) {
        int v = va_arg(pick, int);
        result += v;
    }

    va_end(pick);

    return result;
}

double multi(int k, ...) {
    va_list ptr;
    va_start(ptr, k);

    double m = 1.0;
    do {
        m *= k;
        k = va_arg(ptr, double);
    } while (k);

    va_end(ptr);
    return m;
}

void miniprint(char* format, ...) {
    va_list op;
    char* p;
    int ii;
    double dd;

    va_start(op, format);

    for (p = format; *p; p++) {
        if (*p != '%') {
            cout << *p;
        } else {
            switch (*++p) {
            case 'd':
                ii = va_arg(op, int);
                cout << ii;
                break;
            case 'f':
                dd = va_arg(op, double);
                cout << dd;
                break;
            }
        }
    }

    va_end(op);
}
