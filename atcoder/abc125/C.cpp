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

int a[N], b[N], c[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (!i) {
      b[0] = a[0];
    } else {
      b[i] = __gcd(b[i-1], a[i]);
    }
  }
  c[n-1] = a[n-1];
  for (int i = n-2; i >= 0; --i) {
    c[i] = __gcd(c[i+1], a[i]);
  }
  int ans = c[1];
  for (int i = 1; i < n-1; ++i) {
    ans = max(ans, __gcd(b[i-1], c[i+1]));
  }
  ans = max(ans, b[n-2]);
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
