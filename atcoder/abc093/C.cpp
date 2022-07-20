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
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    if (a%2 != b%2) {
        if (a%2 == c%2) ++a;
        else ++b;
        ++c; ++ans;
    } else if (a%2 != c%2) {
        if (a%2 == b%2) ++a;
        else ++c;
        ++b; ++ans;
    } else if (b%2 != c%2) {
        if (b%2 == a%2) ++b;
        else ++c;
        ++a; ++ans;
    }
    int v[3] = {a, b, c};
    sort(v, v+3);
    cout << ans+(v[1]-v[0])/2+(v[2]-v[1]);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}