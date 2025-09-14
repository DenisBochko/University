
const int N = 3;

void input_matrix(int matrix[N][N]) {
    cout << "Введите элементы матрицы (" << N << "x" << N << "):" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int matrix[N][N]) {
    cout << "Матрица: " << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void sum_matrix(int a[N][N], int b[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void diff_matrix(int a[N][N], int b[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrix(int a[N][N], int b[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void scalar_multiply_matrix(int matrix[N][N], int scalar, int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

int main() {
    int A[N][N], B[N][N];
    int result1[N][N], result2[N][N], result3[N][N], result4[N][N];

    // Ввод
    input_matrix(A);
    input_matrix(B);

    // 1
    scalar_multiply_matrix(A, 3, result1);
    print_matrix(result1);
    
    // 2
    scalar_multiply_matrix(A, 2, result2);
    scalar_multiply_matrix(B, 3, result3);
    diff_matrix(result2, result3, result2);
    print_matrix(result2);
        
    // 3
    multiply_matrix(A, B, result3);
    print_matrix(result3);
    
    // 4
    scalar_multiply_matrix(A, 4, result4);
    sum_matrix(result4, result3, result4);
    print_matrix(result4);

    return 0;
}
