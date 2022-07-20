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

long long x[N], y[N], z[N];
int ind[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    ind[i] = i;
    scanf("%lld%lld%lld", x+i, y+i, z+i);
  }
  long long ans = 0;
  for (int i = 0; i < 8; ++i) {
    sort(ind, ind+n, [i](int a, int b) {
      int f = 1, s = 1, t = 1;
      if (i&1) f = -1;
      if (i&2) s = -1;
      if (i&4) t = -1;
      return f*x[a]+s*y[a]+t*z[a] > f*x[b]+s*y[b]+t*z[b];
    });
    long long b = 0, t = 0, p = 0;
    for (int j = n-1; j >= n-m; --j) {
      b += x[ind[j]]; t += y[ind[j]]; p += z[ind[j]];
    }
    ans = max(ans, abs(b)+abs(t)+abs(p));
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
