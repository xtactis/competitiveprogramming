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

const int M = 321;
const int N = 90034;

int a[M][M];
int x[N], y[N];
int c[N];

void solve() {
    int h, w, d; scanf("%d%d%d", &h, &w, &d);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", a[i]+j);
            x[a[i][j]] = j; y[a[i][j]] = i;
        }
    }
    for (int i = 1; i <= h*w; ++i) {
        if (c[i]) continue;
        for (int j = i+d; j <= h*w; j+=d) {
            c[j] = c[j-d]+abs(x[j]-x[j-d])+abs(y[j]-y[j-d]);
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        debug(c[r]);
        debug(c[l]);
        printf("%d\n", c[r]-c[l]);
    }
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}