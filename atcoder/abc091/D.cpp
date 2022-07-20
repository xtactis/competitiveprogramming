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

int r[N][2], b[N][2];
bool used[N];
int cnt[N];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", r[i], r[i]+1);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", b[i], b[i]+1);
    }
    int ans = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == inf) continue;
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                if (r[i][0] < b[j][0] && r[i][1] < b[j][1]) ++cnt[i];
            }
        }
        int c = inf, ind = -1;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) continue;
            if (cnt[i] < c) {
                c = cnt[i];
                ind = i;
            }
        }
        if (c == inf) break;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            // I don't trust this
            if (r[ind][0] < b[i][0] && r[ind][1] < b[i][1]) {
                cnt[ind] = inf;
                used[i] = true;
                ++ans;
                break;
            }
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