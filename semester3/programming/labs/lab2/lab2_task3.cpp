#include <iostream>
#include <cstdio>

void a();
void b();
void c();
void d();
void e();
void f();
void g();

int main() {
    g();

    return 0;
}

void a() {
    int symbol, count = 0;

    while ((symbol = getchar()) != '.') {
        if (symbol == 'a') {
            count++;
        }
    }

    printf("Количество символов 'a':%d\n", count);
}

void b() {
    int symbol, count = 0;

    while ((symbol = getchar()) != '.') {
        if (symbol == 'e') {
            count++;
        }

        if (symbol == 'u') {
            break;
        }
    }

    printf("Количество символов 'e', перед 'u':%d\n", count);
}

void c() {
    int symbol1, symbol2, count = 0;

    while (true) {
        if ((symbol1 = getchar()) == '.') {
            break;
        } else if ((symbol2 = getchar()) == '.') {
            break;
        }

        if ((symbol1 == 'n' && symbol2 == 'o') || (symbol1 == 'o' && symbol2 == 'n')) {
            count++;
        }
    }

    printf("Количество сочетаний 'on' или 'no':%d\n", count);
}

void d() {
    int previous_symbol = 0, current_symbol = 0;
    int count_of_plus = 0, count_of_minus = 0, count_of_alternating = 0;

    while ((current_symbol = getchar()) != '.') {
        if (current_symbol == '+') {
            count_of_plus++;
        }

        if (current_symbol == '-') {
            count_of_minus++;
        }
 
        if ((previous_symbol == '-' && current_symbol == '+') || (previous_symbol == '+' && current_symbol == '-')) {
            count_of_alternating++;
        }

        previous_symbol = current_symbol;
    }

    printf("Количество плюсов: %d\n", count_of_plus);
    printf("Количество минусов: %d\n", count_of_minus);
    printf("Количество чередующихся: %d\n", count_of_alternating);
}

void e() {
    int previous_previous_symbol = 0, previous_symbol = 0, current_symbol = 0;
    int count = 0;

    while ((current_symbol = getchar()) != '.') {
        if (previous_previous_symbol == 'c' && previous_symbol == '+' && current_symbol == '+') {
            count++;
        }

        previous_previous_symbol = previous_symbol;
        previous_symbol = current_symbol;
    }
     
    printf("Количество 'c++': %d\n", count);
}

void f() {
    int c0 = -1, c1 = -1, c2 = -1, c3 = -1;
    int c;

    while ((c = getchar()) != '.') {
        c0 = c1; c1 = c2; c2 = c3; c3 = c;
        if (c0 == 'c' && c1 == 'h' && c2 == 'a' && c3 == 'r') {
            puts("YES");
            return;
        }
    }

    puts("NO");
}

void g() {
    // Реализовал только со строчными буквами.
    int max_len = 0, current_len = 0;
    int previous_symbol = 'a' - 1, current_symbol = 0;

    while ((current_symbol = getchar()) != '.') {
        if ((current_symbol - previous_symbol) == 1) {
            current_len++;
            previous_symbol = current_symbol;

            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }

            previous_symbol = 'a' - 1;
            current_len = 0;
        }
    }

    if (max_len > 0) {
        printf("Последовательность началась с латинского алфавита, максимальная длинна: %d\n", max_len);
    } else {
        puts("Последовательгость не началась с букв латинского алфавита\n");
    }
}

