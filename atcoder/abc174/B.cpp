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

void solve() {
  int n, d; scanf("%d%d", &n, &d);
  int ans = 0;
  for (long long x, y, i = 0; i < n; ++i) {
    scanf("%lld%lld", &x, &y);
    if (sqrt(x*x+y*y) <= d) ++ans;
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
