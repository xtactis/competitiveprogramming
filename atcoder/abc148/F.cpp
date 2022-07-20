#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

const int N = 1e5;
vector<int> g[N];
int n, a, b;
pair<int, int> distA[N], distB[N];

void bfs(int x, pair<int, int> dist[N]) {
  queue<pair<int, int>> q;
  dist[x] = make_pair(0, x);
  q.emplace(0, x);
  while (!q.empty()) {
    int d = q.front().first;
    int u = q.front().second;
    q.pop();
    for (int v: g[u]) {
      if (dist[v].first != -1) continue;
      if (x == a && v == b) continue;
      dist[v] = make_pair(d+1, v);
      q.emplace(d+1, v);
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  if (n == 2) return !printf("0");
  --a; --b;
  for (int i = 0; i < n-1; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) distA[i].first = distB[i].first = -1;
  bfs(a, distA);
  bfs(b, distB);
  sort(distB, distB+n, greater<pair<int, int>>());
  for (int i = 0; i < n; ++i) {
    int vert = distB[i].second;
    if (distA[vert].first == -1) continue;
    if (distB[i].first <= distA[vert].first) continue;
    printf("%d", distB[i].first-1);
    return 0;
  }
  return 0;
}
