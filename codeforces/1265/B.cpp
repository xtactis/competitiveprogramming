#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int a[N];
int maxi[N];
int dp[N];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        bool one = false;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
            if (one) m = maxi[a[i]] = max(m, a[i]);
            if (a[i] == 1) one = true;
        }
        one = false;
        m = 0;
        for (int i = n-1; i >= 0; --i) {
            if (one) m = maxi[a[i]] = max(m, a[i]);
            if (a[i] == 1) one = true;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, maxi[i]);
            printf("%d", ans<=i);
        }
        printf("\n");
    }
    return 0;
}
