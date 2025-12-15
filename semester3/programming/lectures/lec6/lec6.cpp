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

// int main() {
    // 1)
    // Point A = {0,-3}, B = {0,1};

    // pPoint pA{&A};
    // pPoint pB{&B};

    // cout << "(через точку)     AB = " << dist(A, B) << endl;
    // cout << "(через указатели) AB = " << dist1(pA, pB) << endl;

    // 2)
    // Point A = {0, 0}, B = {80, 40}, mid;
    // mid = make((A.x + B.x)/2, (A.y + B.y)/2);

    // cout << "Центральныя точка mid = " << endl;
    // show(mid);
    // cout << endl;

    // return 0;
// }

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
} tennis;

foo
*/

// Домашняя работа
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string name;
    int liga;
    int ball; // сумма очков
} tennis;

// Ввод участников
void inputPlayers(tennis arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Участник " << i + 1 << endl;

        cout << "Имя: ";
        cin >> arr[i].name;

        cout << "Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): ";
        cin >> arr[i].liga;

        cout << "Сумма очков: ";
        cin >> arr[i].ball;

        cout << endl;
    }
}

// Обмен элементов
void swap(tennis &a, tennis &b) {
    tennis temp = a;
    a = b;
    b = temp;
}

// 1 этап: пузырьковая сортировка по лиге
void bubbleSortByLiga(tennis arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].liga > arr[j + 1].liga) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2 этап: пузырьковая сортировка по очкам внутри каждой лиги
void bubbleSortByBallsInLiga(tennis arr[], int n) {
    int start = 0;

    while (start < n) {
        int end = start;

        // находим диапазон одной лиги
        while (end < n && arr[end].liga == arr[start].liga) {
            end++;
        }

        // пузырёк по очкам (по убыванию)
        for (int i = start; i < end - 1; i++) {
            for (int j = start; j < end - 1 - (i - start); j++) {
                if (arr[j].ball < arr[j + 1].ball) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        start = end;
    }
}

// Вывод мест отдельно для каждой лиги
void printResults(tennis arr[], int n) {
    int currentLiga = -1;
    int place = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].liga != currentLiga) {
            currentLiga = arr[i].liga;
            place = 1;
            cout << "\n=== Лига " << currentLiga << " ===\n";
        }

        cout << place << " место: "
             << arr[i].name
             << " (очки: " << arr[i].ball << ")\n";

        place++;
    }
}

int main() {
    int n;
    cout << "Введите количество участников: ";
    cin >> n;

    tennis players[100]; // максимум 100 участников

    inputPlayers(players, n);
    bubbleSortByLiga(players, n);
    bubbleSortByBallsInLiga(players, n);
    printResults(players, n);

    return 0;
}

/*
Введите количество участников: 6
Участник 1
Имя: 1
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 1
Сумма очков: 10

Участник 2
Имя: 2
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 1
Сумма очков: 45

Участник 3
Имя: 3
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 2
Сумма очков: 35

Участник 4
Имя: 4
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 2
Сумма очков: 34

Участник 5
Имя: 5
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 3
Сумма очков: 45

Участник 6
Имя: 6
Лига (1 - Школьная, 2 - Университетская, 3 - Профессиональная): 3
Сумма очков: 32


=== Лига 1 ===
1 место: 2 (очки: 45)
2 место: 1 (очки: 10)

=== Лига 2 ===
1 место: 3 (очки: 35)
2 место: 4 (очки: 34)

=== Лига 3 ===
1 место: 5 (очки: 45)
2 место: 6 (очки: 32)
*/