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
  long long n; scanf("%lld", &n);
  string s;
  while (n) {
    --n;
    s.push_back(n%26+'a');
    n /= 26;
  }
  reverse(s.begin(), s.end());
  printf("%s", s.c_str());
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
