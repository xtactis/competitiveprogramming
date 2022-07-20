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

int n, m;
long long a[N], b[N], cum[N];
long long dp[N][2];

long long foo(long long x) {
  if (x >= b[m-1]) return x-b[m-1];
  if (x <= b[0]) return b[0]-x;
  int p = upper_bound(b, b+m, x)-b;
  return min(abs(b[p]-x), abs(b[p-1]-x));
}

long long rek(int pos, int t) {
  if (pos >= n) return !t*1e15;
  long long &ret = dp[pos][t];
  if (ret != -1) return ret;
  if (t) {
    return ret = a[pos+1]-a[pos]+rek(pos+2, 1);
  }
  ret = foo(a[pos])+rek(pos+1, 1);
  if (pos+2 < n) ret = min(ret, a[pos+2]-a[pos]+foo(a[pos+1])+rek(pos+3, 1));
  if (pos+1 < n) ret = min(ret, a[pos+1]-a[pos]+rek(pos+2, 0));
  return ret;
}
 
void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%lld", a+i);
  for (int i = 0; i < m; ++i) scanf("%lld", b+i);
  sort(a, a+n);
  sort(b, b+m);
  printf("%lld", rek(0, 0));
}

/*
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%lld", a+i);
  for (int i = 0; i < m; ++i) scanf("%lld", b+i);
  sort(a, a+n);
  sort(b, b+m);
  cum[1] = a[1]-a[0];
  for (int i = 2; i < n; ++i) {
    cum[i] = cum[i-2]+a[i]-a[i-1];
  }
  cum[n+1] = cum[n] = cum[n-1];
  long long ans = 1e18;
  for (int i = 0; i < n; ++i) {
    long long cur = foo(a[i]);
    if (i&1) {
      if (i-2 > 0) cur += cum[i-2];
      cur += cum[n]-cum[i+1];
      cur += a[i+1]-a[i-1];
    } else {
      if (i-1 > 0) cur += cum[i-1];
      cur += cum[n]-cum[i];
    }
    ans = min(ans, cur);
  }
  printf("%lld", ans);
}
*/

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
