#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

class complex {
private:
    double real_;
    double imaginary_;

public:
    complex(double real = 0.0, double imaginary = 0.0)
        : real_(real), imaginary_(imaginary) {}

    complex operator+(const complex& other) const {
        return {real_ + other.real_, imaginary_ + other.imaginary_};
    }

    complex operator-(const complex& other) const {
        return {real_ - other.real_, imaginary_ - other.imaginary_};
    }

    friend std::ostream& operator<<(std::ostream& output, const complex& value) {
        output << '(' << value.real_;
        if (value.imaginary_ >= 0) {
            output << '+';
        }
        output << value.imaginary_ << "i)";
        return output;
    }

    // Формат ввода: действительная и мнимая части через пробел.
    friend std::istream& operator>>(std::istream& input, complex& value) {
        input >> value.real_ >> value.imaginary_;
        return input;
    }
};

template <typename T>
class Matrix {
private:
    std::size_t rows_ = 0;
    std::size_t columns_ = 0;
    std::vector<std::vector<T>> values_;

    void ensureSameSize(const Matrix& other) const {
        if (rows_ != other.rows_ || columns_ != other.columns_) {
            throw std::invalid_argument("Размеры матриц должны совпадать");
        }
    }

public:
    Matrix() = default;
    Matrix(const Matrix&) = default;

    Matrix(std::size_t rows, std::size_t columns, const T& initial = T{})
        : rows_(rows), columns_(columns), values_(rows, std::vector<T>(columns, initial)) {}

    Matrix(std::initializer_list<std::initializer_list<T>> rows)
        : rows_(rows.size()), columns_(rows.size() == 0 ? 0 : rows.begin()->size()) {
        for (const auto& row : rows) {
            if (row.size() != columns_) {
                throw std::invalid_argument("Все строки матрицы должны иметь одну длину");
            }
            values_.emplace_back(row);
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows_ = other.rows_;
            columns_ = other.columns_;
            values_ = other.values_;
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        ensureSameSize(other);
        Matrix result(rows_, columns_);
        for (std::size_t row = 0; row < rows_; ++row) {
            for (std::size_t column = 0; column < columns_; ++column) {
                result.values_[row][column] = values_[row][column] + other.values_[row][column];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        ensureSameSize(other);
        Matrix result(rows_, columns_);
        for (std::size_t row = 0; row < rows_; ++row) {
            for (std::size_t column = 0; column < columns_; ++column) {
                result.values_[row][column] = values_[row][column] - other.values_[row][column];
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix) {
        for (std::size_t row = 0; row < matrix.rows_; ++row) {
            output << "[ ";
            for (std::size_t column = 0; column < matrix.columns_; ++column) {
                output << matrix.values_[row][column] << ' ';
            }
            output << "]\n";
        }
        return output;
    }

    // Размер задаётся конструктором, затем считываются его элементы по строкам.
    friend std::istream& operator>>(std::istream& input, Matrix& matrix) {
        for (std::size_t row = 0; row < matrix.rows_; ++row) {
            for (std::size_t column = 0; column < matrix.columns_; ++column) {
                input >> matrix.values_[row][column];
            }
        }
        return input;
    }
};

template <typename T>
void showCalculations(const Matrix<T>& first, const Matrix<T>& second, const char* typeName) {
    std::cout << "Матрицы типа " << typeName << ":\n";
    std::cout << "A:\n" << first;
    std::cout << "B:\n" << second;
    std::cout << "A + B:\n" << first + second;
    std::cout << "A - B:\n" << first - second;

    Matrix<T> assigned;
    assigned = first;
    std::cout << "Матрица после присваивания C = A:\n" << assigned << '\n';
}

int main() {
    Matrix<int> integersA{{1, 2}, {3, 4}};
    Matrix<int> integersB{{5, 6}, {7, 8}};
    showCalculations(integersA, integersB, "int");

    Matrix<float> floatsA{{1.5F, 2.5F}, {3.5F, 4.5F}};
    Matrix<float> floatsB{{0.5F, 1.0F}, {1.5F, 2.0F}};
    showCalculations(floatsA, floatsB, "float");

    Matrix<complex> complexesA{{{1, 2}, {3, -1}}, {{0, 4}, {2, 0}}};
    Matrix<complex> complexesB{{{2, -2}, {1, 1}}, {{5, 0}, {-2, 3}}};
    showCalculations(complexesA, complexesB, "complex");

    std::istringstream input("10 20 30 40");
    Matrix<int> entered(2, 2);
    input >> entered;
    std::cout << "Матрица, прочитанная из потока:\n" << entered;

    return 0;
}
