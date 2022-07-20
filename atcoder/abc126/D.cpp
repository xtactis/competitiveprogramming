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

vector<pair<int, int>> g[N];
int bio[N];

void dfs(int u, int c) {
  bio[u] = c;
  for (const auto &p: g[u]) {
    if (bio[p.first]) continue;
    if (p.second) dfs(p.first, 1+!(c-1));
    else dfs(p.first, c);
  }
}

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0, u, v, w; i < n-1; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    g[u-1].emplace_back(v-1, w%2);
    g[v-1].emplace_back(u-1, w%2);
  }
  dfs(0, 1);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", bio[i]-1);
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
