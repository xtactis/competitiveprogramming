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

using ll = long long;

const int N = 1e5+23;
const ll inf = 1e15;

vector<pair<int, int>> S[N], Y[N];
long long costS[N], costY[N];
long long ans[N];

void solve() {
  int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
  --s, --t;
  for (int u, v, a, b, i = 0; i < m; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    Y[--u].emplace_back(--v, a);
    Y[v].emplace_back(u, a);
    S[u].emplace_back(v, b);
    S[v].emplace_back(u, b);
  }
  for (int i = 0; i < n; ++i) {
    costS[i] = costY[i] = inf;
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);
  costY[s] = 0;
  while (!pq.empty()) {
    ll d = pq.top().first, u = pq.top().second;
    pq.pop();
    if (d != costY[u]) continue;
    costY[u] = d;
    for (const auto &v: Y[u]) {
      if (costY[v.first] <= d+v.second) continue;
      costY[v.first] = d+v.second;
      pq.emplace(d+v.second, v.first);
    }
  }
  pq.emplace(0, t);
  costS[t] = 0;
  while (!pq.empty()) {
    ll d = pq.top().first, u = pq.top().second;
    pq.pop();
    if (costS[u] != d) continue;
    costS[u] = d;
    for (const auto &v: S[u]) {
      if (costS[v.first] <= d+v.second) continue;
      costS[v.first] = d+v.second;
      pq.emplace(d+v.second, v.first);
    }
  }
  ans[n] = inf;
  for (int i = n-1; i >= 0; --i) {
    ans[i] = min(ans[i+1], costY[i]+costS[i]);
  }
  for (int i = 0; i < n; ++i) printf("%lld\n", inf-ans[i]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
