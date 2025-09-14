#include <iostream>
using namespace std;

//--------------- lab 3 ------------------
void lab3_task1(){
    const int N = 6;
    int array[N] = {}, a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a > 7) {
            a = 7;
        }
        array[i] = a;
    }
    for (int i = 0; i < N; i++) cout << array[i];
}

void lab3_task2() {
    const int N = 6;
    int array[N] = {1, 2}, a;
    
    for (int i = 0; i < N; i++) {
        cin >> a;
        array[i] = a;
    }
    
    for (int i = 0; i < N; i+=2){
        a = array[i];
        array[i] = array[i + 1];
        array[i+1] = a;
    }

    for (int i = 0; i < N; i++) cout << array[i];
}

void lab3_task3() {
    const int N = 6;
    int A[N], B[N], C[N];
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) A[i] = rand() % 101 - 50; // -50 50
    for (int i = 0; i < N; i++) B[i] = rand() % 101 - 50;
    for (int i = 0; i < N; i++) C[i] = A[i] * B[i];
    
    for (int i = 0; i < N; i++) cout << C[i] << " ";
    
}

void lab3_task4() {
    const int N = 6;
    int A[N], x;
    cout << "Введите кратность: \n";
    cin >> x;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) A[i] = rand() % 41 - 20; // -20 20
    for (int i = 0; i < N; i++) {
        if (A[i] % x == 0) {
            cout << A[i] << " ";
        }
    }
}

void lab3_task5() {
    const int N = 30;
    int C[N], F[N];
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) C[i] = rand() % 100;
    for (int i = 0; i < N; i++) F[i] = ((9 * C[i]) / 5) + 32;
    
    cout << "day\t\tC\t\tF\n";
    for (int i = 0; i < 30; i++) {
        cout << i + 1 << "\t\t" << C[i] << "\t\t" << F[i] << "\n";
    }
}

void lab3_task6() {
    const int N = 10;
    int A[N], sum, count;
    
    sum = 0;
    count = 0;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) A[i] = rand() % 100;
    
    for (int i = 0; i < N; i++) {
        if (A[i] % 5 == 0 && A[i] % 7 != 0) {
            sum += A[i];
            count++;
        }
    }
    
    cout << "Cумма: " << sum << " Количество: " << count;
}

void lab3_task7() {
    const int N = 10;
    int A[N] = {4, 12, 54, 9, 15, 3, 5, 66, 25, 8}, sum, count;
    
    sum = 0;
    count = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] % 3 == 0 && A[i] % 9 != 0) {
            sum += A[i];
            count++;
        }
    }
    
    if (count != 0) cout << "Среднее арифметическое: " << sum / count;
}

void lab3_task8() {
    const int N = 10;
    int B[N], sum, mult;
    
    sum = 0;
    mult = 1;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 11 - 5;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    for (int i = 0; i < N; i++) {
        if (B[i] > 0) sum += B[i];
        if (B[i] < 0) mult *= B[i];
    }
    cout << "\nsum: " << sum << "\n";
    cout << "multiply: " << mult << "\n";
}

void lab3_task9() {
    const int N = 10;
    int B[N], num, sum;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 100;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    for (int i = 0; i < N; i++) {
        num = B[i];
        sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        
        if (sum % 2 == 0 && sum > 0) {
            cout << "Сумма цифр кратна 2: " << B[i] << "\n";
        }
    }
}

void lab3_task10() {
    const int N = 10;
    int B[N], mx, mn;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 100;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    mx = B[0];
    mn = B[0];
    for (int i = 1; i < N; i++) {
        if (B[i] > mx) mx = B[i];
        if (B[i] < mn) mn = B[i];
    }
    
    cout << "Минимальное: " << mn << "\n";
    cout << "Максимальное: " << mx << "\n";
}

void lab3_task11() {
    const int N = 10;
    int B[N], a, b;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 101 - 50;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    a = B[0];
    b = B[0];
    for (int i = 1; i < N; i++) {
        if (B[i] > a) {
            b = a;
            a = B[i];
        }
        
        if (B[i] > b) {
            b = B[i];
        }
    }
    
    cout << "Предмаксимальное: " << b << "\n";
    cout << "Максимальное: " << a << "\n";
}

void lab3_task12() {
    const int N = 10;
    int B[N], res[N], mx;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 10;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    
    mx = B[0];
    
    for (int i = 0; i < N; i++) {
        if (B[i] > mx) mx = B[i];
    }
    
    cout << "Мax:" << mx << "\n";
    
    for (int i = 0; i < N; i++) res[i] = B[i] * mx;
    
    cout << "Результирующий:\n";
    for (int i = 0; i < N; i++) cout << res[i] << " ";
    cout << "\n";
}

void lab3_task13() {
    const int N = 10;
    int B[N], res[N], mn;
    
    //srand(time(NULL)); // работает
    cout << "Изначальный: ";
    for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    
    mn = B[0];
    
    for (int i = 0; i < N; i++) {
        if (B[i] < mn) mn = B[i];
    }
    
    cout << "Мin: " << mn << "\n";
    
    for (int i = 0; i < N; i++) res[i] = B[i] - mn;
    
    cout << "Результирующий: ";
    for (int i = 0; i < N; i++) cout << res[i] << " ";
    cout << "\n";
}

void lab3_task14() {
    const int N = 10;
    int B[N], count = 0;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 100;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N; i+=2) {
        if (B[i] % 2 != 0) count++;
    }
    
    cout << "Количество: " << count << "\n";
}

void lab3_task15_a() {
    const int N = 10;
    int B[N], count = 0;
    
    //srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 21 - 10;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N - 1; i++) {
        if (B[i] > 0 && B[i + 1] > 0) count++;
    }
    
    cout << "Количество: " << count << "\n";
}

void lab3_task15_b() {
    const int N = 10;
    int B[N], count = 0;
    
    // srand(time(NULL)); // работает
    for (int i = 0; i < N; i++) B[i] = rand() % 21 - 10;
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < N - 1; i++) {
        if ((B[i] > 0 && B[i + 1] < 0) || (B[i] < 0 && B[i + 1] > 0)) count++;
    }
    
    cout << "Количество: " << count << "\n";
}


int main()
{
    lab3_task1();
    return 0;
}
