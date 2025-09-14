//--------------- lab 4 ------------------


void lab4_task1(){
    const int N = 10;
    int a[N], b[N], k = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) a[i] = rand() % 21;
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) {
            b[k] = a[i];
            k++;
        }
    }
    
    cout << "B: ";
    for (int i = 0; i < k; i++) cout << b[i] << " ";
    cout << "\n";
}

void lab4_task2(){
    const int N = 10;
    int a[N], positive[N], negativ[N], p = 0, n = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) a[i] = rand() % 51 - 25;
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    // positive/negativ
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            positive[p] = i + 1;
            p++;
        } else if (a[i] < 0) {
            negativ[n] = i + 1;
            n++;
        }
    }
    
    // вывод
    cout << "Positive: ";
    for (int i = 0; i < p; i++) cout << positive[i] << " ";
    cout << "\n";
    cout << "Negativ: ";
    for (int i = 0; i < n; i++) cout << negativ[i] << " ";
    cout << "\n";
}

void lab4_task3(){
    const int N = 10;
    int a[N], b[N], k = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) a[i] = rand() % 51 - 25;
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    // Сложность алгоритма О(3 * N)
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            b[k] = a[i];
            k++;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (a[i] < 0) {
            b[k] = a[i];
            k++;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (a[i] == 0) {
            b[k] = a[i];
            k++;
        }
    }
    
    cout << "B: ";
    for (int i = 0; i < N; i++) cout << b[i] << " ";
    cout << "\n";
}

bool isPrime(int num) {
    int count = 1;
    
    for (int i = 1; i <= ((num/2) + 1); i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        return true;
    }
    return false;
}

void lab4_task4(){
    const int N = 10;
    int a[N], sum = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) a[i] = rand() % 10;
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N; i++) if (isPrime(a[i])) sum += a[i];
    
    cout << "Sum = "<< sum << "\n";
}

void lab4_task5() {
    const int N = 10;
    int a[N] = {-4, -3, -2, -1, -4, -2, -3, 5, 4, -1};
    
//    srand( static_cast<unsigned int>(time(nullptr)));  // Генерация случайных чисел
//    for (int i = 0; i < N; i++) a[i] = rand() % 11 - 5;

    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";

    int series_count = 0;
    bool in_series = false; // Флаг, находимся ли мы в серии
    for (int i = 1; i < N; i++) {
        if ((a[i] > 0 && a[i - 1] < 0) || (a[i] < 0 && a[i - 1] > 0)) {
            if (!in_series) { // Начало новой серии
                series_count++;
                in_series = true;
            }
        } else {
            in_series = false; // Серия прерывается
        }
    }

    cout << "Количество серий: " << series_count << "\n";
    
    }

void lab4_task6() {
    const int N = 5;
    float a[N], multipy_sum = 0, sum = 0, count = 0;
    
    srand(static_cast<unsigned int>(time(nullptr)));  // Генерация случайных чисел
    for (int i = 0; i < N; i++) a[i] = rand() % 11 - 5;
    
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            count += 1.0;
            sum += a[i];
        }
        
        if (i != N - 1) {
            multipy_sum += a[i] * a[i + 1];
            // cout << a[i] << " " << a[i + 1] << "\n"; // Для отладки
        }
    }
    
    cout << "Среднее арифметическое положительных элементов: " << sum/count << "\n";
    cout << "a1 • a2 + a2 • a3 ... :" << multipy_sum << "\n";
}

void lab4_task7_1() {
    const int N = 5;
    double x[N] = {1, 2, 0.5, -1.5, 3};
    double y[N] = {1, 2, 0, -0.5, 4};
    double R = 2.0;
    
    for (int i = 0; i < 5; i++) {
        if (sqrt(pow(x[i], 2) + pow(y[i], 2)) <= R) {
            // cout << x[i] << " " << y[i] << "\n";
            cout << "Номер точки: " << (i + 1) << "\n";
        }
    }
}

void lab4_task7_2() {
    const int N = 5;
    double x[N] = {1, 2, 0.5, -1.5, 3};
    double y[N] = {1, 2, 0, -0.5, 4};
    double center[2] = {1, 1};
    double R = 2.0;
    
    for (int i = 0; i < 5; i++) {
        if (sqrt(pow(x[i] - center[0], 2) + pow(y[i] - center[1], 2)) <= R) {
            // cout << x[i] << " " << y[i] << "\n";
            cout << "Номер точки: " << (i + 1) << "\n";
        }
    }
}

void lab4_task8() {
    const int N = 10;
    int a[N], positive[N], negativ[N], p = 0, n = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) a[i] = rand() % 51 - 25;
    cout << "A: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
    
    // positive/negativ
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            positive[p] = a[i];
            p++;
        } else if (a[i] < 0) {
            negativ[n] = a[i];
            n++;
        }
    }
    
    // вывод
    cout << "Positive: ";
    for (int i = 0; i < p; i++) cout << positive[i] << " ";
    cout << "\n";
    cout << "Negativ: ";
    for (int i = 0; i < n; i++) cout << negativ[i] << " ";
    cout << "\n";
}

void lab4_task9() {
    const int N = 15;
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    long long multy;
    
    multy = 1;
    
    for (int i = 0; i < N; i++) {
        multy *= (a[i] + b[N - 1 - i]);
    }
    
    cout << multy;
}

void main() {
    lab4_task9();
}
