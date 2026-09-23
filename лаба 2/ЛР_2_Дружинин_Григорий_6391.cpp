#include <iostream>
using namespace std;

int main() {
    long long N = 0;
    long double Ave = 0;
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
        Ave += Num;
        if (Max < Num) Max = Num;
        if (Min > Num) Min = Num;
        if ((Num > 0) && ((Num % 5) == 0)) ++CountNumMod5;
        if ((Num > 0) && !(Num & (Num - 1))) ++CountNumStep2;
        if ((N >= 3) && (Num > (Memory2 + Memory1))) ++dop;

        Memory2 = Memory1;
        Memory1 = Num;
    }

    cout << "\na) " << Ave / N;
    cout << "\nb) " << Max - Min;
    cout << "\nv) " << CountNumMod5;
    cout << "\ng) " << CountNumStep2;
    cout << "\nd) " << dop;
    return 0;
}
