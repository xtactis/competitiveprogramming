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

const int N = 54;

long long x[N], y[N];
set<pair<long long, long long>> s;

void solve() {
  int n; scanf("%d", &n);
  if (n == 1) {
    printf("1");
    return;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", x+i, y+i);
    s.emplace(x[i], y[i]);
  }
  int ans = 1e9;
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      long long a = x[j]-x[i], b = y[j]-y[i];
      int cur = n;
      for (const auto &e: s) {
	if (s.count({e.first+a, e.second+b}))
	  --cur;
      }
      ans = min(ans, cur);
    }
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
