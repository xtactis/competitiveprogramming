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
  for (int i = 0; i < (int)s.size(); i+=2) {
    cout << s[i];
  }
  cout << s.back() << '\n';
}

int main() {
  init();
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
