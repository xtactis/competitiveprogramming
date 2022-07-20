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
  long long ans = 0;
  for (int i = 0, count = 0; i < (int)s.size()-1; ++i) {
    if (s[i] == 'A') {
      ++count;
      continue;
    }
    if (s[i] == 'B' && s[i+1] == 'C') {
      ans += count;
      ++i;
    } else {
      count = 0;
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
