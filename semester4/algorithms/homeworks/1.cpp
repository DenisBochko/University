#include <iostream>

void homework();
void castingExample();
void example2();
void homework2();

// Компилировать
/* 
clang++ semester4/algorithms/homeworks/1.cpp \
-o semester4/algorithms/homeworks/1 && \
./semester4/algorithms/homeworks/1
*/
int main() {
    homework2();

    return 0;
}

void homework() {
    int x = 2;
    int y = 3;

    int* p = &x;
    int* q = &y;

    std::cout << "x: " << *p << ", y: " << *q << "\n";
    std::cout << "(p) значение: " << p << ", размер: " << sizeof(p) << "\n";
    std::cout << "(q) значение: " << q << ", размер: " << sizeof(q) << "\n";

    int** pp = &p;
    int** qq = &q;

    x = **qq;
    y = **pp;

    std::cout << "x: " << x << ", y: " << y << "\n";
}

/*
Приведение типов указателей (casting)
т.к. указатель - это переменная, то его можно приводить к другому типу

(<тип указателя>*)<указатель>

кастинг удобен, когда необходимо получить часть переменной;
*/

// Пример
void castingExample() {
    int k = 6; 
    int* pk = &k;
    double d = 3.14;
    double* pd = &d;
    std::cout << "&k = " << pk << "; *pk = " << *pk << std::endl;
    std::cout << "&d = " << pd << "; *pd = " << *pd << std::endl;

    // pd = (double*)pk;
    // std::cout << "&d = " << pd << "; *pd = " << *pd << std::endl;

    pk = (int*)pd;
    std::cout << "&k = " << pk << "; *pk = " << *pk << std::endl;
}

// Вывести исодержимое байтов целого числа А
void example2() {
    int A = 371;
    int* pA = &A;

    printf("%d\n\n", *pA);

    char* pc = (char*)pA;

    for (int i = 0; i < sizeof(int); i++) {
        printf("%d\n", *pc); pc++;
    }
}

// Вывести в 16 с.с. значение байтов переменной ul
void homework2() {
    unsigned long ul = 0xAE13C7DD;
    unsigned long* pUl = &ul;

    unsigned char* pc = (unsigned char*)pUl;

    for (int i = 0; i < sizeof(ul); i++) {
        printf("%d байт = %02X\n", i, *pc); 
        pc++;
    }
}