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

long long x[N], v[N];
long long f[N], g[N];

void solve() {
  int n;
  long long c;
  scanf("%d%lld", &n, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", x+i, v+i);
    f[i] = v[i]-x[i];
    g[i] = i;
    if (i) {
      f[i] = f[i]+f[i-1]+x[i-1];
      if (f[g[i-1]] > f[i]) g[i] = g[i-1];
    }
  }
  long long ans = 0;
  ans = max(ans, f[g[n-1]]);
  long long cum = 0;
  for (int i = n-1; i > 0; --i) {
    ans = max(ans, v[i]+cum-2*(c-x[i])+f[g[i-1]]);
    cum += v[i];
  }
  ans = max(ans, cum-2*(c-x[0]));
  reverse(x, x+n);
  reverse(v, v+n);
  for (int i = 0; i < n; ++i) {
    x[i] = c-x[i];
    f[i] = v[i]-x[i];
    g[i] = i;
    if (i) {
      f[i] = f[i]+f[i-1]+x[i-1];
      if (f[g[i-1]] > f[i]) g[i] = g[i-1];
    }
  }
  ans = max(ans, f[g[n-1]]);
  cum = 0;
  for (int i = n-1; i > 0; --i) {
    ans = max(ans, v[i]+cum-2*(c-x[i])+f[g[i-1]]);
    cum += v[i];
  }
  ans = max(ans, cum-2*(c-x[0]));
  
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
