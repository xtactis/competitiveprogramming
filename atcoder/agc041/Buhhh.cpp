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
  int n, m, v, p; scanf("%d %d %d %d", &n, &m, &v, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  sort(a, a+n, greater<long long>());
  for (int j = 0; j < p-1 && v > 1; ++j) {
    a[j] += m;
    --v;
  }
  int hi = upper_bound(a, a+n, a[p-1], greater<long long>())-a;
  int ans = hi;
  long long s = 0;
  for (int i = p-1; i < hi; ++i) s += a[i];
  for (int i = hi; i < n; ++i) {
    long long x = a[i]+m;
    long long c = max(v-(n-i), 0);
    if (x < a[p-1]) break;
    if (a[i] != a[i-1] && c*m > x*(i-(p-1))-s) break;
    ++ans;
    s += a[i];
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
