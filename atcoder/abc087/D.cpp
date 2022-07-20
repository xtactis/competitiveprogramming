#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

const int N = 1e5+34;
const int M = 2e5+34;

int a[N];
vector<pair<int, int>> g[N];

bool bio[N];
bool dfs(int u, int c) {
  a[u] = c;
  bio[u] = true;
  bool ret = false;
  for (const auto &e: g[u]) {
    if (bio[e.first]) {
      if (a[e.first]-a[u] != e.second) return true;
      continue;
    }
    ret |= dfs(e.first, c+e.second);
  }
  return ret;
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int l, r, d; scanf("%d%d%d", &l, &r, &d);
    g[--l].emplace_back(--r, d);
    g[r].emplace_back(l, -d);
  }
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    if (dfs(i, 0)) {
      printf("No");
      return;
    }
  }
  printf("Yes");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
