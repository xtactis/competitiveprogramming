#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 2e5+34;

int a[N];
int h[N];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", h+i);
        a[i] = i+1-h[i];
    }
    sort(a, a+n);
    long long ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int x = i+1+h[i];
        const auto p = equal_range(a, a+n, x);
        ans += p.second-p.first;
    }
    printf("%lld", ans);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}