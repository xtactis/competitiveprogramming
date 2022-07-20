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

int n, a[N], dp[N][2];

int rek(int pos, int frend) {
  if (pos >= n) return 0;
  int &ret = dp[pos][frend];
  if (ret != -1) return ret;
  if (frend) {
    ret = a[pos]+rek(pos+1, 0);
    if (pos+1 < n)
      ret = min(ret, a[pos]+a[pos+1]+rek(pos+2, 0));
  } else {
    ret = min(rek(pos+1, 1), rek(pos+2, 1));
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  printf("%d\n", rek(0, 1));
}

int main() {
  init();
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
