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

const int N = 2e5+23;

string s;
int ans;

void ch(int i) {
  if (s[i] == 'L') s[i] = 'R';
  else s[i] = 'L';
  ++ans;
}

void solve() {
  int n; cin >> n >> s;
  ans = 0;
  for (int i = 0; i < 2*n; ++i) {
    if (s[i%n] == 'R' && s[(i+1)%n] == 'R' && s[(i-1+n)%n] == 'R') ch(i%n);
    if (s[i%n] == 'L' && s[(i+1)%n] == 'L' && s[(i-1+n)%n] == 'L') ch(i%n);
  }
  cout << ans << "\n";
}

int main() {
  init();
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
