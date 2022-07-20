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
int a[N];
int n;

long long check(long long p) {
  for (int i = 0; i < n; ++i) {
    p = p/a[i]*a[i];
    if (p < a[i]);
  }
  return p;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  long long lo = 1, hi = 1e16;
  while (lo+1 < hi) {
    long long mid = lo+(hi-lo)/2;
    if (check(mid) >= 2) hi = mid;
    else lo = mid;
  }
  if (check(hi) != 2) {
    printf("-1");
    return;
  }
  printf("%lld ", hi);
  lo = hi-1; hi = 1e16;
  while (lo+1 < hi) {
    long long mid = lo+(hi-lo)/2;
    if (check(mid) > 2) hi = mid;
    else lo = mid;
  }
  printf("%lld", lo);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
