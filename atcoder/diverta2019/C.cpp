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
  int n; cin >> n;
  int ans = 0;
  int a = 0, b = 0, ba = 0;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < (int)s.size(); ++j) {
      if (s[j] == 'A' && s[j+1] == 'B') ++ans;
    }
    if (s[0] == 'B' && s.back() == 'A') ++ba;
    else if (s[0] == 'B') ++b;
    else if (s.back() == 'A') ++a;
  }
  ans += max(ba-1, 0);
  if (ba && a) {
    --a;
    ++ans;
  }
  if (ba && b) {
    --b;
    ++ans;
  }
  ans += max(min(a, b), 0);
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
