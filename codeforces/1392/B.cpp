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

void solve() {
  long long n, k; scanf("%lld%lld", &n, &k);
  int m = -2e9;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    m = max(a[i], m);
  }
  k %= 2;
  k += 2;
  while (k--) {
    int newm = -2e9;
    for (int i = 0; i < n; ++i) {
      a[i] = m-a[i];
      newm = max(newm, a[i]);
    }
    m = newm;
  }
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
