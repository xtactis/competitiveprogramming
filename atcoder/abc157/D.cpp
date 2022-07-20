#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

const int N = 1e5+34;

vector<int> g[N], q[N];

int bio[N], group[N];
void dfs(int u, int c) {
  bio[u] = c;
  ++group[c];
  for (int v: g[u]) {
    if (bio[v]) {
      continue;
    }
    dfs(v, c);
  }
}

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

void solve() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }
  for (int i = 0; i < k; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    q[u-1].push_back(v-1);
    q[v-1].push_back(u-1);
  }
  int c = 1;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    dfs(i, c++);
  }
  for (int i = 0; i < n; ++i) {
    int ans = group[bio[i]]-1;
    ans -= g[i].size();
    for (int v: q[i]) {
      if (bio[v] == bio[i]) --ans;
    }
    printf("%d ", ans);
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
