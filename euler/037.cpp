#include <bits/stdc++.h>
using namespace std;

set<long long> primes;

int digits(long long x) {
    if (x == 0) return 0;
    return 1 + digits(x/10);
}

bool tleft(long long x, int d) {
    if (x < 10) return primes.count(x);
    x %= (long long)pow(10, d-1);
    return primes.count(x) && tleft(x, d-1);
}

bool tright(long long x) {
    if (x < 10) return primes.count(x);
    return primes.count(x) && tright(x/10);
}

int main() {
    vector<long long> ans;
    long long res = 0;
    primes.insert(2);
    for (long long i = 3; ans.size() < 11; i += 2) {
        for (long long p: primes) {
            if (i % p == 0) break;
            if (p*p > i) {
                primes.insert(i);
                break;
            }
        }
        if (*primes.rbegin() != i) continue;
        if (i < 10) continue;
        if (tleft(i, digits(i)) && tright(i)) {
            ans.push_back(i);
            printf("new: %lld\n", i);
            res += i;
        }
    }
    printf("%lld\n", res);
    return 0;
}