#include "list.h"

using namespace std;

/*
clang++ ./semester4/algorithms/homeworks/list/list.cpp \
./semester4/algorithms/homeworks/list/main.cpp \
-o ./semester4/algorithms/homeworks/list/list_hm && \
./semester4/algorithms/homeworks/list/list_hm
*/

int main(){
    pNode p;
    pList List = createList();
    int com=1, a, b;

    int testData[] = {5, -3, 12, -7, 1, -9, 8, 0, -2, 4};
    int testSize = sizeof(testData) / sizeof(testData[0]);

    for (int i = 0; i < testSize; i++) {
        addNodeAfter(List, getPointer(List, testData[i]), testData[i]);
    }

    printf("Initial list: ");
    showList(List);
    printf("\n\n");
    while (com) {
        puts("1-add");
        puts("2-find");
        puts("3-del");
        puts("4-show");
        puts("5-clear");
        puts("6-Add after");
        puts("7-Unic List");
        puts("8-positive-negative");
        puts("9-reverse list");
        puts("0-exit");
        cin>>com;
        switch (com){
        case 1: {
            cout<<"Enter number: ";
            cin>>a;
            if (!addNodeAfter(List, getPointer(List, a), a))
                cout<<"Node don't add.";
            break;
        }
        case 2: {
            cout << "Enter number: ";
            cin >> a;
            p = findNode(List, a);
            if (p)
                cout<<"Number =="<<a<<" adres: " << p<<endl;
            else
                cout << "Number ==" << a << " Not found!! "<<endl;
            break;
        }
        case 3: {
            cout<<"Enter number: ";
            cin>>a;
            p = findNode(List, a);
            if (!p) cout << "Value " << a << " Not Found!\n";
            else {
                if (a == List->top->value) {
                    List->top = p->next;
                    List->len--;
                    free(p);
                }
                else delNode(List, getPointer(List, a));
                cout << "Value " << a << " Delete !\n";
            }
            break;
        }
        case 4: {
            showList(List);
            printf("\n");
            break;
        }
        case 5: {
            clearList(List);
            showList(List);
            break;
        }
        case 6: {
            cout << "Enter number E: ";
            cin >> a;
            cout << "Enter number E1 (E->E1): ";
            cin >> b;
            putAfter(List, a, b);
            showList(List);
            printf("\n");
            break;
        }
        case 7: {
            UnicList(List);
            showList(List);
            cout << "Len_pL=" << List->len<<endl;
            break;
        }
        case 8: {
            pList E1 = createList();
            pList E2 = createList();
            printf("\nSource list:     ");
            showList(List);
            splitList(List, E1, E2);
            printf("\nPositive (E1):   ");
            showList(E1);
            printf("\nOther    (E2):   ");
            showList(E2);
            printf("\n");
            deleteList(E1);
            deleteList(E2);
            break;
        }
        case 9: {
            printf("Before reverse: ");
            showList(List);
            reverseList(List);
            printf("\nAfter reverse:  ");
            showList(List);
            printf("\n");
            break;
        }
        }
    }
    deleteList(List);
    return 0;
}