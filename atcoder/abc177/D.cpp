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

vector<int> g[N];
bool bio[N];

int dfs(int u) {
  bio[u] = 1;
  int ret = 1;
  for (int v: g[u]) {
    if (bio[v]) continue;
    ret += dfs(v);
  }
  return ret;
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    ans = max(ans, dfs(i));
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
