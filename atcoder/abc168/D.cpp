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

const int N = 1e5+34;
int bio[N];
vector<int> g[N];

void bfs(int p) {
  queue<int> q;
  q.push(p);
  bio[p] = 69;
  while (!q.empty()) {
    int p = q.front(); q.pop();
    for (int v: g[p]) {
      if (bio[v]) continue;
      q.push(v);
      bio[v] = p;
    }
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(1);
  for (int i = 1; i <= n; ++i) {
    if (!bio[i]) {
      puts("No");
      return;
    }
  }
  puts("Yes");
  for (int i = 2; i <= n; ++i) {
    printf("%d\n", bio[i]);
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
