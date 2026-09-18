#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    int days[13] = {0, 31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31};

    bool isLeapYear() const {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }

    int daysInMonth() const {
        return month == 2 && isLeapYear() ? 29 : days[month];
    }

    // Приводит дату к правильному виду после сложения или вычитания.
    void normalize() {
        while (month > 12) {
            month -= 12;
            ++year;
        }
        while (month < 1) {
            month += 12;
            --year;
        }
        while (day > daysInMonth()) {
            day -= daysInMonth();
            ++month;
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
        while (day < 1) {
            --month;
            if (month < 1) {
                month = 12;
                --year;
            }
            day += daysInMonth();
        }
    }

public:
    // Два конструктора: дата по умолчанию и дата с заданными значениями.
    Date() : day(1), month(1), year(2000) {}

    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    // «Дата + дата»: вторая дата используется как период (дни, месяцы, годы).
    Date operator+(const Date& period) const {
        Date result(*this);
        result.day += period.day;
        result.month += period.month;
        result.year += period.year;
        result.normalize();
        return result;
    }

    // «Дата - дата»: из даты окончания вычитается период.
    Date operator-(const Date& period) const {
        Date result(*this);
        result.day -= period.day;
        result.month -= period.month;
        result.year -= period.year;
        result.normalize();
        return result;
    }

    // «Дата + число дней».
    Date operator+(int numberOfDays) const {
        Date result(*this);
        result.day += numberOfDays;
        result.normalize();
        return result;
    }

    // «Дата - число дней».
    Date operator-(int numberOfDays) const {
        return *this + (-numberOfDays);
    }

    // Переход к следующей и предыдущей дате.
    Date& operator++() {
        ++day;
        normalize();
        return *this;
    }

    Date& operator--() {
        --day;
        normalize();
        return *this;
    }

    // Вывод даты в поток cout.
    friend ostream& operator<<(ostream& out, const Date& date) {
        if (date.day < 10) out << '0';
        out << date.day << '.';
        if (date.month < 10) out << '0';
        return out << date.month << '.' << date.year;
    }

    // Нужна отдельная функция: компилятор сам не переставляет int + Date в Date + int.
    friend Date operator+(int numberOfDays, const Date& date) {
        return date + numberOfDays;
    }
};

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab4/task2/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab4/task2/main && \
/Users/dabochko/Documents/University/semester5/oop/lab4/task2/main
*/

int main() {
    Date start(1, 4, 2010);
    Date period(10, 3, 2); // 10 дней, 3 месяца, 2 года.
    Date deadline = start + period;

    cout << "Дата начала: " << start << '\n';
    cout << "Срок строительства: 2 года 3 месяца 10 дней\n";
    cout << "Дата сдачи: " << deadline << "\n\n";

    cout << "Дата начала, найденная вычитанием: " << deadline - period << '\n';
    cout << "Поставка через 20 дней: " << start + 20 << '\n';
    cout << "Поставка через 20 дней (int + Date): " << 20 + start << '\n';
    cout << "Дата зарплаты за 15 дней до начала: " << start - 15 << '\n';

    ++start;
    cout << "Следующая дата: " << start << '\n';
    --start;
    cout << "Предыдущая дата: " << start << '\n';
}
