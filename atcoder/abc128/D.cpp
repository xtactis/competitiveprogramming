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
int n, k;
int a[N];

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  int ans = 0;
  for (int i = 0; i <= min(n, k); ++i) {
    for (int j = n-1; j >= max(i-1, n-(k-i)-1); --j) {
      set<pair<int, int>> s;
      for (int l = 0; l < n; ++l) {
	if (l >= i && l <= j) continue;
	s.emplace(a[l], l);
      }
      int bakk = k-s.size();
      int cur = 0;
      for (const auto &e: s) {
	if (e.first < 0 && bakk > 0) {
	  --bakk;
	  continue;
	}
	cur += e.first;
      }
      ans = max(ans, cur);
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
