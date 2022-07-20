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
  set<int> s;
  for (int a, i = 0; i < n; ++i) {scanf("%d", &a); s.insert(a);}
  printf("%d\n", s.size());
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
