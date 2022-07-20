#include <bits/stdc++.h>
using namespace std;

long long dp[21][21];

int main() {
    for (int i = 0; i <= 20; ++i) {
        dp[i][0] = dp[0][i] = 1;
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    printf("%lld %lld", dp[2][2], dp[20][20]);
    return 0;
}