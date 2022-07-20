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

int a[N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += (k-a[i])/a[0];
  }
  printf("%d\n", ans);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
