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

long long lcm(long long a, long long b) {
  return a/__gcd(a, b)*b;
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  long long l = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    l = lcm(l, a[i]/2);
  }
  for (int i = 0; i < n; ++i) {
    if (l*2/a[i]%2 == 0) {
      debug(a[i]);
      puts("0");
      return;
    }
  }
  long long ans = (m+l)/(2*l);
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
