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
    int a, b, k; cin >> a >> b >> k;
    for (int i = a; i < a+k && i <= b; ++i) {
        cout << i << '\n';
    }
    for (int i = max(b-k, a+k+1)+1; i <= b; ++i) {
        cout << i << '\n';
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