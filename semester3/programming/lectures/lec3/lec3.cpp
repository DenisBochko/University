#include <iostream>
using namespace std;

/* Алгоритмы сортировки */

void BubbleSort(int* arr, int n);
void bubble(int* arr, int k);
void BubbleSort_New(int* x, int k);
// void SelectionSort(int* arr, int n);
void reverse_bubble_sort(int* arr, int n);

void InsertSort(int k, int* x);
void SelectionSort(int k, int* x);
void Shaker(int k, int* x);

void Shella(int size, int* a);

void Enter_array(int k, int* x);
void Copy(int k, int* x, int* y);
void Print(int k, int* x);

int main() {
    int i, Size = 500, a[1000], b[1000];
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        cout << " " << i + 1 << endl;
        Enter_array(Size, a);
        Copy(Size, b, a);
        Print(Size, a);
        Shaker(Size, a);

        // Copy(Size, a, b);
        // Print(Size, a);
        // BubbleSort_New(a, Size);
        
        // Copy(Size, a, b);
        // Print(Size, a);
        // BubbleSort_New(a, Size);

        // Copy(Size, a, b);
        // Print(Size, a);
        // BubbleSort_New(a, Size);

        // Copy(Size, a, b);
        // Print(Size, a);
        // BubbleSort_New(a, Size);
    }

    return 0;
}

// классический алгоритм пузырька
void BubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}

// сортировка пузырьком в от большего к меньшему 
void reverse_bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int b = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = b;
            }
        }
    }
}

// void SelectionSort(int* arr, int n) {
//     for (int i = 0; i < n; i++) {
//         int mn_idx = i;

//         for (int j = i; j < n; j++) {
//             if (arr[j] < arr[mn_idx]) mn_idx = j;
//         } 

//         int b = arr[i];
//         arr[i] = arr[mn_idx];
//         arr[mn_idx] = b;
//     }
// }


// На Лабораторной делали.
void bubble(int* x, int k) {
    int i, j, c = 0, p = 0, buf;
    for (i = 0; i < k - 1; i++) // Сколько проходов нужно сделать
        for (j = k - 1; j > i; j--) { // Цикл просмотра
            c++;
            if (x[j] < x[j - 1]) {
                p++;
                buf = x[j];
                x[j] = x[j - 1];
                x[j - 1] = buf;
            }
        }
    printf("c = %d; p = %d; \n", c, p);
}

/*
2 6 7 0 9 1 5 3
            3 5
        1 9
    0 7
  0 6
0 2

0 2 6 7 1 9 3 5       
          3 9
      1 7
    1 6
  1 2

0 1 2 6 7 3 9 5
            5 9
        3 7
      3 6

0 1 2 3 6 7 5 9
          5 7
        5 6

0 1 2 3 5 6 7 9

0 1 2 3 5 6 7 9

0 1 2 3 5 6 7 9

0 1 2 3 5 6 7 9
*/

void BubbleSort_New(int* x, int k) {
    int i = 0, j, m = 0, c = 0, p = 0, buf;
    do {
        m = i;
        for (j = k - 1; j > m; j--) {
            c++;
            if (x[j - 1] > x[j]) {
                i = j; // i - индекс элемента, который последний учаввствовал в перестановке
                p++;
                buf = x[j];
                x[j] = x[j - 1];
                x[j - 1] = buf;
            }
        }
    } while (i - m);
    printf("c = %d; p = %d; \n", c, p);
}
/*
2 6 7 0 9 1 5 3
            3 5
        1 9
    0 7
  0 6
0 2

m = 0
0 2 6 7 1 9 3 5
          3 9
      1 7
    1 6
  1 2

m = 1
0 1 2 6 7 3 9 5
            5 9
          3 5
        3 7
      3 6
    2 3

m = 2
0 1 2 3 6 7 5 9
          5 7
        5 6
      3 5

m = 3
0 1 2 3 5 6 7 9
*/

void Enter_array(int k, int* x) {
    int i;
    for (i = 0; i < k; i++) x[i] = rand() % 100;
}

void Copy(int k, int* x, int* y) {
    int i;
    for (i = 0; i < k; i++) x[i] = y[i];
}

void Print(int k, int* x) {
    for (int i = 0; i < k; i++) {
        cout << x[i] << " ";
    }
}

// Evoid Shaker (int k, int* x) {
// int i, t, n1 = 0, n2 = k - 1, ], c = 0, P = 0;
// do 1 for (i = n2; i › n1; i~~) {
// c+*;
// if (x[i - 1] › x[i]) {
// p**; j = 1;
// t = x[i - 1]: x[i - 1] = x[1]; x[i] = t;
// } n1 = 2:
// for (i = n1 + 1; i <= n2; i++) {
// C++;
// if (x[1 - 1] › x[1]) t
// t = x[1 - 1]:
// x[i - 1] = x[i];
// ×[1] = t;
// j = i; ptt;
// n2
// g
// ]
// - 1;

// void InsertSort(int k, int* x) {
//     int i, j, temp, c = 0, p = 0;
//     for (i = 1; i < k; i++) {
//         c++;
//         if (x[i-1] > x[i]) {
//             temp = x[1]; p++; //поиск места элемента
//             for (j = 1 - 1; j >= 0 && x[j] > temp; j--, c+=2) {
//                 p++;
//                 x[j + 1] = x[j];
//             } //сдвигаем эл. вправо, пока не дошли до места вст-ки элем-та
//             x[j + 1] = temp; p++;
//         }
//     }
//     Print(k, x);
//     printf("InsertSort: compar=%d, reshuffle=%d\n\n", c, p / 3);
// }

void Shella(int size, int* a) {
    int i, j, temp, step = size / 2, c = 0, p = 0;
    while (step) {
        for (i = 0; i + step < size; i++) {
            c++;
            if (a[i] > a[i + step]) {
                j = i; // будем идти начиная с i-ого элемента
                temp = a[i + step]; p++;
                while (j >= 0 && a[j] > temp) {
                    // пока не пришли к началу массива и пока рассматриваем
                    // элемен больше элемента, находящегося на расстоянии шаг
                    c++; p++;
                    a[j + step] = a[j];
                    j -= step;
                }
                a[j + step] = temp; p++;
            }
        }   step /= 2; // уменьшаем шаг
    } // while step
    Print(size, a);
    printf("SortShella: compar=%d, reshuffle=%d\n\n", c, p / 3);
}

// кинула Света

void InsertSort(int k, int* x) {
    int i, j, temp, c = 0, p = 0;
    for (i = 1; i < k; i++, c++) {
        if (x[i - 1] > x[i]) {
            temp = x[i];
            p++; // поиск места элемента
            for (j = i - 1; j >= 0 && x[j] > temp; j--, c += 2) {
                p++;
                x[j + 1] = x[j]; // сдвигаем элемент вправо, пока не дошли до места вставки
            }
            x[j + 1] = temp;
            p++;
        }
    }
    Print(k, x);
    printf("InsertSort: compar=%d, reshuffle=%d\n", c, p / 3);
}

void SelectionSort(int k, int* x) {
    int i, j, im, temp, c = 0, p = 0, p1 = 0;
    for (i = 0; i < k - 1; i++) {
        im = i; // начальное значение индекса минимального элемента
        for (j = i + 1; j < k; j++) {
            c++;
            if (x[j] < x[im]) {
                im = j;
                p1++;
            }
        }
        temp = x[i];
        x[i] = x[im];
        x[im] = temp;
    }
    Print(k, x);
    printf("SelectionSort: compar=%d, reshuffle=%d\n\n", c, k-1+p1 / 3);
}

void Shaker(int k, int* x) {
    int i, t, n1 = 0, n2 = k - 1, j, c = 0, p = 0;
    do {
        for (i = n2; i > n1; i--) {
            c++;
            if (x[i - 1] > x[i]) {
                p++; 
                
                j = i;
                t = x[i - 1]; 
                x[i - 1] = x[i]; 
                x[i] = t;
            }
        } n1 = j;
        for (i = n1 + 1; i <= n2; i++) {
            c++;
            if (x[i - 1] > x[i]) {
                p++; 

                j = i; 
                t = x[i - 1];
                x[i - 1] = x[i];
                x[i] = t;
            }
        }
        n2 = j - 1;
    } while (n1 < n2);
    Print(k, x);
    printf("Shaiker: compar=%d, reshuffle=%d\n\n", c, p);
}