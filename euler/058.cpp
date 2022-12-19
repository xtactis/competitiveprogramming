#include <bits/stdc++.h>

using namespace std;

bool isprime(long long x) {
    if (x % 2 == 0) return false;
    for (int i = 3, lim = sqrt(x); i < lim; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int d_primes = 0;
    int total = 1;
    for (long long i = 3; ; i+=2) {
        long long nine = i*i;
        long long seven = nine-(i-1);
        long long five = seven-(i-1);
        long long three = five-(i-1);
        d_primes += isprime(seven)+isprime(five)+isprime(three);
        total += 4;
        if ((float)d_primes/total < 0.1) {
            printf("%lld\n", i);
            break;
        }
    }

    return 0;
}
