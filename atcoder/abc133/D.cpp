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
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a+i);
    if (i%2) {
      a[i] += a[i-1];
    } else {
      a[i] = a[i-1] - a[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i%2) {
      printf("%lld ", a[n]-2*a[i-1]);
    } else {
      printf("%lld ", 2*a[i-1]-a[n]);
    }
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
