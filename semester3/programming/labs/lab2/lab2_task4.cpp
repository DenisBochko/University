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
    k();

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
    int sr = 0;

    while ((c = getchar()) != '.') {
        if (c == '*') {
            sr++;
        } else {
            if (sr > 0) {
                int out = sr / 2;

                if (out == 0) {
                    putchar('*');
                } else {
                    for (int i = 0; i < out; i++) {
                        putchar('+');
                    }
                }
                
                sr = 0;
            }

            putchar(c);
        }
    }

    // хвост
    if (sr) {
        int out = sr / 2;

        if (out == 0) {
            putchar('*');
        } else {
            for (int i = 0; i < out; i++) {
                putchar('+');
            }
        }
    }
}

/*
asd123.
asd000012300sad012.
*/
void h() {
    int c;
    int fg = 0;     // внутри группы
    int fn = 0;     // встретили ненулевую цифру
    int zeros = 0;  // количество нулей в начале

    while ((c = getchar()) != '.') {
        if (isdigit(c)) {
            fg = 1;

            if (c == '0' && !fn) zeros++; // копим ведущие нули
            else {
                if (!fn) fn = 1;    // если до этого были нули, то просто их игнорируем
                putchar(c);         // печатаем первую ненулевую и все следующие
            }
        } else {
            if (fg) {
                if (!fn) putchar('0'); // группа состояла только из нулей
                fg = fn = zeros = 0;
            }

            putchar(c);
        }
    }

    // хвост
    if (fg) if (!fn) putchar('0');
}

void i() {
    int c;
    int a = 0, b = 0, d = 0;

    while ((c = getchar()) != '.') {
        a = b; b = d; d = c;

        if (a != 't' && b != 'h' && d != 'e') {
            if (a != 0) putchar(a);
        } else {
            b = 0; d = 0;
        }
    }
}

// asd0123asd321.
// asd0123asd
void j() {
    int ch;                      // текущий символ
    bool in_group = false;       // находимся ли внутри цифровой группы
    int first_digit = 0;         // код первой цифры группы ('0'..'9')
    int prev_digit = 0;          // код предыдущей цифры в группе
    int group_len = 0;           // длина текущей группы
    bool is_consecutive = true;  // каждая следующая = предыдущая + 1

    while ((ch = getchar()) != '.') {
        if (ch >= '0' && ch <= '9') {
            if (!in_group) {
                in_group = true;
                first_digit = ch;
                prev_digit = ch;
                group_len = 1;
                is_consecutive = true;
            } else {
                if (is_consecutive && ch == prev_digit + 1) {
                    prev_digit = ch;
                    group_len++;
                } else {
                    // всё ещё «в группе», но уже невалидной
                    prev_digit = ch;
                    group_len++;
                    is_consecutive = false;
                }
            }
        } else {
            // граница группы
            if (in_group && is_consecutive && group_len >= 2) {
                // печатаем весь диапазон от first_digit длиной group_len
                for (int i = 0; i < group_len; ++i) {
                    putchar(first_digit + i);
                }
            }
            in_group = false;
            putchar(ch); // нецифровой символ копируем как есть
        }
    }

    // разбор хвоста перед точкой
    if (in_group && is_consecutive && group_len >= 2) {
        for (int i = 0; i < group_len; ++i) {
            putchar(first_digit + i);
        }
    }
}

void k() {
    int a = 0, b = 0, c = 0, d = 0, e = 0;

    while ((e = getchar()) != '.') {
        putchar(e);
        
        if (a == 'c' && b == 'h' && c == 'i' && d == 'l' && e == 'd') {
            putchar('r'); putchar('e'); putchar('n'); 
        }

        a = b; b = c; c = d; d = e; 
    }
}

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