#include <iostream>

using namespace std;

const int ROWS_A = 3;
const int COLS_A = 2;
const int ROWS_B = 2;
const int COLS_B = 4;
const int ROWS = 3;
const int COLS = 3;
const int MAXN = 4;

void inputMatrix(long long m[][MAXN], int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> m[i][j];
}

int numLen(long long x) {
    int len = (x < 0) ? 2 : 1;
    while (x > 9 || x < -9) {
        x /= 10;
        ++len;
    }
    return len;
}

void printMatrix(long long m[][MAXN], int rows, int cols) {
    int width = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (numLen(m[i][j]) > width)
                width = numLen(m[i][j]);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int s = numLen(m[i][j]); s < width + 1; ++s)
                cout << ' ';
            cout << m[i][j];
        }
        cout << endl;
    }
}

// c (n x p) = a (n x k) * b (k x p)
void multiply(long long a[][MAXN], long long b[][MAXN], long long c[][MAXN], int n, int k, int p) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for (int t = 0; t < k; ++t)
                c[i][j] += a[i][t] * b[t][j];
        }
}

void task1() {
    if (COLS_A != ROWS_B) {
        cout << "Перемножение невозможно: число столбцов A не равно числу строк B" << endl;
        return;
    }

    long long A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

    cout << "Введите матрицу A (" << ROWS_A << "x" << COLS_A << "), по строкам:" << endl;
    inputMatrix(A, ROWS_A, COLS_A);
    cout << "Введите матрицу B (" << ROWS_B << "x" << COLS_B << "), по строкам:" << endl;
    inputMatrix(B, ROWS_B, COLS_B);

    multiply(A, B, C, ROWS_A, COLS_A, COLS_B);

    cout << "Результат C = A * B (" << ROWS_A << "x" << COLS_B << "):" << endl;
    printMatrix(C, ROWS_A, COLS_B);
}

void task2() {
    if (ROWS != COLS) {
        cout << "Возведение в степень невозможно: матрица " << ROWS << "x" << COLS << " не квадратная" << endl;
        return;
    }

    long long A[MAXN][MAXN], result[MAXN][MAXN], temp[MAXN][MAXN];

    cout << "Введите матрицу A (" << ROWS << "x" << COLS << "), по строкам:" << endl;
    inputMatrix(A, ROWS, COLS);

    int power;
    cout << "Введите степень (целое положительное число): ";
    cin >> power;
    if (power <= 0) {
        cout << "Степень должна быть положительной" << endl;
        return;
    }

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            result[i][j] = A[i][j];

    for (int step = 1; step < power; ++step) {
        multiply(result, A, temp, ROWS, ROWS, ROWS);
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < ROWS; ++j)
                result[i][j] = temp[i][j];
    }

    cout << "Результат A^" << power << " (" << ROWS << "x" << COLS << "):" << endl;
    printMatrix(result, ROWS, COLS);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    cout << "Выберите задание (1 - перемножение матриц, 2 - возведение матрицы в степень): ";
    cin >> choice;

    if (choice == 1)
        task1();
    else if (choice == 2)
        task2();
    else
        cout << "Нет такого задания" << endl;

    return 0;
}
