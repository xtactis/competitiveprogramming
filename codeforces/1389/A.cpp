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
  int l, r; scanf("%d%d", &l, &r);
  if (l*2 > r) {
    printf("-1 -1\n");
    return;
  }
  printf("%d %d\n", l, l*2);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
