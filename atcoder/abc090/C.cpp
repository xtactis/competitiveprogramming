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
    int n, m; scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    long long ans = 0;
    if (n == 1 && m == 1) {
        ans = 1;
    } else if (n == 1) {
        ans = m-2;
    } else {
        ans = (long long)(n-2)*(m-2);
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

