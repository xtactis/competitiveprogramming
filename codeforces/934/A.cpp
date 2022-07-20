#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[69], b[69];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", b+i);
    }
    long long ans = LLONG_MAX;
    for (int rem = 0; rem < n; ++rem) {
        long long cur = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            if (i == rem) continue;
            for (int j = 0; j < m; ++j) {
                cur = max(cur, (long long)a[i]*b[j]);
            }
        }
        ans = min(ans, cur);
    }
    printf("%I64d", ans);
    return 0;
}