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
  string s; int k;
  cin >> s >> k;
  for (char &c: s) {
    if ('z'+1-c > k) continue;
    if (c == 'a') continue;
    k -= 'z'+1-c;
    c = 'a';
  }
  k %= 26;
  s.back() += k;
  if (s.back() > 'z') s.back() -= 26;
  cout << s;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
