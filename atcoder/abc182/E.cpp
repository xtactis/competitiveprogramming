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

const int N = 1543;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int a[4][N][N];

void solve() {
  int h, w, n, m; scanf("%d%d%d%d", &h, &w, &n, &m);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    --x, --y;
    for (int j = 0; j < 4; ++j) a[j][x][y] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    --x, --y;
    for (int j = 0; j < 4; ++j) a[j][x][y] = -4000;
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i && a[0][i][j] == 0) a[0][i][j] += a[0][i-1][j];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (j && a[1][i][j] == 0) a[1][i][j] += a[1][i][j-1];
    }
  }
  for (int i = h-1; i >= 0; --i) {
    for (int j = 0; j < w; ++j) {
      if (a[2][i][j] == 0) a[2][i][j] += a[2][i+1][j];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = w-1; j >= 0; --j) {
      if (a[3][i][j] == 0) a[3][i][j] += a[3][i][j+1];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int x = 0;
      for (int k = 0; k < 4; ++k) x = max(x, a[k][i][j]);
      ans += x > 0;
    }
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
