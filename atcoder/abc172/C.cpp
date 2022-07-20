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
long long a[N], b[N];

void solve() {
  long long n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    if (i) a[i] += a[i-1];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lld", b+i);
    if(i) b[i] += b[i-1];
  }
  int ans = upper_bound(b, b+m, k)-b;
  for (int i = 0; i < n; ++i) {
    if (a[i] > k) break;
    int bbooks = upper_bound(b, b+m, k-a[i])-b;
    ans = max(ans, (i+1) + bbooks);
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
