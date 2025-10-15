#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>

using namespace std;

/*
int fact(int n) {
    if (n <= 1) return 1;
    return fact(n - 1) * n;
}

int main() {
    cout << fact(20);
    return 0;
}
*/

/*
В точке вызова функции происходит прерывание для обслуживания работы функции:
выделяется область оперативной памяти (стек функции).

В стеке функции размещаются локальные переменные и формальные параметры.
Дальше выполняется код функции. По завершении работы функции стек уничтожается.

Способы передачи параметров функции: по значению, через указатель, через ссылку
*/


// В стеке размещаются формальный параметры и локальные переменные 

/*
double Rec_Fact_Dn(int i, int m, double Mult = 1) {
    Mult = Mult * i;
    if (i == m) return Mult;
    return Rec_Fact_Dn(i + 1, m, Mult);
}

int main() {
    cout << Rec_Fact_Dn(3, 8, 1);
    return 0;
}
*/

/*
void Printd(int n) {
    if (n > 0) {
        putchar('-');
        n = -n;
    }

    if (n){
        Printd(n / 10);
        putchar(n % 10 + '0'), putchar(' ');
    }
}
*/

// Прототипы
void pop(int i);
void pop1(int i);
double Rec_Fact_Up(int n);
double Rec_Fact_Dn(int i, int m, double Mult = 1);
double rec_degree(double, int);
double rec_degree1(double, int);
void Printd(int n);
int NOD_iter(int, int);
int NOD_rec(int, int);
unsigned long fib(unsigned long n);
double sum(double s[], int n);
unsigned long F(int);
unsigned long G(int);
int Count_Char(int i, char* s, char c);
int Count_Number(int* a, int n, int num, int ii);
void Rec(int);
int Count_kc(int);
void p_10_2(int N);
void p_10_q(int N, int q);
double maxr(double s[], int n);

int main() {
    // Демо-блоки оставлены, но отключены:
    /*
    char str1[27] = "a";
    char str2[2];
    str2[1] = 0;
    cout << str2 << endl;
    for (str2[0] = 'b'; str2[0] <= 'z'; str2[0]++) {
        strcat_s(str1, str2);
        cout << str1 << '\n';
    }

    p_10_q(891, 16);
    cout << Count_kc(1234) << endl;
    cout << Rec_Fact_Up(8) << endl;
    cout << Rec_Fact_Dn(1, 8, 1.0) << endl;

    for (int i = 1; i < 31; i++) cout << fib(i) << " ";

    double x, y; int n;
    cout << "Input (x<=10)   Input (-90<=N<=90)? " << endl;
    cin >> x >> y >> n;
    y = rec_degree(x, abs(n));
    cout << x << " " << n << " " << (n > 0 ? y : 1 / y) << endl;
    y = rec_degree1(x, abs(n));
    cout << x << " " << n << " " << (n > 0 ? y : 1 / y) << endl;

    Printd(-231475);

    int a_ = 512, b_ = 96;
    cout << "Итер: " << NOD_iter(a_, b_) << endl;
    cout << "Рекур: " << NOD_rec(a_, b_) << endl;

    Rec(10);
    for (int i = 1; i < 30; i++)
        cout << fixed << "F(" << i << ")=" << F(i) << " G(" << i << ")=" << G(i) << endl;

    char s[20];
    cin.getline(s, 20);
    cout << s << endl;
    cout << Count_Char(0, s, s[1]);
    */

    // Текущее демо: массив случайных чисел и рекурсивный максимум
    srand(static_cast<unsigned>(time(nullptr)));

    double a[20];
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 101;
        cout << a[i] << " ";
    }
    cout << endl << maxr(a, 20) << endl;

    return 0;
}

// Реализации

void pop(int i) {
    if (i > 10) return;
    cout << i << ")  У попа была собака, он ее любил...!\n";
    pop(i + 1);
}

void pop1(int i) {
    cout << i << ")  У попа была собака, он ее любил...!\n";
    if (i < 10) pop1(i + 1);
    cout << i << "!!!!!\n";
}

double Rec_Fact_Up(int n) {
    if (n < 2) {
        cout << n << "=";
        return 1;
    }
    cout << n << "*";
    return Rec_Fact_Up(n - 1) * n;
}

double Rec_Fact_Dn(int i, int m, double Mult) {
    cout << i << (i != m ? "*" : "=");
    Mult *= i;
    if (i == m) return Mult;
    return Rec_Fact_Dn(i + 1, m, Mult);
}

double rec_degree(double x, int n) {
    if (n == 0) return 1;
    if ((n % 2) == 0) {
        double r = rec_degree(x, n / 2);
        cout << x << "^" << n / 2 << "=" << r << endl;
        return r * r;
    } else {
        double r = rec_degree(x, n - 1);
        cout << x << "^" << (n - 1) << "=" << r << endl;
        return x * r;
    }
}

double rec_degree1(double x, int n) {
    if (n == 0) return 1;

    if (n % 5 == 0) {
        double r = rec_degree1(x, n / 5);
        cout << x << "^" << n / 5 << " = " << r << endl;
        return r * r * r * r * r;
    } else if (n % 3 == 0) {
        double r = rec_degree1(x, n / 3);
        cout << x << "^" << n / 3 << " = " << r << endl;
        return r * r * r;
    } else if (n % 2 == 0) {
        double r = rec_degree1(x, n / 2);
        cout << x << "^" << n / 2 << " = " << r << endl;
        return r * r;
    } else {
        double r = rec_degree1(x, n - 1);
        cout << x << "^" << (n - 1) << " = " << r << endl;
        return x * r;
    }
}

void Printd(int n) {  // Печать целого числа в виде строки символов
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n) {
        Printd(n / 10);
        putchar(n % 10 + '0');
        putchar(' ');
    }
}

int NOD_iter(int n, int m) {
    int r;
    do {
        r = n % m;
        n = m;
        m = r;
        cout << "n=" << n << " m=" << m << endl;
    } while (r);
    return n;
}

int NOD_rec(int n, int m) {
    if ((n % m) == 0) return m;
    cout << "n=" << m << " m=" << n << endl;
    return NOD_rec(m, n % m);
}

unsigned long fib(unsigned long n) {
    if (n < 3) return 1;
    return fib(n - 1) + fib(n - 2);
}

// Делали на лабе
// 
unsigned long fib(int n) {
    if (n == 0 || n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}

double sum(double s[], int n) {
    if (n == 1) {
        cout << "n=" << n << "; sum=" << s[0] << endl;
        return s[0];
    }
    double x = sum(s, n - 1);
    cout << "n=" << n << "; sum=" << (x + s[n - 1]) << endl;
    return x + s[n - 1];
}

double maxr(double s[], int n) {
    if (n == 1) return s[0];
    double x = maxr(s, n - 1);
    return (x > s[n - 1]) ? x : s[n - 1];
}

unsigned long F(int n) {
    if (n == 1) return 1;
    return static_cast<unsigned long>(n) * G(n - 1);
}

unsigned long G(int n) {
    if (n == 1) return 2;
    return static_cast<unsigned long>(2 * n - 1) * F(n - 1);
}

int Count_Char(int i, char* s, char c) {
    // подсчет вхождений в строку символа c
    char ch = s[i];
    if (!ch) return 0;
    if (ch == c) return Count_Char(i + 1, s, c) + 1;
    return Count_Char(i + 1, s, c);
}

int Count_Number(int* a, int n, int num, int ii) {
    // подсчет кол-ва элементов массива, больших числа num
    if (ii == n) return 0;
    int add = (a[ii] > num) ? 1 : 0;
    return add + Count_Number(a, n, num, ii + 1);
}

void Rec(int n) {
    // простой рекурсивный вывод 1..n
    if (n <= 0) return;
    Rec(n - 1);
    cout << n << ' ';
}

int Count_kc(int n) {
    // количество цифр числа (для n=0 вернем 1)
    if (n == 0) return 1;
    n = std::abs(n);
    if (n < 10) return 1;
    return 1 + Count_kc(n / 10);
}

void p_10_2(int N) {
    // печать числа N в двоичной системе
    if (N < 2) {
        cout << N;
        return;
    }
    p_10_2(N / 2);
    cout << (N % 2);
}

void p_10_q(int N, int q) {
    // печать числа N в системе счисления с основанием q (2..36)
    const char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (q < 2 || q > 36) {
        cout << "[bad base]";
        return;
    }
    if (N < q) {
        cout << digits[N];
        return;
    }
    p_10_q(N / q, q);
    cout << digits[N % q];
}
