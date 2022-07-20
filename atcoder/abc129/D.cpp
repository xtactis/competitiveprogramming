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

char s[N][N];
int a[N][N], b[N][N];

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", s[i]+j);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      a[i][j] = 1;
      if (j) a[i][j] += a[i][j-1];
    }
    int m = 0;
    for (int j = w-1; j >= 0; --j) {
      if (s[i][j] == '#') {
	m = 0;
	continue;
      }
      if (m) {
	a[i][j] = m;
      } else {
	m = a[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (s[j][i] == '#') continue;
      b[j][i] = 1;
      if (j) b[j][i] += b[j-1][i];
    }
    int m = 0;
    for (int j = h-1; j >= 0; --j) {
      if (s[j][i] == '#') {
	m = 0;
	continue;
      }
      if (m) {
	b[j][i] = m;
      } else {
	m = b[j][i];
      }
      ans = max(ans, m+a[j][i]-1);
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
