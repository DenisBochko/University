#include <iostream>
using namespace std;
/*
Классы памяти c++
static - переменная инициализируется автоматически, не нужно дополнитьельно инициализировать
Регистровая - переменные будут обрабатываться как можно быстрее (могут быть только целочисленные переменные), типа храниться в регистре, но не факт
Внешняя - (глобальная (extern - берётся из другого файла))
*/

// Пример
void func(void) {
    // x будет инициализирована только при первом вызове.
    // значение y будет всегда делать 1 и 1++
    // значение x будет постоянно увеличиваться
    static int x = 1; // храниться в data сигменте 
    int y = 1; // храниться в стеке

    cout << x++ << "" << y++ << "/n";
}

/*
Рекурсивная функция (функция вызывает сама себя)

1) Постепенно сводим задачу к базовой.
2) Выполняем базовую задачу.

ВАЖНО! Глубина рекурсии не может быть бесконечной, закончиться память!
*/

// Пример1
void pop();
void pop1(int i);
int factorial(int n);
void Printd(int n);
int gcd(int n, int m);
int mgcd(int a, int b);
double sum(double s[], int n);

int main() {
    double s[5] = {1, 2, 3, 4, 5};
    cout << sum(s, 5);

    return 0;
}

void pop() {
    pop();
    cout << "Собака была...";
}

void pop1(int i) {
    cout << "Собака была...";

    if (i == 10) {
        return;
    }

    pop1(i + 1);
}

// Вычисление факториала
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return factorial(n - 1) * n;
}

// Список (присваивание последнего справа элемента)
void list() {
    int a, b, c;

    a = (b = 1, c = 3, 12);
    printf("a = %d, b = %d, c = %d", a, b, c);
}

// Печатаем число в виде строки символов
void Printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    if (n) {
        Printd(n / 10);
        putchar(n % 10 + '0');
    }
}

// Вычисление НОД (наибольший общий делитель) через инерационную и рекурсивную функкцию

// Рекурсивный 
int gcd(int n, int m) {
    while (n != m) {
        if (n > m) {
            n=n-m;
        } else {
            m = m - n;
        }
    }

    return n;
}

// Модернизированный алогоритм
int mgcd(int a, int b) {
    if (a == 0) return b < 0 ? -b : b;
    if (b == 0) return a < 0 ? -a : a;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// рекурсивные числа фиббоначи
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// вычисление суммы элементов массива
double sum(double s[], int n) {
    if (n == 1) return s[0];

    return sum(s, n - 1) + s[n - 1];
}
