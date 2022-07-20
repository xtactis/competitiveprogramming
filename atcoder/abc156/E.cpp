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

const int N = 2e5+23;
const int mod = 1e9+7;

long long f[N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

long long C(int n, int k) {
  return f[n] * binpow(f[k], mod-2) % mod * binpow(f[n-k], mod-2) % mod;
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = f[i-1] * i % mod;
  long long ans = 0;
  for (int i = 0; i <= min(n-1, k); ++i) {
    ans = (ans + C(n, i)*C(n-1, i)%mod) % mod;
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
