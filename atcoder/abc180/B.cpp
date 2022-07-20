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
  int n; scanf("%d", &n);
  long long m = 0, e = 0, c = -1;
  for (long long x, i = 0; i < n; ++i) {
    scanf("%lld", &x);
    m += abs(x);
    e += x*x;
    c = max(c, abs(x));
  }
  printf("%lld %.9lf %lld", m, sqrt(e), c);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
