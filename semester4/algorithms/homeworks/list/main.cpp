#include <list.h>

using namespace std;

int main(){
    pNode p;
    pList List = createList();
    int com=1, a, b;
    while (com) {
        puts("1-add");
        puts("2-find");
        puts("3-del");
        puts("4-show");
        puts("5-clear");
        puts("6-Add after");
        puts("7-Unic List");
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
            break;
        }
        case 7: {
            UnicList(List);
            showList(List);
            cout << "Len_pL=" << List->len<<endl;
            break;
        }
        }
    }
    deleteList(List);
    return 0;
}