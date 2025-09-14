#include <iostream>
using namespace std;

void b();

int main() {
    // char c;
    // for (c='A'; c <= 'z'; c++) {
    //     cout << (int)c << " " << c << "\n";
    // }

    // return 0;
    b();
    return 0;
}

void a() {
    char c;
    while ((c = getchar()) != '.') {
        if (c == '?') c = '!';
        cout << c;
    }

    cout << c;
}

void b() {
    char c;
    while ((c = getchar()) != '.') {
        if (c == '&') cout << c;
        if (c != '-') cout << c;
    }
}

void c() {
    char c;
     while ((c = getchar()) != '.') {
        // if (c >= 'a' && c <= 'z') cout << c;
        if (islower(c)) cout << c;
    }
}

void d() {
    char c;
    while ((c = getchar()) != '.') {
        cout << c;
        if (c == '+') {
            while ((c = getchar()) == '+') {
                if (c == '.') break;
            }
        }
    }
}
