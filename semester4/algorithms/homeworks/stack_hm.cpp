#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ======================== БАЗОВЫЙ КОД СТЕКА ========================

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct Stack {
    pNode top;
    int len;
} *pStack;

pStack createStack() {
    pStack pS = (pStack)malloc(sizeof(struct Stack));
    if (pS) {
        pS->top = NULL;
        pS->len = 0;
    }
    return pS;
}

int isEmpty(pStack pS) {
    if (pS->top && pS->len) return 0;
    return 1;
}

int push(pStack pS, int c) {
    pNode p = (pNode)malloc(sizeof(struct Node));
    if (p) {
        p->value = c;
        p->next = pS->top;
        pS->top = p;
        pS->len++;
        return 1;
    }
    return 0;
}

int pop(pStack pS) {
    pNode p = pS->top;
    int c = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return c;
}

// Получить значение вершины стека без извлечения
int peek(pStack pS) {
    return pS->top->value;
}

void showStack(pStack pS) {
    pStack qS = createStack();
    int c;
    if (isEmpty(pS)) printf("Stack is empty\n");
    else {
        while (!isEmpty(pS)) {
            c = pop(pS);
            printf("%d ", c);
            push(qS, c);
        }
        printf("\n");
        // Возвращаем элементы обратно в исходный стек
        while (!isEmpty(qS)) {
            c = pop(qS);
            push(pS, c);
        }
    }
    free(qS);
}

void clearStack(pStack pS) {
    while (!isEmpty(pS)) {
        pop(pS);
    }
}

// Вспомогательная функция: заполнить стек случайными числами от -50 до +50
void fillRandom(pStack pS, int n) {
    int i;
    for (i = 0; i < n; i++) {
        push(pS, rand() % 101 - 50);
    }
}

// Задание 1
// Разделить стек на положительные и отрицательные
void task1() {
    pStack src = createStack();
    pStack pos = createStack();    // положительные
    pStack neg = createStack();    // отрицательные
    pStack temp = createStack();   // вспомогательный для сохранения порядка

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    // порядок развернётся
    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    // порядок восстановится
    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c >= 0)
            push(pos, c);
        else
            push(neg, c);
    }

    printf("Положительные:  ");
    showStack(pos);
    printf("Отрицательные:  ");
    showStack(neg);

    clearStack(pos); free(pos);
    clearStack(neg); free(neg);
    clearStack(temp); free(temp);
    free(src);
}

// Задание 2
// Разделить на чётные и нечётные, вывести вершины
void task2() {
    pStack src = createStack();
    pStack even_s = createStack();   // чётные
    pStack odd_s = createStack();    // нечётные
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    // порядок развернётся
    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    // порядок восстановится
    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c % 2 == 0)
            push(even_s, c);
        else
            push(odd_s, c);
    }

    if (!isEmpty(even_s))
        printf("Вершина чётных: %d\n", peek(even_s));
    else
        printf("Вершина чётных: null\n");

    if (!isEmpty(odd_s))
        printf("Вершина нечётных: %d\n", peek(odd_s));
    else
        printf("Вершина нечётных: null\n");

    clearStack(even_s); free(even_s);
    clearStack(odd_s); free(odd_s);
    clearStack(temp); free(temp);
    free(src);
}

// Задание 3
// Перемещать из первого во второй, пока вершина первого не станет чётной
void task3() {
    pStack first = createStack();
    pStack second = createStack();

    fillRandom(first, 10);
    printf("Исходный стек: ");
    showStack(first);

    // Перемещаем элементы, пока вершина first не станет чётной
    while (!isEmpty(first) && (peek(first) % 2 != 0)) {
        push(second, pop(first));
    }

    pStack temp = createStack();
    while (!isEmpty(second)) {
        push(temp, pop(second));
    }
    while (!isEmpty(temp)) {
        push(second, pop(temp));
    }

    if (!isEmpty(first))
        printf("Вершина первого:  %d\n", peek(first));
    else
        printf("Вершина первого:  null\n");

    if (!isEmpty(second))
        printf("Вершина второго:  %d\n", peek(second));
    else
        printf("Вершина второго:  null\n");

    clearStack(first); free(first);
    clearStack(second); free(second);
    clearStack(temp); free(temp);
}

// Задание 4
// Удалить из стека все элементы с чётными значениями
void task4() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c % 2 != 0) {
            push(src, c);
        }
    }

    printf("После удаления чётных: ");
    showStack(src);

    clearStack(src); free(src);
    clearStack(temp); free(temp);
}

// Задание 5
// Удалить каждый второй элемент
void task5() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    int count = 1;
    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (count % 2 != 0) {
            push(src, c);
        }
        count++;
    }

    printf("После удаления каждого 2-го: ");
    showStack(src);

    clearStack(src); free(src);
    clearStack(temp); free(temp);
}

int main() {
    srand(time(NULL));

    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}