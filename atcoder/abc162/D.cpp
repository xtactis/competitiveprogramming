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

vector<int> r, g, b;

void solve() {
  int n; string s; cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') r.push_back(i);
    else if (s[i] == 'G') g.push_back(i);
    else b.push_back(i);
  }
  long long ans = 0;
  for (int i: r) {
    for (int j: g) {
      ans += b.size();
      int x[2] = {i, j};
      sort(x, x+2);
      auto y = lower_bound(b.begin(), b.end(), 2*x[1]-x[0]);
      if (y != b.end() && *y == 2*x[1]-x[0]) --ans;
      y = lower_bound(b.begin(), b.end(), (x[0]+x[1])/2);
      if (y != b.end()) {
        int z = *y;
        if (z-x[0] == x[1]-z) --ans;
      }
      y = lower_bound(b.begin(), b.end(), x[0]-(x[1]-x[0]));
      if (y != b.end() && *y == x[0]-(x[1]-x[0])) --ans;
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
