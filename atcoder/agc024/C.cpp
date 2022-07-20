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
  int a, p; long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a > i) {
      puts("-1");
      return;
    }
    if (i && a-p > 1) {
      puts("-1");
      return;
    }
    if (i && a <= p) ans += p;
    p = a;
  }
  ans += p;
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
