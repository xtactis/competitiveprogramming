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

int bio[N][3];
vector<int> g[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
  }
  int s, t; scanf("%d%d", &s, &t);
  --s, --t;
  queue<pair<int, int>> qq;
  qq.emplace(s, 0);
  bio[s][0] = 1;
  while (qq.size()) {
    int u = qq.front().first, d = qq.front().second; qq.pop();
    if (u == t && d % 3 == 0) {
      printf("%d", d/3);
      return;
    }
    int x = (d+1)%3;
    for (int v: g[u]) {
      if (bio[v][x]) continue;
      qq.emplace(v, d+1);
      bio[v][x] = 1;
    }
  }
  printf("-1");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
