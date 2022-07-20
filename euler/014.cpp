#include <bits/stdc++.h>
using namespace std;

const int N = 3e6+5;

long long dp[N];

long long collatz(long long x) {
    if (x < N && dp[x] != -1) return dp[x];
    long long ret = 1+collatz((x%2)?3*x+1:(x/2));
    if (x < N) dp[x] = ret;
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    long long ans = -1, mans = -1;
    dp[1] = 1;
    for (int i = 1; i <= 1e6; ++i) {
        long long cur = collatz(i);
        if (cur > mans) {
            mans = cur;
            ans = i;
        }
    }
    printf("%lld", ans);
    return 0;
}