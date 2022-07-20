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

const int N = 42;

int a[N];
int n, t;
vector<long long> b;

void half(int n, long long s = 0) {
    if (n < 0) {
        b.push_back(s);
        return;
    }
    half(n-1, s);
    half(n-1, s+a[n]);
}

void solve() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    half(n/2);
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < (1 << (n-n/2)); ++i) {
        long long cur = 0;
        for (int j = n/2+1; j < n && cur <= t; ++j) {
            if (i & (1 << (j-n/2))) {
                cur += a[j];
            }
        }
        int x = upper_bound(b.begin(), b.end(), t-cur)-b.begin()-1;
        if (cur > t) continue;
        ans = max(ans, cur+b[x]);
    }
    
    printf("%lld", ans);
}

int main() {
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
