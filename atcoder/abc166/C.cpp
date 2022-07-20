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

const int N = 1e5+34;
int h[N];
bool notit[N];

void solve() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", h+i);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        if (h[a] >= h[b]) {
            notit[b] = true;
        }
        if (h[a] <= h[b]) {
            notit[a] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += !notit[i];
    }
    printf("%d", ans);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}