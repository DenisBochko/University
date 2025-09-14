#include <iostream>
#include <cstdio>

// Заметка для лабы 1 и 2.
int numberOfWords();

// Определить количество введённых строк
int main() {
    int count = numberOfWords();

    printf("\n%d\n", count);
}

int numberOfWords() {
    int c, count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
           count++; 
        }
    }

    return count;
}
