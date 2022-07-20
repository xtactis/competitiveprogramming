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

const int N = 1e4+23;

vector<int> g[N];
int c[N], bio[N];

void solve() {
  int n; scanf("%d", &n);
  int mo = 0;
  for (int u, v, i = 0; i < n-1; ++i) {
    scanf("%d %d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
    if (g[u].size() > g[mo].size()) mo = u;
    if (g[v].size() > g[mo].size()) mo = v;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", c+i);
  }
  sort(c, c+n, greater<int>());
  queue<int> q;
  q.push(mo);
  int ind = 0;
  bio[mo] = c[ind++];
  long long ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: g[u]) {
      if (bio[v]) continue;
      bio[v] = c[ind++];
      ans += min(bio[v], bio[u]);
      q.push(v);
    }
  }
  printf("%lld\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d ", bio[i]);
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
