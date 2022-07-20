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

map<int, int> mp;

void solve() {
  int n; scanf("%d", &n);
  for (int x, i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++mp[x];
  }
  int m; scanf("%d", &m);
  for (int t, i = 0; i < m; ++i) {
    scanf("%d", &t);
    if (mp[t] > 0) {
      --mp[t];
    } else {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
