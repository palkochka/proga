#include <iostream>
using namespace std;

int main() {
    long long N = 0;
    long double Sum = 0;
    // Объявляем переменную Max с наименьшим возможным значением
    // Объявляем переменную Min с наибольшим возможным значением
    long long Max = 0x8000000000000000, Min = 0x7fffffffffffffff;
    long long Memory1 = 0;
    long long Memory2 = 0;

    int CountNumMod5 = 0;
    int CountNumStep2 = 0;
    int dop = 0;

    long long Num;
    while ((cin >> Num) && (Num != 0)) {
        cout << "\n";
        ++N;
        Sum += Num;
        // Если максимум меньше текущего числа, то он будет равен текущему числу
        if (Max < Num) Max = Num;
        // Если минимум больше текущего числа, то он будет равен текущему числу
        if (Min > Num) Min = Num;
        // Проверка на кратность 5 и положительное число
        if ((Num > 0) && ((Num % 5) == 0)) ++CountNumMod5;
        // Быстрая проверка на степень двойки через побитовые операции
        if ((Num > 0) && !(Num & (Num - 1))) ++CountNumStep2;
        // Проверка, больше ли число суммы двух предыдущих 
        if ((N >= 3) && (Num > (Memory2 + Memory1))) ++dop;

        // Запоминаем предыдущие 2 числа
        Memory2 = Memory1;
        Memory1 = Num;
    }

    cout << "\na) " << Sum / N;
    cout << "\nb) " << Max - Min;
    cout << "\nv) " << CountNumMod5;
    cout << "\ng) " << CountNumStep2;
    cout << "\nd) " << dop;
    return 0;
}
