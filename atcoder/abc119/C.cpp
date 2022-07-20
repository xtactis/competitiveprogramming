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

const int N = 10;

int l[N];

void solve() {
  int n, a, b, c; scanf("%d%d%d%d", &n, &a, &b, &c);
  for (int i = 0; i < n; ++i) scanf("%d", l+i);
  int ans = 1e9;
  for (int i = 0, lmt = 1 << (n*2); i < lmt; ++i) {
    int h[4] = {0};
    int z[4] = {0};
    int cur = 0;
    for (int p, x = i, j = 0; j < n; ++j, x /= 4) {
      p = x%4;
      ++h[p];
      if (p == 3) continue;
      cur += 10;
      z[p] += l[j];
    }
    if (!h[0] || !h[1] || !h[2]) continue;
    ans = min(ans, cur+abs(a-z[0])+abs(b-z[1])+abs(c-z[2])-30);
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
