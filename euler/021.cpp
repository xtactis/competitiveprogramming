#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int dp[N];

int d(int n) {
    if (dp[n] != -1) return dp[n];
    int ret = 0;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i) continue;
        ret += i;
        if (i != 1 && n/i != i) ret += n/i;
    }
    return dp[n] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        int b = d(i);
        if (b != i && d(b) == i) ans += b+i;
    }
    printf("%d", ans/2);
    return 0;
}