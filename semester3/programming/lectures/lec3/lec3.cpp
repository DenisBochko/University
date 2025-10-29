#include <iostream>
using namespace std;

/* Алгоритмы сортировки */

void bubble_sort(int* arr, int n);
void bubble(int* arr, int k);
void bubble_new(int* x, int k);

void selection_sort(int* arr, int n);
void reverse_bubble_sort(int* arr, int n);

void Enter_array(int k, int* x);
void Copy(int k, int* x, int* y);
void Print(int k, int* x);

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    Enter_array(SIZE, arr);

    bubble_new(arr, SIZE);

    Print(SIZE, arr);

    return 0;
}

// классический алгоритм пузырька
void bubble_sort(int* arr, int n) {
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

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int mn_idx = i;

        for (int j = i; j < n; j++) {
            if (arr[j] < arr[mn_idx]) mn_idx = j;
        } 

        int b = arr[i];
        arr[i] = arr[mn_idx];
        arr[mn_idx] = b;
    }
}


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

void bubble_new(int* x, int k) {
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