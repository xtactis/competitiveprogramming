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
  map<string, int> m;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    sort(s.begin(), s.end());
    ++m[s];
  }
  long long ans = 0;
  for (const auto &e: m) {
    ans += 1LL*e.second*(e.second-1)/2;
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
