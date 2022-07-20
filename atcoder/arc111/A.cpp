#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod;

ll binpow(ll b, ll e) {
    if (!e) return 1;
    if (e&1) return b*binpow(b, e-1)%mod;
    return binpow(b*b%mod, e/2);
}

int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    mod = m*m;
    printf("%lld", binpow(10, n) / m % m);
    return 0;
}