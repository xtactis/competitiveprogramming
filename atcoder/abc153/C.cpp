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
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n-k; ++i) {
    ans += a[i];
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
