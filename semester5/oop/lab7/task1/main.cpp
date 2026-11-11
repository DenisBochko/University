#include <cstring>
#include <iostream>
#include <string>

// Ошибки в формулировках задания:
// 1) template <class T, class T> — имя T объявлено дважды.
// 2) template <class T1, T2> — перед T2 пропущено class или typename.
// 3) template <class T> T f(int x) синтаксически допустимо, но T нельзя
//    вывести из аргумента int: функцию можно вызвать только как f<тип>(x).
// 4) inline template <class T> — неверный порядок; правильно:
//    template <class T> inline T f(T x, T y).

namespace lab7 {

template <typename T>
void swap(T& first, T& second) {
    T temporary = first;
    first = second;
    second = temporary;
}

} // namespace lab7

template <typename T>
T max(T first, T second) {
    const T result = first > second ? first : second;
    std::cout << "Вызвана шаблонная функция max. Большее значение: "
              << result << '\n';
    return result;
}

template <>
const char* max<const char*>(const char* first, const char* second) {
    const char* result = std::strcmp(first, second) > 0 ? first : second;
    std::cout << "Вызвана специализированная функция max для строк. "
                 "Большая строка: "
              << result << '\n';
    return result;
}

int main() {
    std::cout << "Проверка шаблонной функции swap:\n";

    int integerFirst = 10;
    int integerSecond = 20;
    lab7::swap(integerFirst, integerSecond);
    std::cout << "int: " << integerFirst << ", " << integerSecond << '\n';

    char charFirst = 'A';
    char charSecond = 'Z';
    lab7::swap(charFirst, charSecond);
    std::cout << "char: " << charFirst << ", " << charSecond << '\n';

    std::string stringFirst = "первый";
    std::string stringSecond = "второй";
    lab7::swap(stringFirst, stringSecond);
    std::cout << "string: " << stringFirst << ", " << stringSecond << "\n\n";

    std::cout << "Проверка функции max:\n";
    max('a', '1');
    max(0, 1);
    max("Hello", "World");

    return 0;
}
