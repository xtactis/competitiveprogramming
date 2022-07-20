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
  int n, x; scanf("%d%d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    a[i] = a[i]-x;
  }
  int g = a[0];
  for (int i = 1; i < n; ++i) {
    g = __gcd(g, a[i]);
  }
  printf("%d", abs(g));
}

/*
33 105 57
48 24 24

 */

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
