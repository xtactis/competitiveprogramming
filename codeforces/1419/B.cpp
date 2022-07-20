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
  long long n; scanf("%lld", &n);
  int ans = 0;
  long long cur = 0, cnt = 1;
  while (n) {
    cur += cnt;
    cnt *= 2;
    long long s = (1+cur)*cur/2;
    if (n >= s) {
      ++ans;
      n -= s;
    } else {
      break;
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
