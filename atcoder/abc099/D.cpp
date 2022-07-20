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

int d[32][32], C[3][32];

void solve() {
  int n, c; scanf("%d%d", &n, &c);
  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= c; ++j) {
      scanf("%d", d[i]+j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int x, j = 1; j <= n; ++j) {
      scanf("%d", &x);
      ++C[(i+j)%3][x];
    }
  }
  int ans = 2e9;
  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= c; ++j) {
      for (int k = 1; k <= c; ++k) {
	if (i == j || j == k || i == k) continue;
	int cur = 0;
	for (int col = 1; col <= c; ++col) {
	  cur +=
	      C[0][col]*d[col][i]
	    + C[1][col]*d[col][j]
	    + C[2][col]*d[col][k];
	}
	ans = min(ans, cur);
      }
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
