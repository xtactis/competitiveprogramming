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

int a[N];

void solve() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    int S = 0;
    for (int i = 0; i < k; ++i) {
        S += a[i];
    }
    int ss = S, f = 1;
    for (int i = k; i < n; ++i) {
        ss -= a[i-k];
        ss += a[i];
        if (ss != S) f = 0;
    }
    if (f) {
        puts("-1");
        return;
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (!s.count(a[i])) {
            ans.push_back(a[i]);
            s.insert(a[i]);
            continue;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int e: ans) printf("%d ", e);
    puts("");
}

int main() {
    int t = 1; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
