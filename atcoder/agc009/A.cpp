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

int a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a+i, b+i);
  }
  long long ans = 0, cur = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i]+cur == 0) continue;
    if (a[i]+cur < b[i]) {
      long long x = b[i]-a[i]-cur;
      cur += x;
      ans += x;
    } else {
      long long x = (a[i]+cur+b[i]-1)/b[i];
      ans += x*b[i]-(a[i]+cur);
      cur += x*b[i]-(a[i]+cur);
    }
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
