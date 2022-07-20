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
  int x, y; scanf("%d%d", &x, &y);
  if (x > 3) x = 4;
  if (y > 3) y = 4;
  x = 100000*(4-x);
  y = 100000*(4-y);
  int ans = x+y;
  if (ans == 600000) ans += 400000;
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
