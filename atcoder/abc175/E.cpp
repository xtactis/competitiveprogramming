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

const int N = 3e3+23;

int a[N][N];
long long dp[N][N][4];

int r, c, k;

long long rek(int x, int y, int z) {
  if (x >= r || y >= c) return 0;
  long long &ret = dp[x][y][z];
  if (ret != -1) return ret;
  if (z) {
    ret = max({rek(x, y+1, z),
	       rek(x, y+1, z-!!a[x][y])+a[x][y],
	       rek(x+1, y, 3)+a[x][y]});
  }
  ret = max(ret, rek(x+1, y, 3));
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d", &r, &c, &k);
  for (int r, c, v, i = 0; i < k; ++i) {
    scanf("%d%d%d", &r, &c, &v);
    a[--r][--c] = v;
  }
  printf("%lld", rek(0, 0, 3));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
