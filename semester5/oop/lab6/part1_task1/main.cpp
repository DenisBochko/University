#include <iostream>
#include <cstring>

using namespace std;

class Base1 {
private:
    int i;
public:
    Base1() {
        i = 0;
        cout << "Конструктор Base1 без параметров" << endl;
    }
    Base1(int x) {
        i = x;
        cout << "Конструктор Base1 с параметром" << endl;
    }
    void put(int x) { i = x; }
    int get() { return i; }
};

class Base2 {
private:
    char name[20];
public:
    Base2() {
        strcpy(name, "Пусто");
        cout << "Конструктор Base2 без параметров" << endl;
    }
    Base2(char* text) {
        put(text);
        cout << "Конструктор Base2 с параметром" << endl;
    }
    void put(char* text) {
        strncpy(name, text, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Не даём строке выйти за границу массива
    }
    char* get() { return name; }
};

// Порядок наследования определяет порядок создания базовых частей.
class Derived : public Base2, public Base1 {
private:
    char ch;
public:
    Derived() : Base1(), Base2() {
        ch = 'V';
        cout << "Конструктор Derived без параметров" << endl;
    }

    // Даже если поменять Base2 и Base1 местами ниже,
    // первым всё равно будет создан Base1 (он первый в списке наследования).
    Derived(char c, char* text, int x) : Base1(x), Base2(text) {
        ch = c;
        cout << "Конструктор Derived с параметрами" << endl;
    }
    void put(char c) { ch = c; }
    char get() { return ch; }

    friend ostream& operator<<(ostream& out, Derived& obj) {
        // get() есть во всех трёх классах, поэтому указываем класс явно
        out << "i = " << obj.Base1::get() << endl;
        out << "name = " << obj.Base2::get() << endl;
        out << "ch = " << obj.get() << endl;
        return out;
    }
};

/*
clang++ /Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task1/main.cpp \
-o /Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task1/main && \
/Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task1/main
*/

int main() {
    cout << "Первый объект:" << endl;
    Derived a;
    cout << a;

    cout << "\nВторой объект:" << endl;
    char text[] = "Барсик";
    Derived b('B', text, 25);
    cout << b;
    return 0;
}
