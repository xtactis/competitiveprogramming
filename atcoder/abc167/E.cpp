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

const int mod = 998244353;
const int N = 2e5+23;

int n, m, k;
int f[N];

int binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

int C(int n, int k) {
  return 1LL * f[n] * binpow(f[k], mod-2) % mod * binpow(f[n-k], mod-2) % mod;
}

void solve() {
  scanf("%d%d%d", &n, &m, &k);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = 1LL * f[i-1] * i % mod;
  }
  long long ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans = ans + 1LL * m * C(n-1, i) % mod * binpow(m-1, n-1-i) % mod;
    ans %= mod;
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
