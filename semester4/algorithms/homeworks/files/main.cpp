#include <iostream>
#include <fstream>

using namespace std;

void write_file();
void read_file();
void append_file();
void sum_file();

int main() {
    int c;

    while (true) {
        cout << "\nМеню" << endl;
        cout << "1. Записать числа в файл" << endl;
        cout << "2. Прочитать файл" << endl;
        cout << "3. Дописать числа в файл" << endl;
        cout << "4. Сумма чисел в файле" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> c;

        switch (c) {
            case 1: write_file();  break;
            case 2: read_file();   break;
            case 3: append_file(); break;
            case 4: sum_file();    break;
            case 0: return 0;
            default: cout << "Неверный выбор!" << endl;
        }
    }

    return 0;
}

// Запись n чисел в файл
void write_file() {
    int i, n;
    double d;

    ofstream f("a.txt");
    cout << "Сколько чисел? n = ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "d = ";
        cin >> d;
        f << d << ' ';
    }
    f.close();
    cout << "Записано." << endl;
}

// Чтение и вывод всех чисел из файла 
void read_file() {
    double d;
    ifstream f("a.txt");
    if (!f) {
        cout << "Файл не найден!" << endl;
        return;
    }

    cout << "Содержимое файла: ";
    while (f >> d) {
        cout << d << ' ';
    }
    cout << endl;
    f.close();
}

// Дописать n чисел в конец файла
void append_file() {
    int i, n;
    double d;

    ofstream f("a.txt", ios::app);
    if (!f) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "Сколько чисел дописать? n = ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "d = ";
        cin >> d;
        f << d << ' ';
    }
    f.close();
    cout << "Дописано." << endl;
}

// Сумма всех чисел в файле
void sum_file() {
    double d, s = 0;
    ifstream f("a.txt");
    if (!f) {
        cout << "Файл не найден!" << endl;
        return;
    }

    while (f >> d) {
        s += d;
    }
    cout << "Сумма = " << s << endl;
    f.close();
}
