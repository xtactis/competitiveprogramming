#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  string s; cin >> s;
  int ans = 0;
  for (int b = 0, e = s.size()-1; b < e;) {
    if (s[b] == s[e]) {
      ++b; --e;
    } else if (s[b] == 'x') {
      ++b; ++ans;
    } else if (s[e] == 'x') {
      --e; ++ans;
    } else {
      cout << -1;
      return;
    }
  }
  cout << ans;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
