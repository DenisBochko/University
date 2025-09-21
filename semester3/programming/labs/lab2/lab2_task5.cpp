#include <iostream>
#include <cstdio>

void a();
void b();

int main() {
    b();
    return 0;
}

// a+12.3456-b-0.456789+1.3-45678
// a+12.34-b-0.45+1.3-45678
void a() {
    int c;
    bool fg = false; // началась ли группа
    bool fd = false; // была ли точка
    int ln = 0;      // длина последовательности после точки

    while ((c = getchar()) != '$') {
        if (isdigit(c) || c == '.') {
            if (!fg) fg = true;

            if (fg && c == '.') fd = true;

            if (fd && ln <= 3) ln++;
            if (fd && ln > 3) continue;

            putchar(c);
        } else {
            if (fg) {
                fg = false;
                fd = false;
                ln = 0;
            }

            putchar(c);
        }
    }
}

// a-000123+bc+0000.0008-0000+0001.07
// a-123+bc+0.0008-0+1.07
void b() {
    int c;
    int p = 0;       // предыдущий символ
    bool fg = false; // началась ли группа
    bool fd = false; // была ли точка
    bool fz = false; // были ли ненулевая цифра

    while ((c = getchar()) != '$') {
        if (isdigit(c)) {
            if (!fg) {
                fg = true;
                if (p == '.') fd = true;
                fz = false;
            }

            if (fd) putchar(c);
            else {
                if (c != '0') {
                    putchar(c);
                    fz = true;
                }
            }
        } else {
            if (fg) {
                if (!fd && !fz) putchar('0');
                fg = false;
                fd = false;
                fz = false;
            }

            putchar(c);
        }
        p = c;
    }

    if (fg && !fd && !fz) putchar('0');
}
