#include <iostream>
using namespace std;

typedef struct {
    int x, y;
} Point, *pPoint;

// dist Передача структуры "оператор-точка"
double dist(Point A, Point B) {
    double d;

    d = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));

    return d;
}

// dist1 Передача структуры через указатели "оператор-стрелка"
double dist1(pPoint pA, pPoint pB) {
    double d;

    d = sqrt(pow(pA -> x - pB -> x, 2) + pow(pA -> y - pB -> y, 2));
    
    return d;
}

// make Создаёт и возвращает переменную типа Point
Point make(int x, int y) {
    Point temp;
    temp.x = x;
    temp.y = y;

    return temp;
}

// show Выводит в консоль координаты точки из аргумента 
void show(Point A) {
    cout << "(" << A.x << ";" << A.y << ")" << endl;
}

int main() {
    // 1)
    // Point A = {0,-3}, B = {0,1};

    // pPoint pA{&A};
    // pPoint pB{&B};

    // cout << "(через точку)     AB = " << dist(A, B) << endl;
    // cout << "(через указатели) AB = " << dist1(pA, pB) << endl;

    // 2)
    Point A = {0, 0}, B = {80, 40}, mid;
    mid = make((A.x + B.x)/2, (A.y + B.y)/2);

    cout << "Центральныя точка mid = " << endl;
    show(mid);
    cout << endl;

    return 0;
}

/*

Структуры и функции 

Существует 3 подхода передачи структуры в аргументы функции:
1) Передача всей структуры;
2) Передача полей структуры;
3) Передача указателя на структуру;


Массивы структур
1) Сначала объявляют структуру, затем объявляют массив из этого типа

ДЗ:
В выбранной предметной области (Соревнования какие-нибудь спорт/пение и тд)
распределить участников соревнований по местам, применив любой вид сортировки;
всё должно быть в функциях, (создание через клавиатуру) 

начало дз
typtdef struct {
    string name;
    int liga;
    int ball; // Сумма очков
} football;

foo
*/
