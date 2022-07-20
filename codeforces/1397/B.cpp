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

long long a[N];

void solve() {
  int n; scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    ans += a[i]-1;
  }
  sort(a, a+n);
  for (int i = 2; i < 32000; ++i) {
    long long cur = 0, c = 1;
    bool f = true;
    for (int j = 0; j < n; ++j) {
      cur += abs(a[j] - c);
      c *= i;
      if (c > a[i]*2) {
	f = false;
	break;
      }
    }
    if (f) ans = min(ans, cur);
  }
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
