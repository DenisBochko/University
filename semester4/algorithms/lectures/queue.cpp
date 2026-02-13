#include <iostream>

typedef struct Node {
    char val;
    struct Node* next;
} *pNode;

typedef struct Queue {
    Node* beg; // начало очереди 
    Node* end; // конец очереди
    int len;
} *pQueue;

// createQueue - создание пустой очереди
pQueue createQueue() {
    pQueue pQ;
    pQ = (pQueue)malloc(sizeof(Queue));

    // Зануляем поля 
    pQ->beg = NULL;
    pQ->end = NULL;
    pQ->len = 0;

    return pQ;
}

// isEmpty - очередь пустая или нет (предикат называется)
bool isEmpty(pQueue pQ) {  
    if (pQ->beg == NULL) return 1;
    
    return 0;
}
