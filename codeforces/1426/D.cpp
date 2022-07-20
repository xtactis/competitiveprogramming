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
  int n; scanf("%d", &n);
  long long cum = 0;
  set<long long> s;
  s.insert(0);
  int ans = 0;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    cum += a;
    if (s.count(cum)) {
      cum -= a;
      cum += (long long)1e15;
      ++ans;
      s.insert(cum);
      cum += a;
    }
    s.insert(cum);
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
