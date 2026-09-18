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
    // Вызывается при создании товара без параметров: Goods first;
    Goods() {
        name = "Без названия";
        date = "01.01.2026";
        price = 0;
        quantity = 0;
        invoiceNumber = 0;
        cout << "Вызван конструктор по умолчанию\n";
    }

    // Создает новый товар как копию существующего товара.
    // Ссылка & позволяет не создавать лишнюю копию other.
    Goods(const Goods& other) {
        name = other.name;
        date = other.date;
        price = other.price;
        quantity = other.quantity;
        invoiceNumber = other.invoiceNumber;
        cout << "Вызван конструктор копирования\n";
    }

    // Вызывается автоматически, когда объект прекращает существование.
    ~Goods() {
        cout << "Вызван деструктор для товара: " << name << '\n';
    }

    // Изменяет все данные уже созданного товара.
    void edit(string newName, string newDate, double newPrice, int newQuantity, int newInvoiceNumber) {
        name = newName;
        date = newDate;
        price = newPrice;
        quantity = newQuantity;
        invoiceNumber = newInvoiceNumber;
    }

    // Общая стоимость = цена одной единицы * количество.
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

    // Вызывается, если объект уже создан: third = first;
    Goods& operator=(const Goods& other) {
        name = other.name;
        date = other.date;
        price = other.price;
        quantity = other.quantity;
        invoiceNumber = other.invoiceNumber;
        cout << "Вызван оператор присваивания\n";
        return *this; // вернуть текущий объект
    }
};

// При передаче по значению создается копия first — параметр s.
Goods tovar(Goods s) {
    return s;
}

// s — второе имя переданного объекта, поэтому при входе копии нет.
// Но return s возвращает объект по значению, поэтому копия результата создается.
Goods tovarByReferenceParameter(Goods& s) {
    return s;
}

// Не создается ни копия параметра, ни новый объект-результат.
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

    Goods first; // конструктор по умолчанию
    first.edit("Ноутбук", "11.09.2026", 50000, 3, 101);
    first.show();
    cout << "Стоимость товара: " << first.cost() << "\n\n";

    cout << "Инициализация одного объекта другим:\n";
    Goods second = first; // вызывается конструктор копирования

    cout << "\nПрисваивание одному объекту другого:\n";
    Goods third; // third уже создан
    third = first; // поэтому вызывается оператор присваивания, а не конструктор копирования

    cout << "\nПередача в tovar по значению:\n";
    Goods fourth = tovar(first); // first передается по значению: внутри функции появляется копия s

    cout << "\nПередача параметра по ссылке:\n";
    Goods fifth = tovarByReferenceParameter(first); // first передается по ссылке, копии параметра нет

    cout << "\nПередача параметра и возврат по ссылке:\n";
    Goods& sixth = tovarByReference(first); // sixth — другое имя first, это не новый объект
    cout << "Стоимость товара по ссылке: " << sixth.cost() << '\n';

    cout << "\nВыход из функции main()\n";
    return 0;
}
