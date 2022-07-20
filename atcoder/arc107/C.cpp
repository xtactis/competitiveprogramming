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

const int N = 52;
const int mod = 998244353;

int a[N][N];
long long f[N];
vector<int> p[N], q[N];
bool bio[N];

int dfs(const vector<int> vec[N], int u) {
  bio[u] = 1;
  int ret = 1;
  for (int v: vec[u]) {
    if (bio[v]) continue;
    ret += dfs(vec, v);
  }
  return ret;
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i-1]*i%mod;
  }
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      bool f = 1, g = 1;
      for (int l = 0; l < n && (f || g); ++l) {
	if (a[i][l]+a[j][l] > k) f = 0;
	if (a[l][i]+a[l][j] > k) g = 0;
      }
      if (f) {
	p[i].push_back(j);
	p[j].push_back(i);
      }
      if (g) {
	q[i].push_back(j);
	q[j].push_back(i);
      }
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    ans = ans * f[dfs(q, i)] % mod;
  }
  memset(bio, 0, sizeof(bio));
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    ans = ans * f[dfs(p, i)] % mod;
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
