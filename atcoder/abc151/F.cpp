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

inline long long sqr(long long x) {
  return x*x;
}

void solve() {
  int n; scanf("%d", &n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    v.emplace_back(x, y);
  }
  double ans = 10000000;
  for (int i = 0; i < n-2; ++i) {
    for (int j = i+1; j < n-1; ++j) {
      for (int k = j+1; k < n; ++k) {
	double r = 
      }
    }
  }
  assert(ans != 10000000);
  printf("%.8lf", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
