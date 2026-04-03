#include "queue.h"

pQueue createQueue() {
    pQueue pQ = (pQueue)malloc(sizeof(struct Queue));
    pQ->beg = NULL;
    pQ->end = NULL;
    pQ->len = 0;
    return pQ;
}

int isEmpty(pQueue pQ) {
    if (pQ->len > 0) return 0;
    return 1;
}
// с лекции 
void put(pQueue pQ, int value) {
    pNode p = (pNode)malloc(sizeof(struct Node));
    p->value = value;
    p->next = NULL;

    if (pQ->end != NULL) pQ -> end -> next = p;
    else pQ -> beg = p;
    pQ->end = p;
    pQ->len++;
}
// с лекции 
int take(pQueue pQ) {
    pNode p = pQ->beg;
    int value = p->value;
    pQ->beg = p->next;
    free(p);
    pQ->len--;
    if (pQ->beg == NULL)
        pQ->end = NULL;
    return value;
}

void showQ_D1(pQueue pQ) {
    if (isEmpty(pQ)) puts("Queue is empty");
    else {
        pQueue pp = createQueue();
        int c;
        while (!isEmpty(pQ)) {
            c = take(pQ);
            printf("%d ", c);
            put(pp, c);
        }
        printf("\n");
        // Возвращаем элементы обратно
        while (!isEmpty(pp)) put(pQ, take(pp));
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
            printf("%d ", c);
            put(pQ, c);
        }
        printf("\n");
    }
}

void showQ(pQueue pQ) {
    if (isEmpty(pQ)) {
        puts("Queue is empty");
    } else {
        pNode current = pQ->beg;
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void clearQueue(pQueue pQ) {
    while (!isEmpty(pQ)) {
        take(pQ);
    }
    free(pQ);
}

void fillQueueRandom(pQueue pQ, int n) {
    int i;
    for (i = 0; i < n; i++) {
        put(pQ, rand() % 101 - 50);
    }
}
