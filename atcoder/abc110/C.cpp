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

char p[256], q[256];

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (p[t[i]] && p[t[i]] != s[i]) {
      puts("No");
      return;
    }
    p[t[i]] = s[i];
    if (q[s[i]] && q[s[i]] != t[i]) {
      puts("No");
      return;
    }
    q[s[i]] = t[i];
  }
  puts("Yes");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
