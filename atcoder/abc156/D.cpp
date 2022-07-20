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

const int mod = 1e9+7;

long long binpow(long long b, int e) {
    if (e == 0) return 1;
    if (e&1) return b*binpow(b, e-1)%mod;
    return binpow(b*b%mod, e/2);
}

int sub(int a, int b) {
    return (a-b+mod)%mod;
}

int div(long long a, int b) {
    return a*binpow(b, mod-2)%mod;
}

long long choose(int n, int k) {
    long long res = 1;
    for (int i = n-k+1; i <= n; ++i) {
        res = (res*i)%mod;
    }
    for (int i = 2; i <= k; ++i) {
        res = div(res, i);
    }
    return res%mod;
}

void solve() {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    int ans = binpow(2, n)-1;
    printf("%d", sub(sub(ans, choose(n, a)), choose(n, b)));
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}