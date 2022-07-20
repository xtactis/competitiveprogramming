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

int n;
vector<pair<int, int>> edges;
vector<int> g[N];
map<pair<int, int>, int> ec;

void bfs(int s) {
  queue<int> q;
  vector<bool> bio(n);
  q.push(s);
  bio[s] = 1;
  int c = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int v: g[u]) {
      if (bio[v]) continue;
      bio[v] = 1;
      q.push(v);
      ec[{u, v}] = ec[{v, u}] = c++;
    }
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
    edges.emplace_back(u, v);
  }
  size_t ms = 0, ind = -1;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() > ms) {
      ms = g[i].size();
      ind = i;
    }
  }
  bfs(ind);
  for (const auto &e: edges) {
    printf("%d\n", ec[e]);
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
