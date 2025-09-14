//--------------- lab 7_1 ------------------

#define ARRAY_LENGTH 10

void get_arr(int* arr, const int len) {
    cout << "Введите эначения элементов массива:\n";
    
    for (int i = 0; i < len; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    
    /*
     int mas[ARRAY_LENGTH];
     get_arr(mas, ARRAY_LENGTH);
    */
}

void print_arr(int* arr, const int len) {
    for (int i = 0; i < len; i++) {
        cout << "arr[" << i << "] =\t" << arr[i] << "\n";
    }
    
    /*
     int main()
     {
         int mas[ARRAY_LENGTH];
         get_arr(mas, ARRAY_LENGTH);
         print_arr(mas, ARRAY_LENGTH);
         return 0;
     }
    */
}

//--------------- lab 7_2 ------------------

void lab7_is_sorted(int* arr, const int len) {
    for (int i = 1; i < len; i++) {
        if (arr[i] <= arr[i - 1]) {
            cout << "Элементы не упорядочены по возрастанию!\n";
            return;
        }
    }
    cout << "Элементы упорядочены по возрастанию\n";
}

void lab7_first_index(int* arr, const int len, int x) {
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }
    cout << "Индекс элемента, равного '" << x << "': " << index << "\n";
}

int lab7_find_first_negative_index(double* arr, const int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return 0;
}

void lab7_compute_expression(double* arr, const int len) {
    int m = lab7_find_first_negative_index(arr, len);
    double result = arr[0];
    double mediate = arr[0];

    for (int i = 1; i <= m; i++) {
        mediate *= arr[i];
        result += mediate;
    }

    cout << "x0 + x0*x1 + x0*x1*x2 + ... + x0*x1*...*xm = " << result << "\n";
}

void lab7_max_symmetric_sum(double* arr, const int len) {
    double max = arr[0] + arr[len - 1];
    double sum = 0;
    
    for (int i = 1; i <= len / 2; i++) {
        sum = arr[i] + arr[len - 1 - i];
        if (sum > max) {
            max = sum;
        }
    }
    
    cout << "Итоговый максимум симметричных сумм равен: " << max << "\n";
}

void lab7_min_of_multiply(double* arr, const int len) {
    double min = arr[0] * arr[1];
    double multi;
    
    for (int i = 1; i < len - 1; i++) {
        multi = arr[i] * arr[i + 1];
        if (multi < min) {
            min = multi;
        }
    }
    
    cout << "Итоговый минимум последовательных произведений равен: " << min << "\n";
}

int count_of_positive(double* arr, const int len) {
    int count = 0;
    
    for (int i = 0; i < len; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    
    return count;
}

int count_of_negative(double* arr, const int len) {
    int count = 0;
    
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    
    return count;
}

void lab7_compute_UZ_sum(double* arr, const int len) {
    int count_n = count_of_negative(arr, len);
    int count_p = count_of_positive(arr, len);
    
    double u[count_n];  // Отрицательные элементы (u)
    double z[count_p];  // Положительные элементы (z)
    int p = 0, n = 0, k = count_n;
    
    // Разделяем массив на отрицательные и положительные элементы
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            u[n++] = arr[i];  // Отрицательные — в порядке следования
        } else if (arr[i] > 0) {
            z[count_p - 1 - p] = arr[i];  // Положительные — в обратном порядке следования
            p++;
        }
    }
    
    // вычисляем k (чтобы не выйти за range массива)
    if (count_n < count_p) {
        k = count_n;
    } else {
        k = count_p;
    }
    
    double result = 0.0;
    for (int i = 0; i < k; i++) {
        result += u[i] * z[i];
    }
    
    cout << "Итоговый результат равен: " << result << "\n";
}

int main()
{
//    int x[10];
//    get_arr(x, 10);
//    lab7_is_sorted(x, 10);
//    lab7_first_index(x, 10, 5);
    
    double dx[10] = {1.2, 2.0, 1.5, -0.5, 3.0, 1.1, 0.9, 2.2, 1.0, 0.8};
    double dy[5] = {1.2, 2.0, -2.0, -0.5, 3.0};
    lab7_compute_expression(dx, 10); // 1.2 + 2.4 + 3.6 - 1.8 = 5.4
    lab7_max_symmetric_sum(dx, 10);
    lab7_min_of_multiply(dx, 10);
    lab7_compute_UZ_sum(dy, 5); // (-2.0 * 3) + (-0.5 * 2.0) = -7
    return 0;
}
