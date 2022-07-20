#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int counts[N+1];
bool prime[N];
vector<int> primes;

int main() {
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j * j <= N; j += i) {
            prime[j] = true;
        }
    }
    for (int i = 2; i <= N; ++i) {
        int t = i;
        for (int p: primes) {
            int cnt = 0;
            while (t % p == 0) {
                t /= p;
                ++cnt;
            }
            counts[p] = max(counts[p], cnt);
        }
    }
    long long ans = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < counts[i]; ++j) ans *= i;
    }
    printf("%lld", ans);
    return 0;
}