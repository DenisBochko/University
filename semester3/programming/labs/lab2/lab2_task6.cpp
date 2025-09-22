#include <iostream>
#include <cstdio>

using namespace std;

void check_type(int c);

int main() {
    check_type('A');
    
    return 0;
}

void check_type(int c) {
    bool flag = false;

    printf("%c - ", c);

    if (isalpha(c)) {
        if (flag) cout << ", ";
        cout << "латинская буква";
        flag = true;
    }

    if (isdigit(c)) {
        if (flag) cout << ", ";
        cout << "десятичная цифра";
        flag = true;
    }

    if (isxdigit(c)) {
        if (flag) cout << ", "; 
        cout << "шестнадцатиричная цифра";
        flag = true;
    }

    if (isalnum(c)) { 
        if (flag) cout << ", "; 
        cout << "латинская буква или цифра";
        flag = true;
    }

    if (iscntrl(c)) {
        if (flag) cout << ", "; 
        cout << "управляющий символ (0-0x1 F)";
        flag = true;
    }

    if (isprint(c)) {
        if (flag) cout << ", "; 
        cout << "печатаемый символ включая пробел";
        flag = true;
    }

    if (isspace(c)) {
        if (flag) cout << ", "; 
        cout << "пробел/новая строка/табуляция";
        flag = true;
    }

    if (isupper(c)) {
        if (flag) cout << ", "; 
        cout << "буква верхнего регистра";
        flag = true;
    }

    if (islower(c)) {
        if (flag) cout << ", "; 
        cout << "буква нижнего регистра";
        flag = true;
    }

    cout << ".\n";
}

void check_print() {
    
}