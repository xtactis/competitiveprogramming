#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

bool primes[N];

int main() {
    long long x = 600851475143;
    long long ans = 1;
    for (long long i = 4; i * i <= x; i += 2) primes[i] = true;
    for (long long i = 3; i * i <= x; i += 2) {
        if (primes[i]) continue;
        if (x % i == 0) {
            ans = i;
        }
        for (long long j = i + i; j * j <= x; j += i) {
            primes[j] = true;
        }
    }
    printf("%lld", ans);
    return 0;
}