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

map<string, int> z;

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        ++z[s];
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        --z[s];
    }
    int ans = 0;
    for (const auto &e: z) {
        ans = max(ans, e.second);
    }
    cout << ans;
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}