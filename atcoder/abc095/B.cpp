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
    int n, x; scanf("%d%d", &n, &x);
    int m = 1001;
    for (int i = 0; i < n; ++i) {
        int t; scanf("%d", &t);
        m = min(m, t);
        x -= t;
    }
    printf("%d", n+x/m);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}