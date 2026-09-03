#include <iostream>
#include <string>

using namespace std;

class Worker {
private:
    string name;
    string position;
    int start_year;
    double salary;

public:
    Worker(string n, string p, int year, double s) {
        set(n, p, year, s);
    }

    void set(string n, string p, int year, double s) {
        name = n;
        position = p;
        start_year = year;
        salary = s;
    }

    string get_name() {
        return name;
    }

    string get_position() {
        return position;
    }

    int get_start_year() {
        return start_year;
    }

    double get_salary() {
        return salary;
    }

    void show() {
        cout << "ФИО: " << name << endl;
        cout << "Должность: " << position << endl;
        cout << "Год поступления: " << start_year << endl;
        cout << "Зарплата: " << salary << "\n\n";
    }
};

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab1/task4/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab1/task4/main && \
/Users/dabochko/Documents/University/semester5/oop/lab1/task4/main
*/
int main() {
    const int current_year = 2026;

    Worker workers[5] = {
        Worker("Иванов И.И.", "Программист", 2010, 90000),
        Worker("Петров П.П.", "Менеджер", 2018, 70000),
        Worker("Сидоров С.С.", "Программист", 2020, 80000),
        Worker("Кузнецов К.К.", "Бухгалтер", 2012, 55000),
        Worker("Бочко Д.А.", "Человек-паук", 2026, 115)
    };

    cout << "Стаж более 10 лет:\n";

    for (int i = 0; i < 5; i++) {
        if (current_year - workers[i].get_start_year() > 10) {
            workers[i].show();
        }
    }

    cout << "Зарплата больше 60000:\n";
    for (int i = 0; i < 5; i++) {
        if (workers[i].get_salary() > 60000) {
            workers[i].show();
        }
    }

    cout << "Работники на должности Программист:\n";
    for (int i = 0; i < 5; i++) {
        if (workers[i].get_position() == "Программист") {
            workers[i].show();
        }
    }

    return 0;
}
