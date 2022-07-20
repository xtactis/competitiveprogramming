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

const int N = 3000;

void solve() {
  int r, g, b, n; scanf("%d%d%d%d", &r, &g, &b, &n);
  int ans = 0;
  for (int i = 0; i <= N; ++i) {
    if (i*r > n) break;
    for (int j = 0; j <= N; ++j) {
      if (i*r+j*g > n) break;
      if ((n-i*r-j*g)%b) continue;
      ++ans;
    }
  }
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
