#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int mat[N][N];
int dp[N][N];

int main() {
    memset(mat, -1, sizeof(mat));
    memset(dp, -1, sizeof(dp));
    int n; scanf("%d", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    dp[0][0] = mat[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = mat[i][0] + dp[i-1][0];
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[n-1][i]);
    printf("%d", ans);
}