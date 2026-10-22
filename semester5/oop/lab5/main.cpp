#include <iostream>
#include <windows.h>

using namespace std;

// Глобальная функция
void ff() {
    cout << "ff() из глобальной области" << endl;
}

// Базовый класс
class BASE {
public:
    int i;

    // Конструктор
    BASE(int a, long b, double c) {
        i = a;
        l = b;
        d = c;
    }

    // Деструктор
    ~BASE() {}

    // Доступ к закрытому полю
    double getD() const {
        return d;
    }

    const double* getDAddress() const {
        return &d;
    }

    void ff() {
        cout << "ff() из BASE" << endl;
    }

protected:
    long l;

private:
    double d;
};

// Производный класс
class DERIVED : public BASE {
private:
    float f;

public:
    // Конструктор без параметров
    DERIVED() : BASE(0, 0, 0) {
        f = 0;
    }

    // Конструктор с параметрами
    DERIVED(int a, long b, double c, float e) : BASE(a, b, c) {
        f = e;
    }

    // Деструктор
    ~DERIVED() {}

    void ff() {
        cout << "ff() из DERIVED" << endl;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const DERIVED& obj) {
        out << "i = " << obj.i << ", адрес: " << &obj.i << endl;
        out << "l = " << obj.l << ", адрес: " << &obj.l << endl;
        out << "d = " << obj.getD()
            << ", адрес: " << obj.getDAddress() << endl;
        out << "f = " << obj.f << ", адрес: " << &obj.f << endl;

        return out;
    }
};

// Класс без дополнительных полей
class DERIVED_1 : public DERIVED {
public:
    // Конструктор
    DERIVED_1(int a, long b, double c, float e) : DERIVED(a, b, c, e) {}

    // Деструктор
    ~DERIVED_1() {}

    void foo() {
        i++;
        l += 1;

        // Вызов одноимённых функций
        ::ff();
        BASE::ff();
        DERIVED::ff();
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Объект без параметров
    DERIVED obj1;

    cout << "Размер BASE: " << sizeof(BASE) << endl;
    cout << "Размер DERIVED: " << sizeof(DERIVED) << endl;

    // Объект с параметрами
    DERIVED obj2(10, 20, 3.5, 4.5f);

    cout << "\nОбъект obj1:" << endl;
    cout << obj1;

    cout << "\nОбъект obj2:" << endl;
    cout << obj2;

    // Объект класса DERIVED_1
    DERIVED_1 obj3(1, 2, 3.0, 4.0f);

    cout << "\nДо вызова foo():" << endl;
    cout << obj3;

    obj3.foo();

    cout << "\nПосле вызова foo():" << endl;
    cout << obj3;

    return 0;
}

/*
Сборка и запуск в PowerShell:

g++ -std=c++17 -finput-charset=UTF-8 -fexec-charset=UTF-8 main.cpp -o lab5.exe
.\lab5.exe
*/
