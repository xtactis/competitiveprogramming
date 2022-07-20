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

const int N = 2e5+23;

int a[N], l[N], h[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    a[i] = c-'0';
  }
  int dist = 0, first = false;
  for (int i = 0; i < n; ++i) {
    l[i] = 1e9;
    if (!first && !a[i]) continue;
    if (a[i]) {
      first = true;
      l[i] = dist = 0;
    } else {
      l[i] = ++dist;
    }
  }
  dist = 0; first = false;
  for (int i = n-1; i >= 0; --i) {
    h[i] = 1e9;
    if (!first && !a[i]) continue;
    if (a[i]) {
      first = true;
      h[i] = dist = 0;
    } else {
      h[i] = ++dist;
    }
  }
  int ans = 0;
  const int inf = 1e9;
  dist = inf;
  for (int i = 0; i < n; ++i) {
    if (l[i] == 0) dist = inf;
    if (dist != inf) {
      l[i] = ++dist;
    }
    if (min(l[i], h[i]) > k) {
      ++ans;
      l[i] = 0;
      dist = 0;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
