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

const int N = 512;

vector<int> v[N];

void solve() {
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  for (int l, r, i = 0; i < m; ++i) {
    scanf("%d%d", &l, &r);
    v[l].push_back(r);
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i].empty()) continue;
    sort(v[i].begin(), v[i].end());
  }
  for (int l, r, i = 0; i < q; ++i) {
    scanf("%d %d", &l, &r);
    int ans = 0;
    for (; l <= r; ++l) {
      if (v[l].empty()) continue;
      ans += upper_bound(v[l].begin(), v[l].end(), r) - v[l].begin();
    }
    printf("%d\n", ans);
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
