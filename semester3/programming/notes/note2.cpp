#include <iostream>
#include <iomanip>

int main() {
    int n, k;
    std::cin >> n >> k;

    int day = 1;

    // первая строка
    bool firstInRow = true;

    // пустые позиции до первого числа
    for (int pos = 1; pos < n; ++pos) {
        if (!firstInRow) {
            std::cout << ' ';
        }
        std::cout << "  ";  // под "пустую" ячейку тоже 2 символа
        firstInRow = false;
    }

    // оставшиеся позиции первой строки заполняем днями
    for (int pos = n; pos <= 7 && day <= k; ++pos) {
        if (!firstInRow) {
            std::cout << ' ';
        }
        std::cout << std::setw(2) << day;
        firstInRow = false;
        ++day;
    }

    std::cout << '\n';

    // остальные строки
    while (day <= k) {
        bool firstInRow = true;
        for (int pos = 1; pos <= 7 && day <= k; ++pos) {
            if (!firstInRow) {
                std::cout << ' ';
            }
            std::cout << std::setw(2) << day;
            firstInRow = false;
            ++day;
        }
        std::cout << '\n';
    }

    return 0;
}
