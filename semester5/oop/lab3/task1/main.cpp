#include <iostream>
#include <string>

using namespace std;

class Goods {
private:
    string name;       // наименование товара
    string date;       // дата оформления
    double price;      // цена 
    int quantity;      // количество единиц
    int invoiceNumber; // номер накладной, по которой товар поступил на склад

public:
    Goods() {
        name = "Без названия";
        date = "01.01.2026";
        price = 0;
        quantity = 0;
        invoiceNumber = 0;
        cout << "Вызван конструктор по умолчанию\n";
    }

    Goods(const Goods& other) {
        name = other.name;
        date = other.date;
        price = other.price;
        quantity = other.quantity;
        invoiceNumber = other.invoiceNumber;
        cout << "Вызван конструктор копирования\n";
    }

    ~Goods() {
        cout << "Вызван деструктор для товара: " << name << '\n';
    }

    void edit(string newName, string newDate, double newPrice, int newQuantity, int newInvoiceNumber) {
        name = newName;
        date = newDate;
        price = newPrice;
        quantity = newQuantity;
        invoiceNumber = newInvoiceNumber;
    }

    double cost() {
        return price * quantity;
    }

    void show() {
        cout << "Наименование: " << name << '\n';
        cout << "Дата оформления: " << date << '\n';
        cout << "Цена: " << price << '\n';
        cout << "Количество: " << quantity << '\n';
        cout << "Номер накладной: " << invoiceNumber << '\n';
    }

    Goods& operator=(const Goods& other) {
        name = other.name;
        date = other.date;
        price = other.price;
        quantity = other.quantity;
        invoiceNumber = other.invoiceNumber;
        cout << "Вызван оператор присваивания\n";
        return *this;
    }
};

// Передача и возврат по значению.
Goods tovar(Goods s) {
    return s;
}

// Передача параметра по ссылке, возврат по значению.
Goods tovarByReferenceParameter(Goods& s) {
    return s;
}

// Передача параметра и возврат результата по ссылке.
Goods& tovarByReference(Goods& s) {
    return s;
}

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab3/task1/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab3/task1/main && \
/Users/dabochko/Documents/University/semester5/oop/lab3/task1/main
*/

int main() {
    cout << "Вход в функцию main()\n\n";

    Goods first;
    first.edit("Ноутбук", "11.09.2026", 50000, 3, 101);
    first.show();
    cout << "Стоимость товара: " << first.cost() << "\n\n";

    cout << "Инициализация одного объекта другим:\n";
    Goods second = first;

    cout << "\nПрисваивание одному объекту другого:\n";
    Goods third;
    third = first;

    // cout << "\nПередача в tovar по значению:\n";
    Goods fourth = tovar(first);

    cout << "\nПередача параметра по ссылке:\n";
    Goods fifth = tovarByReferenceParameter(first);

    cout << "\nПередача параметра и возврат по ссылке:\n";
    Goods& sixth = tovarByReference(first);
    cout << "Стоимость товара по ссылке: " << sixth.cost() << '\n';

    cout << "\nВыход из функции main()\n";
    return 0;
}
