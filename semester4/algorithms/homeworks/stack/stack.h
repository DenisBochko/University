#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct Stack {
    pNode top;
    int len;
} *pStack;

pStack createStack();
int isEmpty(pStack pS);
int push(pStack pS, int c);
int pop(pStack pS);
int peek(pStack pS); // Получить значение вершины стека без извлечения
void showStack(pStack pS);
void clearStack(pStack pS);
void fillRandom(pStack pS, int n); // Вспомогательная функция: заполнить стек случайными числами от -50 до +50

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task7_switch();
void task8();
void task9();
int evaluatePostfix(const char* expr);
void task10();
