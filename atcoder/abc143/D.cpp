#include <bits/stdc++.h>
using namespace std;

int a[2345];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    sort(a, a+n);
    //for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    //printf("\n");
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int lo = a[j]-a[i], hi = a[i]+a[j];
            int x1 = lower_bound(a+j, a+n, lo)-a;
            int x2 = lower_bound(a+j, a+n, hi)-a;
            //printf("%d %d %d %d: %d %d\n", i, j, lo, hi, x1, x2);
            ans += max(0, x2-x1-1);
        }
    }
    printf("%d", ans);
    return 0;
}