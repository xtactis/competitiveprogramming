#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;


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
  int n, q; scanf("%d%d", &n, &q);
  fenwick_tree<long long> fw(n);
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    fw.add(i, a);
  }
  while (q--) {
    int t, u, v; scanf("%d%d%d", &t, &u, &v);
    if (t) {
      printf("%lld\n", fw.sum(u, v));
    } else {
      fw.add(u, v);
    }
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
