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

const int N = 2e3+23;
const int mod = 1e9+7;

char a[N][N];
long long dp[N][N][4];
const int dx[] = {0, -1, -1}, dy[] = {-1, 0, -1};

long long rek(int y, int x, int dir) {
  if (y == 1 && x == 1) return !dir;
  if (y < 1 || x < 1) return 0;
  if (a[y-1][x-1] == '#') return 0;
  long long &ret = dp[y][x][dir];
  if (ret != -1) return ret;
  ret = 0;
  if (!dir) {
    for (int i = 0; i < 3; ++i) {
      ret = (ret + rek(y+dy[i], x+dx[i], 0)) % mod;
      ret = (ret + rek(y+dy[i], x+dx[i], i+1)) % mod;
    }
  } else {
    --dir;
    ret = (ret + rek(y+dy[dir], x+dx[dir], 0)) % mod;
    ret = (ret + rek(y+dy[dir], x+dx[dir], dir+1)) % mod;
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", a[i]+j);
    }
  }
  printf("%lld", rek(h, w, 0));
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
