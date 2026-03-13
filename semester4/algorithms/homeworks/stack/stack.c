#include "stack.h"

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
