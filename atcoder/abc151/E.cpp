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

const int N = 1e5+23;
const int mod = 1e9+7;

int a[N];
int fact[N];

int binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

int nCr(int n, int k) {
  return 1LL * fact[n] * binpow(fact[k], mod-2) % mod * binpow(fact[n-k], mod-2) % mod;
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  fact[0] = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (i) {
      fact[i] = 1LL*fact[i-1]*i%mod;
    }
  }
  sort(a, a+n);
  long long ans = 0;
  for (int i = n-1; i >= k-1; --i) {
    ans = (ans + 1LL * a[i] * nCr(i, k-1) % mod) % mod;
  }
  for (int i = 0; i <= n-k; ++i) {
    ans = (ans - (1LL * a[i] * nCr(n-i-1, k-1)) % mod + mod) % mod;
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
