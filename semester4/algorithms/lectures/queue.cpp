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
// с лекции 
void put(pQueue pQ, int value) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->value = value;
    p->next = NULL;

    if (pQ->end != NULL) pQ -> end -> next = p;
    else pQ -> beg = p;
    pQ->end = p;
    pQ->len++;
}
// с лекции 
int take(pQueue pQ) {
    pNode p = pQ -> beg;
    int value = p -> value;
    pQ -> beg = p -> next;
    free(p);
    pQ -> len--;
    return value;
}

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
        free(pp);
    }
}

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

void clearQueue(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        while (!isEmpty(pQ)) {
            take(pQ);
        }
    }
    free(pQ);
}

int main() {
    pQueue pQ = createQueue();

    for (int c = 0; c < 9; c++) put(pQ, 10);

    showQ(pQ);

    while (!isEmpty(pQ)) {
        take(pQ);
        showQ(pQ);
    }

    clearQueue(pQ);

    return 0;
}