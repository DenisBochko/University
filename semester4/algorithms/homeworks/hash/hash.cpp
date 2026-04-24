// Hash_open_29-april.cpp : Хеш-таблица с цепочками для целых чисел.
// Задача: дан массив a[i] из maxnum элементов типа T (int).
// Требуется построить хеш-таблицу для элементов массива.
// Обеспечить быстрый доступ к значениям элементов.

/*
clang++ ./semester4/algorithms/homeworks/hash/hash.cpp \
-o ./semester4/algorithms/homeworks/hash/hash_hm && \
./semester4/algorithms/homeworks/hash/hash_hm
*/

#include <iostream>
#include <fstream>
#include <cstdlib>    // для rand, srand, NULL
#include <ctime>      // для time

using namespace std;

// Структура для случая "символ + частота" (закомментирована, можно раскомментировать и изменить typedef)
/*
struct Data {
    char c;
    int k;
};
*/

// Тип элементов хеш-таблицы – целые числа
typedef int T;

// Тип индекса хеш-таблицы
typedef int hashTableIndex;

// Макрос сравнения двух значений типа T
#define compEQ(a,b) ((a) == (b))

// Узел списка (цепочки)
typedef struct Node {
    T data;              // данные
    struct Node* next;   // следующий узел
} *pNode;

// Глобальные переменные
pNode* hashTable;        // массив указателей на начала цепочек
int hashTableSize;       // размер хеш-таблицы

// Прототипы функций
hashTableIndex myhash(T data);
pNode insertNode(T newdata);
void deleteNode(T dat);
pNode findNode(T data);
int kolchar(char* s);   // вспомогательная функция для строк (не используется в текущей версии)

int main() {
    int i, maxnum;
    T* a;
    char s[255], * ps;

    cout << "Enter number -> maxnum : ";
    cin >> maxnum;
    cout << "Input size Hash-Table HashTableSize : ";
    cin >> hashTableSize;

    // Выделение памяти под массив элементов
    a = (T*)malloc(maxnum * sizeof(T));
    if (!a) {
        cout << "Memory allocation error for array a\n";
        return 1;
    }

    // Заполнение массива случайными числами от 1 до 1000
    srand(time(NULL));
    for (i = 0; i < maxnum; i++) {
        a[i] = 1 + rand() % 1000;
    }

    // Выделение памяти под хеш-таблицу (массив указателей)
    hashTable = (pNode*)malloc(sizeof(pNode) * hashTableSize);
    if (!hashTable) {
        cout << "Memory allocation error for hashTable\n";
        free(a);
        return 1;
    }

    // Инициализация всех цепочек пустыми списками
    for (i = 0; i < hashTableSize; i++)
        hashTable[i] = NULL;

    // Вывод исходного массива в файл
    ofstream out("d:\\List_array_a.txt");
    if (!out) {
        cout << "Cannot create output file d:\\List_array_a.txt\n";
    } else {
        for (i = 0; i < maxnum; i++) {
            out << a[i] << " ";
        }
        out.close();
    }

    // Заполнение хеш-таблицы элементами массива
    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }

    // Вывод содержимого хеш-таблицы на экран
    cout << "\n--- Hash table contents ---\n";
    for (i = 0; i < hashTableSize; i++) {
        pNode p = hashTable[i];
        cout << i << " : ";
        if (!p) cout << "NULL";
        while (p) {
            cout << " (" << p->data << ") ->";
            p = p->next;
        }
        cout << endl;
    }

    // Поиск всех элементов массива в хеш-таблице (в обратном порядке)
    cout << "\n--- Searching elements ---\n";
    for (i = maxnum - 1; i >= 0; i--) {
        pNode p = findNode(a[i]);
        if (p) {
            cout << a[i] << " - " << p->data << endl;
        } else {
            cout << a[i] << " - NOT FIND" << endl;
        }
    }

    // Сохранение итоговой хеш-таблицы в файл
    out.open("d:\\HashTable_ITOG.txt");
    if (!out) {
        cout << "Cannot create output file d:\\HashTable_ITOG.txt\n";
    } else {
        for (i = 0; i < hashTableSize; i++) {
            out << i << " ";
            pNode Temp = hashTable[i];
            while (Temp) {
                out << "(" << Temp->data << ")->";
                Temp = Temp->next;
            }
            out << endl;
        }
        out.close();
    }

    // Очистка хеш-таблицы (удаление всех узлов)
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }

    // Освобождение памяти массива и таблицы указателей
    free(a);
    free(hashTable);

    return 0;
}

// Хеш-функция: остаток от деления на размер таблицы
hashTableIndex myhash(T data) {
    return data % hashTableSize;
}

// Вставка узла в начало цепочки с индексом myhash(newdata)
pNode insertNode(T newdata) {
    pNode p, p0;
    hashTableIndex i;
    i = myhash(newdata);
    p = (pNode)malloc(sizeof(struct Node));
    if (!p) {
        cout << "Нехватка памяти in insertNode()\n";
        return NULL;
    }
    p0 = hashTable[i];
    hashTable[i] = p;
    p->next = p0;
    p->data = newdata;
    return p;
}

// Удаление узла с заданным значением (если найден)
void deleteNode(T dat) {
    pNode p0 = NULL, p;
    hashTableIndex i;
    i = myhash(dat);
    p = hashTable[i];

    // Поиск узла в цепочке
    while (p && !compEQ(p->data, dat)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return; // не найден

    // Исключение узла из списка
    if (p0) {
        p0->next = p->next;
    } else {
        hashTable[i] = p->next;
    }
    free(p);
}

// Поиск узла с заданным значением. Возвращает указатель на узел или NULL.
// Также печатает количество сравнений, потребовавшихся для поиска.
pNode findNode(T data) {
    pNode p;
    int k = 0; // счётчик сравнений
    p = hashTable[myhash(data)];

    while (p && !compEQ(p->data, data)) {
        k++;
        p = p->next;
    }
    if (p && compEQ(p->data, data)) {
        k++; // учёт последнего успешного сравнения
    }
    cout << "!!! == " << data << " cmp=" << k << endl;
    return p;
}

// Вспомогательная функция: возвращает количество вхождений символа s[0] в строку s,
// удаляя все остальные повторения этого символа (кроме первого).
// В текущей программе не используется, оставлена для возможного расширения.
int kolchar(char* s) {
    int k, i, j;
    for (k = i = j = 1; s[i]; i++) {
        if (s[i] != s[0])
            s[j++] = s[i];
        else
            k++;
    }
    s[j] = '\0';
    return k;
}
