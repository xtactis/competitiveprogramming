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

int a[N];

void solve() {
  int n, k, z; scanf("%d%d%d", &n, &k, &z);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (i <= k) ans += a[i];
  }
  int cur = ans, pmx = -1;
  for (; z && k > 2; --z) {
    int mx = 1;
    for (int j = 2; j <= k-2; ++j) {
      if (a[j]+a[j-1] > a[mx]+a[mx-1]) mx = j;
    }
    if (pmx != k) ans = max(ans, cur-a[k]+a[k-2]);
    cur = cur+a[mx]+a[mx-1]-a[k]-a[k-1];
    k -= 2;
    ans = max(ans, cur);
    pmx = mx;
  }
  if (k >= 2 && z && pmx != k) {
    ans = max(ans, cur-a[k]+a[k-2]);
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
