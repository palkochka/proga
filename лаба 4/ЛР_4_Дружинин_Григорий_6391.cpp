#include <iostream>
using namespace std;

// Реализация обычной пузырьковой сортировки
void BubbleSort(long long* arr) {
    for (int i = 0; i < 14; ++i)
        for (int j = 0; j < (14 - i); ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    return;
}

int main() {
    // Задаем переменные, где будут храниться минимумы, заранее записывая в них максимально возможное число
    long long Min1 = 0x7fffffffffffffff;
    long long Min2 = 0x7fffffffffffffff;
    long long Min3 = 0x7fffffffffffffff;

    // Объявляем массив из 15 элементов
    long long arr[15];
    for (int i = 0; i < 15; ++i) {
        cin >> arr[i];

        // Нахождение минимумов каждой 5 элементов 
        if (i < 5)
            if (Min1 > arr[i])
                Min1 = arr[i];
        if ((i >= 5) && (i < 10))
            if (Min2 > arr[i])
                Min2 = arr[i];
        if (i >= 10)
            if (Min3 > arr[i])
                Min3 = arr[i];
    }
    cout << "a)  " << Min1 << "  " << Min2 << "  " << Min3 << endl;

    // Определяем, существует ли возрастающая последовательность идущих подряд степеней двойки
    int PosStep2 = -1;
    for (int i = 0; i < 15; ++i) {
        // Быстрая проверка на степень 2
        if (!(arr[i] & (arr[i] - 1))) {
            if (PosStep2 == -1)
                PosStep2 = i + 1;
            else if (arr[i] <= arr[i - 1])
                PosStep2 = -1;
        }
        else {
            PosStep2 = -1;
        }
    }

    // Сортируем массив, а затем выводим его
    BubbleSort(arr);
    cout << "b)  ";
    for (int i = 0; i < 15; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Нахождение повторяющихся чисел
    int Cnt = 0;
    for (int i = 1; i < 15; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++Cnt;

            while ((i < 15) && (arr[i] == arr[i - 1])) ++i;
        }
    }
    cout << "v)  " << Cnt << endl;

    cout << "g)  " << PosStep2 << endl;
    return 0;
}
