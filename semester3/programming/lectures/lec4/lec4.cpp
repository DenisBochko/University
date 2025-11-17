#include <iostream>
using namespace std;

void func1();

int main() {
    func1();
}

void func1() {
    char s[100];
    cout << "Введите число: ";
    cin >> s;

    int i = 0;
    int intDigits = 0;
    bool beforeDot = true;

    // Подсчёт цифр в целой части
    while (s[i] != '\0') {
        if (s[i] == '.') {
            beforeDot = false;
            break;
        }
        if (s[i] != '-') intDigits++;
        i++;
    }

    cout << "Целая часть числа " << s << " содержит " << intDigits << " цифр." << endl;

    // Печать строки в обратном порядке
    int len = 0;
    while (s[len] != '\0') len++;

    cout << "Обратный порядок: ";
    for (int j = len - 1; j >= 0; j--) {
        cout << s[j];
    }

    cout << endl;
}