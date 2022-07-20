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

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  int ans = -1;
  for (int i = 1; i*i <= m; ++i) {
    if (m%i) continue;
    if (m/i >= n) ans = max(ans, i);
    if (i >= n) ans = max(ans, m/i);
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
