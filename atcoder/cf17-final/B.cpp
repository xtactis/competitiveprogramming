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
  int h[3] = {}, n = s.size();
  for (int i = 0; i < n; ++i) {
    ++h[s[i]-'a'];
  }
  sort(h, h+3, greater<int>());
  h[0] -= h[2];
  h[1] -= h[2];
  h[2] = 0;
  if (h[0] > 1) cout << "NO";
  else cout << "YES";
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
