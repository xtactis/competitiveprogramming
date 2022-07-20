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

void solve() {
    int n, k; scanf("%d%d", &n, &k);
    long long ans = 0;
    for (int b = 1; b <= n; ++b) {
        ans += (n/b)*max(0, b-k) + max(0, n%b - k + 1);
        ans -= (0%b>=k);
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