#include <bits/stdc++.h>
using namespace std;

int a[12][12];
int cost[12];

int main() {
  int n, m, x; scanf("%d %d %d", &n, &m, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cost[i]);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int ans = -1;
  for (int i = 1; i < (1<<n); ++i) {
    vector<int> c(m); int cur = 0;
    for (int j = 0; j < n; ++j) {
      if (((i>>j)&1) == 0) continue;
      cur += cost[j];
      for (int k = 0; k < m; ++k) {
	c[k] += a[j][k];
      }
    }
    if (all_of(c.begin(), c.end(), [x](int z){return z >= x;})) {
      if (ans == -1) ans = cur;
      else ans = min(cur, ans);
    }
  }
  printf("%d", ans);
  return 0;
}
