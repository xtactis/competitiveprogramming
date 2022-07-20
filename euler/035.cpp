#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

bool notprime[N];
set<int> primes;

int main() {
    primes.insert(2);
    for (int i = 3; i < N; i += 2) {
        if (notprime[i]) continue;
        primes.insert(i);
        for (int j = 2*i; j < N; j += i) {
            notprime[j] = true;
        }
    }
    int ans = 0;
    for (int e: primes) {
        int t = e, p = 1;
        while (p <= e) p *= 10;
        p /= 10;
        bool good = true;
        do {
            //printf("%d %d\n", t, p);
            t = t / 10 + (t % 10 * p);
            if (!primes.count(t)) good = false;
        } while (good && t != e);
        if (good) ++ans;
    }
    printf("%d", ans);
    return 0;
}