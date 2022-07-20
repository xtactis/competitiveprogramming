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
const long long inf = 1e15;

vector<pair<int, int>> g[N];
long long D[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int l, r, c; scanf("%d%d%d", &l, &r, &c);
    g[l-1].emplace_back(r-1, c);
  }
  for (int i = 1; i < n; ++i) {
    g[i].emplace_back(i-1, 0);
    D[i] = inf;
  }
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.emplace(0, 0);
  D[0] = 0;
  while (!pq.empty()) {
    long long d = pq.top().first, u = pq.top().second;
    pq.pop();
    if (d > D[u]) continue;
    for (const auto &p: g[u]) {
      if (D[p.first] <= D[u]+p.second) continue;
      pq.emplace(D[u]+p.second, p.first);
      D[p.first] = D[u]+p.second;
    }
  }
  if (D[n-1] == inf) D[n-1] = -1;
  printf("%lld", D[n-1]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
