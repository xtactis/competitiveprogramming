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
  int n, m; scanf("%d%d", &n, &m);
  if (n >= m) {
    puts("0");
    return;
  }
  for (int i = 0; i < m; ++i) scanf("%d", a+i);
  sort(a, a+m);
  long long lo = -1, hi = a[n-1]-a[0]+1;
  long long ans = 0;
  while (lo+1 < hi) {
    long long mid = (lo+hi)/2;
    long long cur = 0;
    int c = 0;
    ans = 0;
    for (int i = 1; i < m; ++i) {
      if (cur+a[i]-a[i-1] > mid) {
	++c;
	ans += cur;
	cur = 0;
      } else cur += a[i]-a[i-1];
    }
    if (c > n) lo = mid;
    else hi = mid;
  }
  debug(hi);
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
