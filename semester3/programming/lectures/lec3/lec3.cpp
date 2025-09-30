#include <iostream>
using namespace std;

/* Алгоритмы сортировки */

void bubble_sort(int* arr, int n);
void selection_sort(int* arr, int n);
void reverse_bubble_sort(int* arr, int n);

int main() {
    int arr[10] = {4, -12, 0, 5, 13, -33, 6, 10, 0, 17};

    reverse_bubble_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

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