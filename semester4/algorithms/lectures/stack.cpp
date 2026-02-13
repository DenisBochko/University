#include <iostream>
#include <cstdlib>

#define _SIZE 10

using namespace std;

// --- ЧАСТЬ 1: СТЕК НА ОСНОВЕ МАССИВА (Stck) ---

typedef struct Stck {
    int mas[_SIZE];
    int top, len;
};

void _init(struct Stck* St) {
    St->top = 0;
    St->len = 0;
};

void _print(struct Stck* St) {
    for (int i = St->top - 1; i >= 0; i--) {
        cout << St->mas[i] << " ";
    }
    cout << endl;
}

int _pop(struct Stck* St) {
    if (!St->len) {
        cout << "STACK IS EMPTY.";
        return 0;
    }
    St->top--;
    St->len--;
    cout << St->top << " "; // Вывод индекса вершины, как на скриншоте
    return St->mas[St->top];
}

void _push(struct Stck* St, int a) {
    if (St->len < _SIZE) {
        St->mas[St->top] = a;
        St->top++;
        St->len++;
    }
    else cout << "STACK IS FULL.";
};

// --- ЧАСТЬ 2: СТЕК НА ОСНОВЕ СВЯЗНОГО СПИСКА (Stack/pStack) ---

typedef struct Node {
    char value; // информационная часть
    struct Node* next; // указатель на след. узел стека
} *pNode;

typedef struct Stack {
    pNode top; // вершина стека
    int len;   // длина - кол-во элементов в стеке
} *pStack;

pStack createStack() {
    pStack pS = (pStack)malloc(sizeof(Stack));
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

int push(pStack pS, char c) {
    pNode p = (pNode)malloc(sizeof(Node));
    if (p) {
        p->value = c;
        p->next = pS->top;
        pS->top = p;
        pS->len++;
        return 1;
    }
    return 0;
}

char pop(pStack pS) {
    pNode p = pS->top;
    char c = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return c;
}

// Печать линейного списка (с использованием вспомогательного стека для сохранения порядка)
void showStack(pStack pS) {
    pStack qS = createStack();
    char c;
    if (isEmpty(pS)) printf("Stack is empty\n");
    else {
        while (!isEmpty(pS)) {
            c = pop(pS);
            cout << c << " ";
            push(qS, c);
        }
        cout << "\n";
        // Возвращаем элементы обратно в исходный стек
        while (!isEmpty(qS)) {
            c = pop(qS);
            push(pS, c);
        }
    }
}

// Этой функции не было на скриншоте, но она вызывается в main.
// Реализация добавлена логически.
void clearStack(pStack pS) {
    while (!isEmpty(pS)) {
        pop(pS);
    }
    // free(pS); // Можно раскомментировать, если нужно удалить и саму структуру стека
}

// --- ЧАСТЬ 3: MAIN ---

int main() {
    char c;
    Stck St;
    _init(&St);

    // Работа со стеком на массиве
    for (int j = 1, i = 11; i < 140; j++, i = 11 * j) {
        _push(&St, i);
        _print(&St);
    }

    cout << St.len << " ";
    _print(&St);

    for (int i = St.top; i; i--) {
        _pop(&St);
        _print(&St);
    }

    cout << "=====================================\n";

    // Работа со стеком на связном списке
    pStack pS = createStack();
    showStack(pS);

    for (c = 'a'; c <= 'z'; c += 2) {
        push(pS, c);
        showStack(pS);
    }

    while (!isEmpty(pS)) {
        showStack(pS);
        pop(pS);
    }

    showStack(pS);
    clearStack(pS);
    cout << "=====================================\n";

    return 0;
}