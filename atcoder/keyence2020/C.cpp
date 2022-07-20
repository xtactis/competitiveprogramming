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
  int n, k, s; scanf("%d%d%d", &n, &k, &s);
  for (int i = 0; i < k; ++i) printf("%d ", s);
  for (int i = 0; i < n-k; ++i) {
    if (s == (int)1e9) printf("1 ");
    else printf("1000000000 ");
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
