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

void g() {
    int c = 0;
    int star_run = 0;

    while ((c = getchar()) != '.') {
        if (c == '*') {
            star_run++;
        } else {
            if (star_run > 0) {
                int out = star_run / 2;

                if (out == 0) {
                    putchar('*');
                } else {
                    for (int i = 0; i < out; i++) {
                        putchar('+');
                    }
                }
                
                star_run = 0;
            }

            putchar(c);
        }
    }

    // хвост
    if (star_run) {
        int out = star_run / 2;

        if (out == 0) {
            putchar('*');
        } else {
            for (int i = 0; i < out; i++) {
                putchar('+');
            }
        }
    }
}

void h() {
    int c;

    int in_digits = 0;      // сейчас внутри группы цифр?
    int seen_nonzero = 0;   // внутри текущей группы уже встречалась ненулевая цифра?
    int zero_count = 0;     // сколько ведущих нулей накопили (пока не печатаем)

    while ((c = getchar()) != '.') {
        if (isdigit(c)) {
            // встретили цифру
            if (!in_digits) {
                // начали новую группу
                in_digits = 1;
                seen_nonzero = 0;
                zero_count = 0;
            }

            if (!seen_nonzero) {
                if (c == '0') {
                    // ведущий ноль: пока просто копим счётчик и ничего не печатаем
                    zero_count++;
                } else {
                    // первая ненулевая цифра: печатаем её,
                    putchar(c);
                    seen_nonzero = 1;
                }
            } else {
                // уже была ненулевая: печатаем все последующие цифры как есть
                putchar(c);
            }

        } else {
            // встретили не цифру: группа закончилась
            if (in_digits) {
                if (!seen_nonzero && zero_count > 0) {
                    // вся группа была нулями, то печатаем один '0'
                    putchar('0');
                }
                // сбрасываем состояние группы
                in_digits = 0;
            }

            // сам нецифровой символ копируем как есть
            putchar(c);
        }
    }

    // хвост
    if (in_digits && !seen_nonzero && zero_count > 0) {
        putchar('0');
    }
}

// void i() {
//     int c0, c1, c2;

//     while ((c0 = getchar()) != '.') {
//         if (c2 == 't', c1 == 'h', c0 == 'e') {

//         }
//     }
// }

void l() {
    int c = 0;
    bool flag = false;
    while ((c = getchar()) != '.') {
        if (!flag && c == '{') {
            flag = true;
            continue;
        }

        if (flag && c == '}') {
            flag = false;
            continue;
        }

        if (flag) continue;

        putchar(c);
    }
}