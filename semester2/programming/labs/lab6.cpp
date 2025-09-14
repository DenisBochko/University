//--------------- lab 6 ------------------

void lab6_1_1() {
    float x=-8.92;
    int y=5;
    cout<<"sizeof x="<< sizeof x <<endl;
    cout<<"sizeof y=" << sizeof y <<endl;
    cout<<"sizeof x+y=" << sizeof x +y<<endl; // sizeof(x) + 5
    cout<<"sizeof (x+y)=" << sizeof (x+y)<<endl; // приведение типа
    cout<<"sizeof x*2+1=" << sizeof x *2+1<<endl; // 4 * 2 + 1 = 9
    cout<<"sizeof 2*y+1=" << sizeof 2*y+1<<endl; // 4 * 5 + 1 = 21 (sizeof2 - int => 4 байта)
    // cout<<"sizeof ++y*2="<< sizeof ++y*2 <<endl; // (sizeof (++y)) * 2 // sizeof не вычисляет выражение
    // cout<<"sizeof y--*2="<<sizeof y--*2 <<endl;
}

void lab6_1_2() {
    cout << "Размеры базовых типов:" << endl;
    cout << "char:        " << sizeof(char) << " байт" << "\n";
    cout << "short:       " << sizeof(short) << " байт" << "\n";
    cout << "int:         " << sizeof(int) << " байт" << "\n";
    cout << "long:        " << sizeof(long) << " байт" << "\n";
    cout << "float:       " << sizeof(float) << " байт" << "\n";
    cout << "double:      " << sizeof(double) << " байт" << "\n";
    cout << "long double: " << sizeof(long double) << " байт" << "\n";
    
    cout << "\nРазмеры указателей на базовые типы:" << "\n";
    cout << "char*:        " << sizeof(char*) << " байт" << "\n";
    cout << "int*:         " << sizeof(int*) << " байт" << "\n";
    cout << "long*:        " << sizeof(long*) << " байт" << "\n";
    cout << "float*:       " << sizeof(float*) << " байт" << "\n";
    cout << "double*:      " << sizeof(double*) << " байт" << "\n";
    cout << "long double*: " << sizeof(long double*) << " байт" << "\n";
}

void lab6_2() {
    int x = 42;
    //объявить указатель на целое число
    int *pX;
    //присвоить адрес переменной х этому указателю
    pX = &x;
    //вывести значение переменной х, используя указатель
    cout << *pX << "\n";
}

void lab6_3(){
    // указатели двигаются вперёд или назад на sizeof(char) = 1, sizeof(int) = 4, sizeof(double) = 8
    char c = 'A';
    int i = 42;
    double d = 3.14;
    
    char *pc = &c;
    int *pi = &i;
    double *pd = &d;
    
    cout << "char:" << "\n";
    cout << "  адрес:      " << static_cast<const void*>(pc) << "\n"; // нужно чтобы напечатать именно указатель, а не символ
    cout << "  адрес + 2:  " << static_cast<const void*>(pc + 2) << "\n";
    cout << "  адрес - 1:  " << static_cast<const void*>(pc - 1) << "\n";
    
    cout << "\nint:" << "\n";
    cout << "  адрес:      " << pi << "\n";
    cout << "  адрес + 2:  " << pi + 2 << "\n";
    cout << "  адрес - 1:  " << pi - 1 << "\n";
    
    cout << "\ndouble:" << "\n";
    cout << "  адрес:      " << pd << "\n";
    cout << "  адрес + 2:  " << pd + 2 << "\n";
    cout << "  адрес - 1:  " << pd - 1 << "\n";
}

void lab6_4() {
    int mas[5] = {1, 2, -5, -7, 10};
    
    for (int i = 0; i < 5; i++) {
        cout << "Указатель: " << mas + i << " Значение: " << *(mas + i) << "\n";
    }
}

void lab6_5() {
    double arr[] = {0, 4.5, -1.1, 8, 7.4, 197};
    int count_of_elements = sizeof(arr) / sizeof(double);
    cout << "Массив: arr, элементов: "<< count_of_elements << "\n";
    
    for (int i = 0; i < count_of_elements; i++) {
        cout << "arr[0] = " << *(arr + i) << "\n";
    }
}

void lab6_6() {
    // 1
    int arr[5] = {1, 2, -5, -7, 10};
    cout << "arr: " << arr << "\n\n";
    
    // 2
    for (int i = 0; i < 5; i++) {
        cout << "&arr[" << i << "] = " << &arr[i] << "\n";
    }
    
    // 3
    for (int i = 0; i < 5; i++) {
        *(arr + i) = i;
    }
    
    // 4
    // arr = (arr + 2); // arr — это константный указатель, изменить нельзя, ошбика компиляции
    
    // 5
    int *pArr;
    pArr = (arr + 2);
    
    // 6
    // Вывод значений, начиная с pArr
    cout << "\nВывод элементов от pArr (pArr = arr + 2):" << "\n";
    for (int i = -2; i <= 2; i++) { // чтобы охватить весь массив
        cout << "pArr[" << i << "] = " << *(pArr + i) << "\n";
    }
}

void lab6_7() {
    srand(static_cast<unsigned int>(time(0)));
    int size;
    
    cout << "Введите размер динамического массива: ";
    cin >> size;
    
    //выделяем память для массива размером size
    int *arr = new int[size];
    
    //заполним массив случайными значениями
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    
    //выводим массив на экран
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    delete []arr;
}

void lab6_8() {
    int size, mx, mx_id;
    
    cout << "Введите размер динамического массива: ";
    cin >> size;
    
    //выделяем память для массива размером size
    int *arr = new int[size];
    
    // заполняем значениями
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент массива: ";
        cin >> arr[i];
    }
    
    mx = arr[0];
    mx_id = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            mx_id = i;
        }
    }
    
    cout << "Максимальный элемент: " << mx << " Его индекс: " << mx_id << "\n";
    
    delete []arr;
}

void lab6_9() {
    srand(static_cast<unsigned int>(time(0)));
    int size1, size2;
    
    cout << "Введите размер первого динамического массива: ";
    cin >> size1;
    
    cout << "Введите размер второго динамического массива: ";
    cin >> size2;
    
    // выделяем память для массивов размером size1,2 и результирующего
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    int *arr3 = new int[size1 + size2];
    
    // заполним первый массив случайными значениями
    for (int i = 0; i < size1; i++) {
        arr1[i] = rand() % 10;
    }
    
    // заполним второй массив случайными значениями
    for (int i = 0; i < size2; i++) {
        arr2[i] = rand() % 10;
    }
    
    // объединение массивов
    for (int i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr3[size1 + i] = arr2[i];
    }

    // вывод всех массивов
    cout << "\nПервый массив: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nВторой массив: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }

    cout << "\nОбъединённый массив: ";
    for (int i = 0; i < (size1 + size2); i++) {
        cout << arr3[i] << " ";
    }
    cout << "\n";

    // очистка памяти
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

void lab6_10() {
    srand(static_cast<unsigned int>(time(0)));
    int N, count_of_odd, offset;
    
    cout << "Введите размер масссива: ";
    cin >> N;
    
    // выделяем память под изначальный массив
    int *arr1 = new int[N];
    
    count_of_odd = 0;
    offset = 0;
    
    for (int i = 0; i < N; i++) {
        *(arr1 + i) = rand() % 10;
    }
    
    // подсчитывем количество нечётных в изначально массиве
    for (int i = 0; i < N; i++) {
        if (*(arr1 + i) % 2 != 0) {
            count_of_odd++;
        }
    }
    
    // выделяем память под новый массив
    int *arr2 = new int[count_of_odd];
    
    for (int i = 0; i < N; i++) {
        if (*(arr1 + i) % 2 != 0) {
            *(arr2 + offset) = *(arr1 + i);
            offset++;
        }
    }
    
    cout << "Изначальный массив: ";
    for (int i = 0; i < N; i++) cout << *(arr1 + i) << " ";
    cout << "\n";
    cout << "Результирующий массив: ";
    for (int i = 0; i < count_of_odd; i++) cout << *(arr2 + i) << " ";
    cout << "\n";
    
    // очистка памяти
    delete[] arr1;
    delete[] arr2;
}

int main()
{
    lab6_10();
    return 0;
}

