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
const int N = 1e5+23;

vector<int> g[N];
vector<long long> e;
int k[N];
int n;

int dfs(int u, int p) {
  int ret = 1;
  for (int v: g[u]) {
    if (v == p) continue;
    int cur = dfs(v, u);
    e.push_back(1LL * cur * (n-cur));
    ret += cur;
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  for (int u, v, i = 0; i < n-1; ++i) {
    scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  int m; scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", k+i);
  }
  dfs(0, -1);
  sort(e.begin(), e.end(), greater<long long>());
  sort(k, k+m, greater<int>());
  long long ans = 0;
  int j = 0;
  if (n-1 < m) {
    long long cur = 1;
    for (; j < m-n+2; ++j) {
      cur = cur * k[j] % mod;
    }
    debug(e[0]);
    debug(cur);
    ans = (ans + cur * e[0] % mod) % mod;
  }
  debug(j);
  for (int i = ans != 0; i < n-1; ++i) {
    debug(e[i]);
    g[i].clear();
    if (j < m) {
      debug(k[j]);
      ans = (ans + k[j++] * e[i] % mod) % mod;
    } else {
      ans = (ans + e[i]) % mod;
    }
  }
  g[0].clear();
  g[n-1].clear();
  e.clear();
  debug(ans);
  printf("%lld\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
