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

const int N = 1e3+23;

int a[N], c[N];
int dp[N][(1<<12)+23];
int n, m;

int rek(int pos, int mask) {
  if (pos == m) {
    return (mask != (1 << n)-1) * 1e9;
  }
  int &ret = dp[pos][mask];
  if (ret != -1) return ret;
  ret = rek(pos+1, mask);
  return ret = min(ret, a[pos] + rek(pos+1, mask | c[pos]));
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &m);
  for (int b, i = 0; i < m; ++i) {
    scanf("%d%d", a+i, &b);
    for (int x; b--;) {
      scanf("%d", &x);
      c[i] |= 1 << (x-1);
    }
  }
  int ans = rek(0, 0);
  if (ans >= 1e9) printf("-1");
  else printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
