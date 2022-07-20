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

const int N = 321;

int a[N][N], p[N], h[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  int ans = 2e9;
  set<int> s;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      ++h[a[j][p[j]]];
    }
    int hi = max_element(h, h+m+1)-h;
    s.insert(hi);
    ans = min(ans, h[hi]);
    for (int j = 0; j < n; ++j) {
      while (s.count(a[j][p[j]])) ++p[j];
    }
    for (int j = 0; j <= m; ++j) h[j] = 0;
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
