#include <iostream>

using namespace std;

class Test {
private:
    friend void fun(Test* object); // функция или класс, которому разрешён доступ к private и protected данным другого класса.

protected:
    int W;

    void Z() {
        cout << "Это закрытая функция класса Test\n";
    }

public:
    Test(int value = 1) {
        W = value;
    }
};

void fun(Test* object) {
    cout << "W = " << object->W << '\n';
    object->Z();
}

/*
clang++ /Users/dabochko/Documents/University/semester5/oop/lab2/task1/main.cpp \
-o /Users/dabochko/Documents/University/semester5/oop/lab2/task1/main && \
/Users/dabochko/Documents/University/semester5/oop/lab2/task1/main
*/

int main() {
    Test test;
    fun(&test);
}
