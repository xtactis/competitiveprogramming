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
  int h1, m1, h2, m2, k; scanf("%d%d%d%d%d", &h1, &m1, &h2, &m2, &k);
  h1 = h1*60+m1;
  h2 = h2*60+m2;
  h2 -= k;
  printf("%d", max(h2-h1, 0));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
