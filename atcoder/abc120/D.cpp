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

vector<pair<int, int>> e;
int parent[N], Size[N];

int findParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = findParent(parent[x]);
}

long long unionize(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  long long ret = 0;
  if (a != b) {
    if (Size[a] < Size[b]) swap(a, b);
    parent[b] = parent[a];
    ret = 1LL * Size[a] * Size[b];
    Size[a] += Size[b];
  }
  return ret;
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    Size[i] = 1;
  }
  for (int u, v, i = 0; i < m; ++i) {
    scanf("%d %d", &u, &v);
    e.emplace_back(u-1, v-1);
  }
  long long ma = 1LL*n*(n-1)/2;
  vector<long long> ans;
  for (int i = m-1; i >= 0; --i) {
    ans.push_back(ma);
    ma -= unionize(e[i].first, e[i].second);
  }
  for (int i = ans.size()-1; i >= 0; --i) {
    printf("%lld\n", ans[i]);
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
