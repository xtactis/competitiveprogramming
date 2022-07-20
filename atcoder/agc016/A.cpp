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

int h[255], m[255];

void solve() {
  for (int c = 'a'; c <= 'z'; ++c) h[c] = m[c] = -1;
  string s; cin >> s;
  int n = s.size(), ans = 1e9;
  for (int i = 0; i < n; ++i) {
    m[s[i]] = max(m[s[i]], i-h[s[i]]-1);
    h[s[i]] = i;
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    if (m[c] == -1) continue;
    ans = min(ans, max(m[c], n-1-h[c]));
  }
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
