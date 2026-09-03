#include <iostream>
#include <string>

using namespace std;

class Stock {
private:
    string company_name; // название
    int shares;          // количество акций 
    double share_val;    // цена каждой акции
    double total_val;    // общая стоимость всех акций 

    void set_tot() {
        total_val = shares * share_val;
    }

public:
    Stock() {
        cout << "Вызван конструктор с дефолтами\n";
        company_name = "Без названия";
        shares = 0;
        share_val = 0;
        total_val = 0;
    }

    Stock(string name, int count, double price) {
        cout << "Вызван конструктор с параметрами\n";
        company_name = name;
        shares = count;
        share_val = price;
        set_tot();
    }

    ~Stock() {
        cout << "Вызван деструктор для " << company_name << '\n';
    }

    // acquire выполняет обработку первоначального вклада 
    void acquire(string name, int count, double price) {
        company_name = name;
        shares = count;
        share_val = price;
        set_tot();
    }

    // buy предназначена для приобретения дополнительных акций
    void buy(int count, double price) {
        if (count < 0) {
            cout << "Нельзя купить отрицательное количество акций\n";
            return;
        }

        shares += count;
        share_val = price;

        set_tot();
    }

    // sell предназначена для продажи акций;
    void sell(int count, double price) {
        if (count < 0) {
            cout << "Нельзя продать отрицательное количество акций\n";
        } else if (count > shares) {
            cout << "Недостаточно акций для продажи\n";
        } else {
            shares -= count;
            share_val = price;

            set_tot();
        }
    }

    // update корректирует стоимость одной акции и пересчитывает общую стоимость акций
    void update(double price) {
        share_val = price;
        set_tot();
    }

    void show() {
        cout << "Компания: " << company_name << endl;
        cout << "Количество акций: " << shares << endl;
        cout << "Цена акции: " << share_val << endl;
        cout << "Общая стоимость: " << total_val << "\n\n";
    }
};

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab1/task3/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab1/task3/main && \
/Users/dabochko/Documents/University/semester5/oop/lab1/task3/main
*/
int main() {
    Stock shares[5] = {
        Stock("Avito", 50, 120),
        Stock("Ozon", 10, 6500),
        Stock("Yandex", 70, 450),
        Stock("Amazon", 40, 230),
        Stock("Google", 5, 15000)
    };

    for (int i = 0; i < 5; i++) {
        shares[i].show();
    }

    return 0;
}
