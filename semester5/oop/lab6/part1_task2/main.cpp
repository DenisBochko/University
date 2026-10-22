#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// virtual нужен, чтобы в Beefalo была ОДНА общая часть DomesticAnimal.
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
        // Явно выбираем ветви, иначе имя print неоднозначно.
        Cow::print();
        Buffalo::print();
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Cow cow(450, 90000, "коричневый");
    Beefalo beefalo(280, 70000, "чёрный");
    cout << "Корова:" << endl;
    cow.print();
    cout << "\nТеленок:" << endl;
    beefalo.print();
    return 0;
}
