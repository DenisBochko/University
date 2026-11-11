#include <iostream>
#include <string>

using namespace std;

class DomesticAnimal {
protected:
    double weight;
    double price;
    string color;
public:
    DomesticAnimal() {
        weight = 0;
        price = 0;
        color = "неизвестно";
    }
    DomesticAnimal(double w, double p, string c) {
        weight = w;
        price = p;
        color = c;
    }
    void print() {
        cout << "DomesticAnimal: вес = " << weight
             << ", цена = " << price << ", цвет = " << color << endl;
    }
};

// virtual - если общий предок встретится через несколько ветвей,
// то хранить его в объекте только один раз
class Cow : virtual public DomesticAnimal {
public:
    Cow() {}
    Cow(double w, double p, string c) : DomesticAnimal(w, p, c) {}
    void print() {
        cout << "Cow" << endl;
        DomesticAnimal::print();
    }
};

class Buffalo : virtual public DomesticAnimal {
public:
    Buffalo() {}
    Buffalo(double w, double p, string c) : DomesticAnimal(w, p, c) {}
    void print() {
        cout << "Buffalo" << endl;
        DomesticAnimal::print();
    }
};

class Beefalo : public Cow, public Buffalo {
public:
    Beefalo(double w, double p, string c) {
        // Не передаём параметры Cow и Buffalo.
        // Поля одной общей базовой части доступны здесь как protected.
        weight = w;
        price = p;
        color = c;
    }
    void print() {
        cout << "Beefalo" << endl;
        // Виртуальное наследование оставляет одну общую часть DomesticAnimal.
        DomesticAnimal::print();
    }
};

/*
clang++ /Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task2/main.cpp \
-o /Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task2/main && \
/Users/denis/Documents/programming/University/semester5/oop/lab6/part1_task2/main
*/

int main() {
    Cow cow(450, 90000, "коричневый");
    Beefalo beefalo(280, 70000, "чёрный");
    cout << "Корова:" << endl;
    cow.print();
    cout << "\nТеленок:" << endl;
    beefalo.print();
    
    return 0;
}
