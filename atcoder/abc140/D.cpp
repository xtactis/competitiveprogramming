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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0, count = 1, seps = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) ++count;
    else {
      ans += count-1;
      ++seps;
      count = 1;
    }
  }
  ans += count-1;
  ++seps;
  if ((seps-2)/2 >= k) {
    ans += k*2;
  } else {
    ans = n-1;
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
