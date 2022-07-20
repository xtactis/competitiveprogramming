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
vector<int> g[N];
int maxs[N];
map<int, int> counts[N];
int n, ind[N];

int dfs(int u, int p = -1) {
  int ret = 1;
  for (const auto &v: g[u]) {
    if (v == p) continue;
    int t = dfs(v, u);
    counts[u][v] = t;
    ret += t;
    maxs[u] = max(maxs[u], t);
  }
  if (n-ret) {
    counts[u][p] = n-ret;
    maxs[u] = max(maxs[u], n-ret);
  }
  return ret;
}

bool dfs2(int u, int v, int o, int p = -1) {
  if (u == v) {
    for (const auto &x: g[u]) {
      if (x == p) continue;
      if (x == o) continue;
      if (counts[o][x]) continue;
      printf("%d %d\n%d %d\n", u+1, x+1, o+1, x+1);
      return true;
    }
  }
  if (u == o) {
    for (const auto &x: g[u]) {
      if (maxs[u] != counts[u][x]) continue;
      return dfs2(x, v, o, u);
    }
  } else {
    for (const auto &x: g[u]) {
      if (x == p) continue;
      if (dfs2(x, v, o, u)) return true;
    }
  }
  return false;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    counts[i].clear();
    g[i].clear();
    maxs[i] = 0;
    ind[i] = i;
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v; scanf("%d %d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  dfs(0);
  sort(ind, ind+n, [](int x, int y){return maxs[x] < maxs[y];});
  for (int i = 1; i < n; ++i) {
    int u = ind[i], v = ind[i-1];
    
    if (maxs[u] > n/2 || maxs[v] > n/2) continue;
    assert(dfs2(u, v, u));
    return;
  }
  printf("%d %d\n%d %d\n", 1, g[0][0]+1, 1, g[0][0]+1);
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
