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
map<pair<int, int>, int> edges;
vector<pair<int, int>> actualEdges;
int mama = -1;

void dfs(int u, int p = -1) {
  set<int> s;
  for (int i = 0; i < g[u].size(); ++i) {
    s.insert(i);
    mama = max(mama, i);
  }
  for (auto &pa: g[u]) {
    pa.second = edges[make_pair(u, pa.first)];
    s.erase(pa.second);
  }
  for (auto &pa: g[u]) {
    if (pa.first == p) continue;
    pa.second = *s.begin();
    s.erase(pa.second);
    edges[make_pair(pa.first, u)] = edges[make_pair(u, pa.first)] = pa.second;
    dfs(pa.first, u);
  }
}

void solve() {
  int n; scanf("%d", &n);
  for (int u, v, i = 0; i < n-1; ++i) {
    scanf("%d%d", &u, &v);
    g[--u].emplace_back(--v, n);
    g[v].emplace_back(u, n);
    edges[make_pair(v, u)] = edges[make_pair(u, v)] = n;
    actualEdges.emplace_back(u, v);
  }
  dfs(0);
  printf("%d\n", mama+1);
  for (const auto &e: actualEdges) {
    printf("%d\n", edges[e]+1);
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
