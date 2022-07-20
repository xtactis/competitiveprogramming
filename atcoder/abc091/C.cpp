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

const int N = 123;
const int inf = 1e9;

struct Point {
    int x, y;
    int id;
    bool color;
} p[2*N];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < 2*n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
        p[i].color = i >= n;
    }
    sort(p, p+2*n, [](const Point &a, const Point &b){
        return a.x < b.x;
    });
    set<int> s;
    int ans = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (p[i].color) {
            if (s.size() == 0) continue;
            int sel, q = -1;
            for (const auto &e: s) {
                if (p[e].y < p[i].y && p[e].y > q) {
                    q = p[e].y;
                    sel = e;
                }
            }
            if (q == -1) continue;
            s.erase(sel);
            ++ans;
        } else {
            s.insert(i);
        }
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