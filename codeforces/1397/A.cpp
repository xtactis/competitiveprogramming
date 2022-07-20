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

int h[30];

void solve() {
  int n; cin >> n;
  string s;
  for (int i = 0; i < 30; ++i) h[i] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (char e: s) {
      ++h[e-'a'];
    }
  }
  for (int i = 0; i < 30; ++i) {
    if (h[i]%n) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  init();
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
