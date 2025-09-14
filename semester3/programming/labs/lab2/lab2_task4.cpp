#include <iostream>
#include <cstdio>

void a();
void b();
void c();
void d();
void e();
void f();
void g();
void h();
void i();
void j();
void k();
void l();

int main() {
    f();

    return 0;
}

void a() {
    int c;
    while ((c = getchar()) != '.') {
        if (c == '?') {
            putchar('!');
        } else {
            putchar(c);
        }
    }
}

void b() {
    int c;
    while ((c = getchar()) != '.') {
        if (c == '-') {
            continue;
        } else if (c == '&') {
            putchar(c);
        }

        putchar(c);
    }
}

void c() {
   int c;

    while ((c = getchar()) != '.') {
        if ((c >= 'a') && (c <= 'z')) {
            putchar(c);
        }
    } 
}

void d() {
    int c;

    while ((c = getchar()) != '.') {
        if ((c >= 'A') && (c <= 'Z')) {
            putchar(c + 32);
            continue;
        }

        putchar(c);
    }
}

void e() {
    int c;

    while ((c = getchar()) != '.') {
        if ((c >= 'a') && (c <= 'z')) {
            putchar(c - 32);
            continue;
        }

        putchar(c);
    }
}

void f() {
    bool flag = false;
    int c = 0;

    while ((c = getchar()) != '.') {
        if (c == '+') {
            if (!flag) { 
                putchar('+'); 
                flag = 1; 
            }
        } else {
            flag = 0;
            putchar(c);
        }
    }
}