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

const int N = 123;

int a[N], b[N], c[N], p[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  for (int i = 0; i < n; ++i) scanf("%d", b+i);
  for (int i = 0; i < n; ++i) scanf("%d", c+i);
  p[0] = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] != p[i-1] && p[(i+1)%n] != a[i]) {
      p[i] = a[i];
    } else if (b[i] != p[i-1] && p[(i+1)%n] != b[i]) {
      p[i] = b[i];
    } else {
      p[i] = c[i];
    }
  }
  for (int i = 0; i < n; ++i) printf("%d ", p[i]);
  puts("");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
