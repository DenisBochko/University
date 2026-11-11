#include <array>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, std::size_t Capacity>
class Stack {
private:
    std::array<T, Capacity> values_;
    std::size_t size_ = 0;

public:
    void push(const T& value) {
        if (size_ == Capacity) {
            throw std::overflow_error("Стек заполнен");
        }
        values_[size_] = value;
        ++size_;
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("Стек пуст");
        }
        --size_;
        return values_[size_];
    }

    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Стек пуст");
        }
        return values_[size_ - 1];
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }
    static constexpr std::size_t capacity() { return Capacity; }
};

int main() {
    Stack<int, 3> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Стек int: размер = " << numbers.size()
              << ", верхний элемент = " << numbers.top() << '\n';
    std::cout << "Извлекаем: " << numbers.pop() << ", " << numbers.pop() << '\n';
    std::cout << "Теперь верхний элемент: " << numbers.top() << '\n';

    Stack<std::string, 2> words;
    words.push("первый");
    words.push("второй");
    std::cout << "\nСтек string: размер = " << words.size()
              << ", верхний элемент = " << words.top() << '\n';
    std::cout << "Извлекаем: " << words.pop() << '\n';

    try {
        words.push("третий");
        words.push("четвёртый");
    } catch (const std::overflow_error& error) {
        std::cout << "Ошибка переполнения: " << error.what() << '\n';
    }

    return 0;
}
