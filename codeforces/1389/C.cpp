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
  int n = s.size();
  int h[10] = {};
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
    ++h[s[i]];
  }
  int a[10][10] = {{}};
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      if (i == j) continue;
      int l = i;
      for (int k = 0; k < n; ++k) {
	if (s[k] == l) {
	  ++a[i][j];
	  l = (l==i?j:i);
	}
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      ans = max(ans, a[i][j]/2);
    }
  }
  cout << n-max(ans*2, *max_element(h, h+10)) << "\n";
}

int main() {
  init();
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
