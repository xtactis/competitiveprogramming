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

vector<int> g[N], l[N];

bool bio[N];

void dfs(int u) {
  bio[u] = 1;
  for (int v: g[u]) {
    if (bio[v]) continue;
    dfs(v);
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int k; scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int x; scanf("%d", &x);
      l[--x].push_back(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < (int)l[i].size(); ++j) {
      g[l[i][j]].push_back(l[i][j-1]);
      g[l[i][j-1]].push_back(l[i][j]);
    }
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    if (!bio[i]) {
      printf("NO");
      return;
    }
  }
  printf("YES");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
