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

int n;

bool check(int x, bool print=false) {
  int cur = 0;
  for (int i = x; i >= 0 && cur < n; --i) {
    if (cur+i <= n) {
      if (print) printf("%d\n", i);
      cur += i;
    }
  }
  return cur == n;
}

void solve() {
  scanf("%d", &n);
  int lo = 0, hi = n+1;
  while (lo+1 < hi) {
    int mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  check(hi, true);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
