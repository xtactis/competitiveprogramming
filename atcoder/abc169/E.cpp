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

int a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a+i, b+i);
  }
  sort(a, a+n);
  sort(b, b+n);
  int lo = a[n/2], hi = b[n/2];
  if (n%2 == 0) {
    lo = a[n/2]+a[n/2-1];
    hi = b[n/2]+b[n/2-1];
  }
  printf("%d", hi-lo+1);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
