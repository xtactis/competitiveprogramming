#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;

bool prime[N+1];

int main() {
    long long ans = 0;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) continue;
        ans += i;
        for (int j = i + i; j  <= N; j += i) {
            prime[j] = true;
        }
    }
    printf("%lld", ans);
    return 0;
}