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
  long long ans = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      ans += n-i-1;
      ans += i*2;
    } else {
      ans += i;
      ans += (n-i-1)*2;
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
