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

long long fifth(long long x) {
    long long t = x;
    x *= x;
    x *= x;
    return x*t;
}

void solve() {
    int n; scanf("%d", &n);
    for (long long a = -4000; a <= 4000; ++a) {
        for (long long b = -4000; b <= 4000; ++b) {
            if (fifth(b)-fifth(a) == n) {
                printf("%d %d\n", b, a);
                return;
            }
        }
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