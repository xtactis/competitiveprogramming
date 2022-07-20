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
  for (int i = 1; i <= n; ++i) {
    char c; scanf(" %c", &c);
    a[i] = c == '#';
    b[i] = !a[i];
    a[i] += a[i-1];
  }
  int ans = 1e9;
  for (int i = n; i > 0; --i) {
    b[i] += b[i+1];
    ans = min(ans, a[i-1]+b[i]);
  }
  printf("%d", min(ans, a[n]));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
