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

const int N = 2e5+234;

vector<int> g[N];
int c[N];
bool bio[N];

void dfs(int u, int x=0) {
  bio[u] = true;
  c[u] += x;
  for (int v: g[u]) {
    if (bio[v]) continue;
    dfs(v, c[u]);
  }
}

void solve() {
  int n, q; scanf("%d%d", &n, &q);
  for (int i = 0; i < n-1; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  for (int i = 0; i < q; ++i) {
    int p, x; scanf("%d%d", &p, &x);
    c[--p] += x;
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    printf("%d ", c[i]);
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
