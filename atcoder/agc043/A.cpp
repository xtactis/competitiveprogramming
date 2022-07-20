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

const int N = 123;

int a[N][N], b[N][N];

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c; scanf(" %c", &c);
      a[i][j] = c == '#';
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int u = 1e9, v = 1e9;
      b[i][j] = a[i][j];
      if (j) {
	u = b[i][j]+b[i][j-1];
	if (a[i][j] && a[i][j-1]) --u;
      }
      if (i) {
	v = b[i][j]+b[i-1][j];
	if (a[i][j] && a[i-1][j]) --v;
      }
      if (i || j) b[i][j] = min(u, v);
    }
  }
  printf("%d", b[h-1][w-1]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
