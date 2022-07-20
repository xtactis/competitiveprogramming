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

const int N = 3e5+23;
const int mod = 998244353;

pair<int, int> p[N];
int n, k;
long long fact[N], invf[N];

long long binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}

long long C(int n, int k) {
  if (k > n) return 0;
  return fact[n]*invf[k]%mod*invf[n-k]%mod;
}

void solve() {
  scanf("%d%d", &n, &k);
  fact[0] = 1;
  invf[0] = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i].first, &p[i].second);
    fact[i+1] = fact[i]*(i+1)%mod;
    invf[i+1] = binpow(fact[i+1], mod-2);
  }
  long long ans = 0;
  debug(ans);
  sort(p, p+n);
  multiset<int> m;
  for (int i = 0; i < n; ++i) {
    while (m.size() && *m.begin() < p[i].first) m.erase(m.begin());
    ans = (ans + C(m.size(), k-1)) % mod;
    m.insert(p[i].second);
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
