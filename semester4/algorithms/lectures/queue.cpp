#include <iostream>
#include <cstdlib> 

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct Queue {
    Node* beg, *end;
    int len;
} *pQueue;

pQueue createQueue() {
    pQueue pQ;
    pQ = (pQueue)malloc(sizeof(Queue));
    pQ->beg = NULL;
    pQ->end = NULL;
    pQ->len = 0;
    return pQ;
}

bool isEmpty(pQueue pQ) {
    if (pQ->len > 0) return false;
    return true;
}

int put(pQueue pQ, int v) {
    pNode p = (pNode)malloc(sizeof(Node));
    if (p) {
        p->value = v;
        p->next = NULL;

        if (isEmpty(pQ)) {
            // Очередь пуста — новый элемент и начало, и конец
            pQ->beg = p;
            pQ->end = p;
        } else {
            // Добавляем в конец
            pQ->end->next = p;
            pQ->end = p;
        }

        pQ->len++;
        return 1;
    }
    return 0;
}

// ========================
// Извлечение элемента из начала очереди (dequeue)
// ========================

int take(pQueue pQ) {
    if (isEmpty(pQ)) {
        cout << "Queue is empty, nothing to take!" << endl;
        return -1; // код ошибки
    }

    pNode temp = pQ->beg;
    int val = temp->value;

    pQ->beg = pQ->beg->next;
    pQ->len--;

    // Если очередь стала пустой — обнуляем и end
    if (pQ->beg == NULL) {
        pQ->end = NULL;
    }

    free(temp);
    return val;
}

// ========================
// Освобождение памяти очереди (самой структуры)
// ========================

void freeQueue(pQueue pQ) {
    free(pQ);
}

// ========================
// Просмотр без разрушения (вариант 1 — вспомогательная очередь)
// ========================

void showQ_D1(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        pQueue pp = createQueue();
        int c;
        while (!isEmpty(pQ)) {
            c = take(pQ);
            cout << c << " ";
            put(pp, c);
        }
        cout << "\n";
        // Возвращаем элементы обратно
        while (!isEmpty(pp)) {
            put(pQ, take(pp));
        }
        freeQueue(pp);
    }
}

// ========================
// Просмотр без разрушения (вариант 2 — через счётчик)
// ========================

void showQ_D2(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        int c;
        int k = pQ->len;
        for (; k > 0; k--) {
            c = take(pQ);
            cout << c << " ";
            put(pQ, c);
        }
        cout << "\n";
    }
}

// ========================
// Просмотр без разрушения (вариант 3 — просто обход указателей, без извлечения)
// ========================

void showQ(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        pNode current = pQ->beg;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

// ========================
// Очистка очереди
// ========================

void clearQueue(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        while (!isEmpty(pQ)) {
            take(pQ);
        }
    }
    freeQueue(pQ);
}

// ========================
// Главная функция для демонстрации
// ========================

int main() {
    pQueue myQueue = createQueue();

    // Добавляем элементы
    put(myQueue, 10);
    put(myQueue, 20);
    put(myQueue, 30);
    put(myQueue, 40);
    put(myQueue, 50);

    cout << "=== Очередь после добавления ===" << endl;
    showQ(myQueue);          // 10 20 30 40 50

    cout << "\n=== showQ_D1 (вспомогательная очередь) ===" << endl;
    showQ_D1(myQueue);       // 10 20 30 40 50

    cout << "\n=== showQ_D2 (через счётчик) ===" << endl;
    showQ_D2(myQueue);       // 10 20 30 40 50

    // Извлекаем два элемента
    cout << "\n=== Извлечение ===" << endl;
    cout << "take: " << take(myQueue) << endl;  // 10
    cout << "take: " << take(myQueue) << endl;  // 20

    cout << "\n=== Очередь после извлечения ===" << endl;
    showQ(myQueue);          // 30 40 50

    cout << "\nДлина очереди: " << myQueue->len << endl;

    // Очистка
    clearQueue(myQueue);

    return 0;
}