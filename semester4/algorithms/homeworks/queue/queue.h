#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct Queue {
    pNode beg, end;
    int len;
} *pQueue;

pQueue createQueue();
int isEmpty(pQueue pQ);
void put(pQueue pQ, int value);
int take(pQueue pQ);
void showQ_D1(pQueue pQ);
void showQ_D2(pQueue pQ);
void showQ(pQueue pQ);
void clearQueue(pQueue pQ);
void fillQueueRandom(pQueue pQ, int n);

void task1();
void task2();
void task3();
void task4();
void task5();
