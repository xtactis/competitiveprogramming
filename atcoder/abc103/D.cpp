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

int h[N];
pair<int, int> a[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i].second, &a[i].first);
    ++h[a[i].second];
  }
  for (int i = 1; i <= n; ++i) {
    h[i] += h[i-1];
  }
  sort(a, a+m);
  int prev = 0, ans = 0;
  for (int i = 0; i < m; ++i) {
    if (h[a[i].first-1] == h[prev]) continue;
    if (a[i].second <= prev) continue;
    ++ans;
    prev = a[i].first-1;
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
