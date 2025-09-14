#include <iostream>
#include "print_hello.hpp"

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
       cout << "Hello, World!" << std::endl; 
    }

    print_hello();
    
    return 0;
}
