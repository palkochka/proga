#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct STUDENT {
    string FIO[3] = {"","",""};
    int group = 0;
    int score[5] = {0,0,0,0,0};
};

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите количество студентов: ";
    cin >> N;

    if (N <= 0) {
        cout << "Нет данных для обработки" << endl;
        return 0;
    }

    // ПУНКТ (a)
    cout << "Введите данные каждого студента по очереди (Фамилия Имя Отчество, номер группы, 5 оценок):\n";
    STUDENT* arr = new STUDENT[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].FIO[0] >> arr[i].FIO[1] >> arr[i].FIO[2];
        cin >> arr[i].group;
        for (int j = 0; j < 5; ++j)
            cin >> arr[i].score[j];
    }
    cout << endl;

    // ПУНКТ (б) - Сортировка по возрастанию номера группы
    sort(arr, arr + N, [](const STUDENT& a, const STUDENT& b) {
        return a.group < b.group;
        });

    // ПУНКТ (в) - Студенты со средним баллом > 4.0
    // Сумма 5 оценок > 20 означает средний балл > 4.0
    bool flag = false;
    cout << "--- Студенты со средним баллом > 4.0 ---" << endl;
    for (int i = 0; i < N; ++i) {
        int sum = arr[i].score[0] + arr[i].score[1] + arr[i].score[2] + arr[i].score[3] + arr[i].score[4];
        if (sum > 20) {
            cout << arr[i].FIO[0] << " " << arr[i].group << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << "Таких студентов нет" << endl;
    }

    // ПУНКТ (г)
    cout << "\n--- Статистика по группам ---" << endl;

    // Считаем количество уникальных групп (массив уже отсортирован)
    int size = 1;
    for (int i = 1; i < N; ++i) {
        if (arr[i].group != arr[i - 1].group) {
            ++size;
        }
    }

    int** result = new int* [size];
    for (int i = 0; i < size; ++i) {
        result[i] = new int[3]();
    }

    // Заполняем таблицу
    int group_idx = -1;
    for (int i = 0; i < N; ++i) {
        if (i == 0 || arr[i].group != arr[i - 1].group) {
            ++group_idx;
            result[group_idx][0] = arr[i].group; 
        }

        ++result[group_idx][1];

        int sum = arr[i].score[0] + arr[i].score[1] + arr[i].score[2] + arr[i].score[3] + arr[i].score[4];
        // Если средний балл <= 2.6 (сумма <= 13) - считаем двоечником
        if (sum <= 13) {
            ++result[group_idx][2];
        }
    }

    // Сортируем таблицу по убыванию количества двоечников (индекс 2)
    sort(result, result + size, [](const int* a, const int* b) {
        return a[2] > b[2];
    });

    cout << "Номер группы | Кол-во студентов | Кол-во двоечников" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << result[i][0] << "\t\t | " << result[i][1] << "\t\t    | " << result[i][2] << endl;
    }

    for (int i = 0; i < size; ++i) 
        delete[] result[i];
    delete[] result; 
    delete[] arr;
    return 0;
}