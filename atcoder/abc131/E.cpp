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
  int n, k; scanf("%d%d", &n, &k);
  vector<pair<int, int>> v;
  for (int i = 1; i < n; ++i) {
    v.emplace_back(n, i);
  }
  int m = (n-1)*(n-2)/2;
  if (k > m) {
    printf("-1");
    return;
  }
  for (int i = 1; i < n-1; ++i) {
    for (int j = i+1; j <= n-1; ++j) {
      if (m == k) goto done;
      v.emplace_back(i, j);
      --m;
    }
  }
 done:
  printf("%d\n", (int)v.size());
  for (const auto &e: v) printf("%d %d\n", e.first, e.second);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
