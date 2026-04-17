#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

// Осталось выучить: delNode, addNode, putAfter, unicList

typedef struct Node{
    int value;
    struct Node* next;
}* pNode;

typedef struct List{
    pNode top;
    int len;
}* pList;

pList createList();
int isEmpty(pList pL);
pNode getPointer(pList pL, int date);
int addNodeAfter(pList pL, pNode pN, int newdate);
void showList(pList pL);
pNode findNode(pList pL, int c);
int putAfter(pList pL, int date, int date1);
int delNode(pList pL, pNode pN);
void clearList(pList pL);
void deleteList(pList pL);
void UnicList(pList pL);
void splitList(pList L, pList E1, pList E2);
void reverseList(pList pL);
