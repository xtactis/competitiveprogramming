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
  long long x, y, k; scanf("%lld%lld%lld", &x, &y, &k);
  printf("%lld\n", (k+k*y-1+x-2)/(x-1)+k);
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
