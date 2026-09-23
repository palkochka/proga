#include <iostream>
#include <cmath>
using namespace std;

// Функция, которая определяет есть ли у числа делители
bool IsPrime(int N) {
    // Достаточно проверять делители до квадратного корня из N
    int n = sqrt(N);
    
    // Пропускаем четные делители
    for (int i = 3; i <= n; i += 2)
        if ((N % i) == 0) 
            return false;
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    if (N < 2) {
        cout << "There are no prime numbers up to N.";
        return 0;
    }
    
    cout << "1-" << min(N, 20) << ":  2  ";
    
    // Проходимся по нечётным числам, т.к. помимо 2 не существует простых четных чисел
    for (int i = 3; i <= N; i += 2) {
        // Разбиение в блоки по 20 чисел
        if (((i - 1) % 20) == 0)
            cout << "\n" << i << "-" << min(N, i+19) << ":  ";
        
        // Вызов функции для проверки на простоту
        if (IsPrime(i))
            cout << i << "  ";
    }
    
    return 0;
}
