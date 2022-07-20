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

int n, k;
vector<int> g[N];
long long f[N];

long long binpow(long long b, long long e) {
  long long ret = 1;
  while (e) {
    if (e&1) {
      ret = ret * b % mod;
      --e;
    } else {
      b = b * b % mod;
      e /= 2;
    }
  }
  return ret;
}

long long dfs(int u, int r, int p) {
  long long rank = g[u].size();
  if (p != -1) --rank;
  if (k-r < rank) return 0;
  long long ret = f[k-r]*binpow(f[(k-r)-rank], mod-2)%mod;
  for (int v: g[u]) {
    if (v == p) continue;
    ret = ret * dfs(v, 2, u) % mod;
  }
  return ret;
}

void solve() {
  scanf("%d%d", &n, &k);
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = f[i-1] * i % mod;
  for (int u, v, i = 0; i < n-1; ++i) {
    scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  printf("%lld", dfs(0, 1, -1)*k%mod);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
