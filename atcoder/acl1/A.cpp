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
int a[N], ans[N], p[N];

void solve() {
  int n; scanf("%d", &n);
  for (int x, y, i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x] = y;
    p[x] = i;
  }
  reverse(a, a+n);
  reverse(p, p+n);
  int ma = -1, prev = 0;
  for (int i = 0; i < n; ++i) {
    ma = max(a[i], ma);
    if (ma != i) continue;
    int d = i-prev+1;
    debug(d);
    for (; prev <= i; ++prev) {
      ans[p[prev]] = d;
    }
  }
  for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
