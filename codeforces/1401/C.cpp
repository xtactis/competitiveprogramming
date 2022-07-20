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

int a[N], b[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(b, b+n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    if (__gcd(a[i], b[0]) != b[0]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
