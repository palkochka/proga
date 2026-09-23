#include <iostream>
#include <cmath>
using namespace std;

// A function that determines whether a number has divisors
bool IsPrime(int N) {
    // It is sufficient to check divisors up to the square root of N
    int n = sqrt(N);
    
    // We skip even divisors
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
    
    // We go through the odd numbers, since there are no even prime numbers other than 2
    for (int i = 3; i <= N; i += 2) {
        // Breaking into blocks of 20 numbers
        if (((i - 1) % 20) == 0)
            cout << "\n" << i << "-" << min(N, i+19) << ":  ";
        
        // Calling the function to check for primality
        if (IsPrime(i))
            cout << i << "  ";
    }
    
    return 0;
}
