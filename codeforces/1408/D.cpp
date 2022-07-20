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

const int N = 2e3+23;
const int M = 1e6+23;

int a[N], b[N], c[N], d[N];
int dist[M];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a+i, b+i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", c+i, d+i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] > c[j]) continue;
      dist[c[j]-a[i]] = max(dist[c[j]-a[i]], d[j]-b[i]+1);
    }
  }
  int ans = M, mx = 0;
  for (int i = M-1; i >= 0; --i) {
    mx = max(mx, dist[i]);
    ans = min(ans, i+mx);
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
