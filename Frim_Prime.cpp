#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate (a^b) % m using modular exponentiation
long long power(long long a, unsigned long long b, long long m) {
    if (b == 0) return 1;
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

// Function to perform Fermat Primality Test
bool isPrime(long long p, int iterations) {
    // Base cases
    if (p <= 1) return false;
    if (p <= 3) return true;

    // Repeat the test for accuracy
    for (int i = 0; i < iterations; ++i) {
        // Choose a random number 'a' such that 2 <= a <= p-2
        long long a = 2 + rand() % (p - 3);

        // Check if a^(p-1) ≡ 1 (mod p)
        if (power(a, p - 1, p) != 1)
            return false; // p is composite
    }

    return true; // p is likely prime
}

int main() {
    long long n;
    cout << "Enter a number to test for primality: ";
    cin >> n;

    int iterations = 5; // Number of iterations for accuracy

    if (isPrime(n, iterations))
        cout << n << " is likely prime." << endl;
    else
        cout << n << " is composite." << endl;

    return 0;
}
