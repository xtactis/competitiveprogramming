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
  string s; cin >> s;
  int n = s.size();
  if (s > "atcoder") {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] > 'a') {
      cout << i-(s[i] > 't') << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main() {
  init();
  int t = 1; cin >> t; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
