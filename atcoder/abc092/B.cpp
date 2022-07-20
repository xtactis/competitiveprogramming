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
    int n, d, x; scanf("%d%d%d", &n, &d, &x);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        for (int j = 0; j < d; ++j) {
            if (j%a) continue;
            ++ans;
        }
    }
    printf("%d", ans+x);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}