
//--------------- lab 5 ------------------


void lab5_task1() {
    const int m = 5;
    const int n = 6;
    int matrix[m][n], mx;
    
    srand(static_cast<unsigned int>(time(NULL)));  // Генерация случайных чисел
    
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    matrix[i][j] = rand() % 100;
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // Находим максимальный элемент
    mx = matrix[0][0];
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        if (matrix[i][j] > mx) mx = matrix[i][j];
    
    // Преобразовываем
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        matrix[i][j] /= mx;
    
    // Вывыдим результат
    cout << "Результирующая матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
}

void lab5_task2() {
    const int m = 5;
    const int n = 6;
    long long matrix[m][n], result[m][1], sum;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) sum += matrix[i][j];
        }
        result[i][0] = sum;
    }
    
    // Выводим результирующую матрицу
    cout << "Результирующая матрица: \n";
    for (int i = 0; i < m; i++) {
        cout << result[i][0] << "\n";
    }
    cout << "\n";
}

void lab5_task3() {
    const int m = 8;
    const int n = 6;
    long long matrix[m][n], count = 0, ck;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // основная логика
    for (int i = 0; i < n; i++) {
        ck = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[j][i] == 0) {
                ck++;
            }
        }
        if (ck > 0) count++;
    }
    
    cout << "количество: " << count << "\n";
}

void lab5_task4() {
    const int m = 5;
    const int n = 7;
    long long matrix[m][n], positive_count = 0, negative_count = 0;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // Проход по всем элементам матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) positive_count++;
            if (matrix[i][j] < 0) negative_count++;
        }
    }
    
    if (positive_count > negative_count) {
        cout << "Положительных элементов больше! (" << positive_count << " " << negative_count << ")\n";
    } else {
        cout << "Отрицательных элементов больше! (" << positive_count << " " << negative_count << ")\n";
    }
}

void lab5_task5() {
    const int m = 8;
    const int n = 8;
    long long matrix[m][n], mx_element, mx_element_id = 0, multi = 1;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10 + 1);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // находим наибольший элемент главной диагонали
    mx_element = matrix[0][0];
    for (int i = 0; i < m; i++) {
        if (matrix[i][i] > mx_element) {
            mx_element = matrix[i][i];
            mx_element_id = i;
        }
    }
    
    // находим произведение в строке
    for (int i = 0; i < n; i++) {
        multi *= matrix[mx_element_id][i];
    }
    cout << "id наибольшего элемента: " << mx_element_id << "\n";
    cout << "произведение: " << multi << "\n";
}

void lab5_task6() {
    const int m = 6;
    const int n = 6;
    long long matrix[m][n], main_sum = 0, side_sum = 0;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // находим сумму на главной диагонали
    for (int i = 0; i < n; i++) main_sum += matrix[i][i];
    
    // находим сумму на побочной диагонали
    for (int i = 0; i < m; i++) side_sum += matrix[i][n - 1 - i];
    
    
    if (main_sum < side_sum) {
        cout << "Сумма главной диагонали меньшне: (" << main_sum << " " << side_sum << ")\n";
    } else {
        cout << "Сумма побочной диагонали меньшне: (" << main_sum << " " << side_sum << ")\n";
    }
}

void lab5_task7() {
    const int m = 5;
    const int n = 10;
    int matrix[m][n], count = 0;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // основная логика
    for (int i = 0; i < m; i++) {
        for (int j = 4; j < 6; j++) {
            if (matrix[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
}

void lab5_task8() {
    const int m = 6;
    const int n = 6;
    int matrix[m][n], count = 0;
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10 - 5);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // основная логика
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((abs(matrix[i][j]) % 2 == 0) && ((matrix[i][j] > -15) && (matrix[i][j] < 15))) {
                count++;
            }
        }
    }
    cout << count << "\n";
}

void lab5_task9() {
    const int m = 5;
    const int n = 5;
    int matrix[m][n];
    
    srand(static_cast<unsigned int>(time(0)));  // Генерация случайных чисел
    
    // Генерируем матрицу
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = static_cast<int>(rand() % 10);
    
    // Выводим изначальную матрицу
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    // основная логика
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 ==0) {
                cout << (j + 1) + (m * i) << "\t";
            } else {
                cout << "-" << "\t";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void view_parking(int matrix[][10], int level, int quantity) {
        // Выводим схему парковки без резервации
        cout << "Схема парковки: \n";
        for (int i = 0; i < level; i++) {
            cout << i + 1 << "-й этаж: |";
            for (int j = 0; j < quantity; j++) {
                cout << matrix[i][j] << "|";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
}

void lab5_task10_2() {
    const int level = 3;
    const int quantity = 10;
    int matrix[level][quantity], reservation[2] = {0, 0};
    bool input = true;
        
    // Генерируем матрицу
    for (int i = 0; i < level; i++)
        for (int j = 0; j < quantity; j++)
            matrix[i][j] = j + 1;
    
    view_parking(matrix, level, quantity);
    
    while (true) {
        cout << "Хотите забронировать место? (1/0)\n";
        cin >> input;
        if (!input) {
            cout << "До свидания!\n";
            break;
        }
        cout << "Введите номер этажа: ";
        cin >> reservation[0];
        cout << "\nВведите номер места: ";
        cin >> reservation[1];
        if (reservation[0] < 1 || reservation[1] < 1) {
            cout << "Неправильные данные! Введите заново\n";
            continue;
        }
        if (reservation[0] > level || reservation[1] > quantity) {
            cout << "Неправильные данные! Введите заново\n";
            continue;
        }
        
        if (matrix[reservation[0] - 1][reservation[1] - 1] == 0) {
            cout << "Место уже забронировано! Попробуйте другое!\n";
            continue;
        }
        
        matrix[reservation[0] - 1][reservation[1] - 1] = 0;
        view_parking(matrix, level, quantity);
        cout << "Вы успешно забронировали место!\n";
    }
}

int main()
{
    lab5_task10_2();
    return 0;
}
