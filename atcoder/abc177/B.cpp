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
  string s, t; cin >> s >> t;
  int ans = s.size();
  for (int i = 0; i < (int)(s.size()-t.size()+1); ++i) {
    int cur = 0;
    for (int j = 0; j < (int)t.size(); ++j) {
      if (s[i+j] != t[j]) ++cur;
    }
    ans = min(ans, cur);
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
