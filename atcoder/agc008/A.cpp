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
  int ans = 0;
  if (x == y) ans = 0;
  else if (x == 0) {
    if (y < 0) ans = -y+1;
    else ans = y;
  } else if (y == 0) {
    if (x < 0) ans = -x;
    else ans = 1+x;
  } else if (x > 0 && y > 0) {
    if (y > x) {
      ans = y-x;
    } else {
      ans = 2+abs(y-x);
    }
  } else if (x > 0) {
    ans = 1+abs(-y-x);
  } else if (y > 0) {
    ans = y-x;
    ans = min(ans, 1+abs(y+x));
  } else {
    ans = y-x;
    if (x > y) {
      ans = 2+abs(x-y);
    }
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
