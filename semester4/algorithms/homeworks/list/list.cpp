#include <list.h>

pList createList(){
    pList New = (pList)malloc(sizeof(struct List));
    if (New){
        New->top = NULL;
        New->len = 0;
    }
    return New;
}

int isEmpty(pList pL){
    if (pL->top && pL->len) return 0;
    return 1;
}

void showList(pList pL) {
    if (isEmpty(pL)) printf("List is empty\n");
    pNode p = pL->top;
    while (p) {
        printf("%d ", p->value);
        p = p->next;
    }
}

pNode findNode(pList pL, int c) {
    pNode p = pL->top;
    if (isEmpty(pL)) return NULL;
    while (p && p->value != c) p = p->next;
    return p;
}

pNode getPointer(pList pL, int c) {
    //поиск узла, за которым будет добавлен новый узел
    //исключение top, узел м.б. довавлен до вершины
    pNode p = pL->top;
    if (isEmpty(pL) || c > p->value) return p;
    //поиск нужного элемента
    while (p->next && p->next->value > c)
        p = p->next;//переход к следующ. элементу
    return p;
}

// ещё не провереный код

int addNodeAfter(pList pL, pNode pN, int newdate) {
    pNode pnew, p = pL->top;
    pnew = (pNode)malloc(sizeof(struct Node));
    if (!pnew) return 0;
    pL->len++;
    pnew->value = newdate;
    if (isEmpty(pL) || pN==p && newdate > p->value) {
        pnew->next = p;
        pL->top = pnew;
        return 1;
    }
    pnew->next = pN->next;
    pN->next = pnew;
    return 1;
}

int putAfter(pList pL, int date, int date1) {
    // встав. узел со знач. date1 за узлов со знач date
    if (isEmpty(pL) || findNode(pL, date) == NULL) return 0;
    pNode p = pL->top, pnew;
    if (p->value == date) {
        pnew = (pNode)malloc(sizeof(struct Node));
        if (!pnew) return 0;
        pL->len++;
        pnew->value = date1;
        pnew->next = p->next;
        p->next = pnew;
        p = p->next;
        if (p) p = p->next;
    }
    while (p) {
        while (p && p->value != date) p = p->next;
        if (p && p->value == date) {
            addNodeAfter(pL, p, date1);
            p = p->next;
            if (p) p = p->next;
        }
    }
    return 1;
}

int delNode(pList pL, pNode pN) {   // удаляет элемент списка, стоящий за узлом pN
    pNode p = pN->next;
    if (pL->len==1) {// исключение, в списке 1 узел
        free(pL->top);
        pL->top = NULL;
        pL->len--;
        return 1;
    }
    if (p) {
        pN->next = p->next;
        free(p);
        pL->len--;
        return 1;
    }
    return 0;
}

void clearList(pList pL){
    while (pL->top) {
        delNode(pL, pL->top);
    }
}

void deleteList(pList pL){
    clearList(pL);
    free(pL);
}

void UnicList(pList pL) {
    pNode p = pL->top, pa;
    int a;
    pList List = createList();
    List->len = pL->len;
    while (p) {
        a = p->value;
        List->top = p->next;
        List->len--;
        while (findNode(List, a)) {
            pL->len--;
            if (a == List->top->value) {
                p->next = List->top->next;
                free(List->top);
                List->len--;
                List->top = p->next;
            }
            else delNode(List, getPointer(List, a));
        }
        if (p) p = p->next;
    }
}