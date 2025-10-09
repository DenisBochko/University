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
double factoriald(double n);
void Printd(int n);
int gcd(int n, int m);
int mgcd(int a, int b);
double rect_fact_do(int i, int m, double mult);
double rec_degree(double x, int n);
int sum(int* s, int n);

int main() {
    int a[3] = {1, 2, 3};

    cout << sum(a, 3);

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

/*

В точке вызова функции происходит прерывание для обслуживания работы функции: 
- выделяется область ОЗУ, которая называется стек функции
- в стеке функции размещается локальные переменные и формальные параметры (бывают фактические, при вызове и формальные, которые внутри тела функции)
- выполняется код функции
- по завершении работы функции стек уничтожается

Способы передачи параметров в функцию:
- по значению (копируются)
- через сслыку (&)
- через указатель (*)

*/

// Вычисление факториала без переполнения
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return factorial(n - 1) * n;
}

// Вычисление факториала без переполнения
double factoriald(double n) {
    if (n <= 1) {
        return 1;
    }

    return factoriald(n - 1) * n;
}

// Вычисление факториала на рекурсивном спуске
double rect_fact_do(int i, int m, double mult = 1) {
    mult = mult * i;

    if (i == m) return mult;
    return rect_fact_do(i + 1, m, mult); 
}

// Список (присваивание последнего справа элемента)
void list() {
    int a, b, c;

    a = (b = 1, c = 3, 12);
    printf("a = %d, b = %d, c = %d", a, b, c);
}

// Печатаем число в виде строки символов
/*
Printd(-123)

Стек:
1) выводим минус, вызываем 
2) 
*/
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

// Функция НОД из лекции
int NOD_rec(int n, int m) {
    if (!(n & m)) return m;
    else return NOD_rec(m, n % m);
}

// рекурсивные числа фиббоначи
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// вычисление суммы элементов массива
int sum(int* s, int n) {
    if (n == 1) return s[0];

    return sum(s, n - 1) + s[n - 1];
}

int countDigits(int n) {
    if (n < 10) return 1;            
    return 1 + countDigits(n / 10);
}






// 06.10
// Рекурсивное возведение в степень
// Если степень нечётная, то вызываем функцию со степенью -1
// Если степень чётная, то вызываем функцию со степенью /2
double rec_degree(double x, int n) {
    double r;
    if (!n) return 1;
    if (!(n % 2)) return r = rec_degree(x, n/2), r*r;
    else return x * rec_degree(x, n - 1);
}
