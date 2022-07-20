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
    int n, m, x; scanf("%d%d%d", &n, &m, &x);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < m; ++i) {
        int a; scanf("%d", &a);
        if (a < x) ++c1;
        else ++c2;
    }
    printf("%d", min(c1, c2));
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}