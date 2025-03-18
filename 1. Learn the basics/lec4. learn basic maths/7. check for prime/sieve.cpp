#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bool isPrime[N];

void sieve() {
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int n = 1483;
    if (isPrime[n]) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}