#include <iostream>
#include <string>

using namespace std;

class Notebook;

class Abonent {
    friend class Notebook; // класс, которому разрешён доступ к private и protected данным другого класса.

    int id;
    string surname;
    string phone;

public:
    Abonent(int id, string surname, string phone) {
        this->id = id;
        this->surname = surname;
        this->phone = phone;
    }

    ~Abonent() {
        cout << "Удален абонент: " << surname << '\n';
    }
};

class Notebook {
public:
    void change(Abonent abonents[], int count, int id, string newPhone) {
        for (int i = 0; i < count; ++i) {
            if (abonents[i].id == id) {
                abonents[i].phone = newPhone;
                return;
            }
        }

        cout << "Абонент с номером " << id << " не найден\n";
    }

    void show(const Abonent abonents[], int count) const {
        cout << "Номер | Фамилия | Телефон\n";
        for (int i = 0; i < count; ++i) {
            cout << abonents[i].id << " | " << abonents[i].surname
                 << " | " << abonents[i].phone << '\n';
        }
    }
};

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab2/task2/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab2/task2/main && \
/Users/dabochko/Documents/University/semester5/oop/lab2/task2/main
*/

int main() {
    Abonent abonents[] = {
        {101, "Иванов", "+7-900-111-11-11"},
        {102, "Петров", "+7-900-222-22-22"},
        {103, "Сидоров", "+7-900-333-33-33"},
        {104, "Кузнецов", "+7-900-444-44-44"},
        {105, "Смирнов", "+7-900-555-55-55"},
    };
    const int count = sizeof(abonents) / sizeof(abonents[0]);

    Notebook notebook;
    notebook.change(abonents, count, 103, "+7-900-000-00-00");
    notebook.show(abonents, count);
}
