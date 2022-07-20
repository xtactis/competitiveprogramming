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

vector<pair<int, int>> v[N];
pair<int, int> ans[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int p, y, i = 0; i < m; ++i) {
    scanf("%d%d", &p, &y);
    v[--p].emplace_back(y, i);
  }
  for (int i = 0; i < n; ++i) {
    sort(v[i].begin(), v[i].end());
    for (int j = 1; j <= (int)v[i].size(); ++j) {
      ans[v[i][j-1].second] = {i+1, j};
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%06d%06d\n", ans[i].first, ans[i].second);
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
