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
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a; scanf("%d", &a);
        ans += a;
    }
    ans = n-ans;
    printf("%d", ans>=0?ans:-1);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}