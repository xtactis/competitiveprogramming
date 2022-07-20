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

const int N = 23;

char s[N][N];
int d[N][N][N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      for (int k = 0; k < h; ++k)
	for (int l = 0; l < w; ++l)
	  d[i][j][k][l] = 1e3; // inf
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      scanf(" %c", &s[i][j]);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      d[i][j][i][j] = 0;
      for (int k = 0; k < 4; ++k)
	if (j+dx[k] >= 0 && j+dx[k] < w && i+dy[k] >= 0 && i+dy[k] < h && s[i+dy[k]][j+dx[k]] == '.')
	  d[i][j][i+dy[k]][j+dx[k]] = d[i+dy[k]][j+dx[k]][i][j] = 1;
    }
  for (int m = 0; m < h; ++m)
    for (int n = 0; n < w; ++n)
      for (int i = 0; i < h; ++i)
	for (int j = 0; j < w; ++j)
	  for (int k = 0; k < h; ++k)
	    for (int l = 0; l < w; ++l)
	      d[i][j][k][l] = min(d[i][j][k][l], d[i][j][m][n] + d[m][n][k][l]);
  int ans = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (s[i][j] == '.')
	for (int k = 0; k < h; ++k)
	  for (int l = 0; l < w; ++l)
	    if (s[k][l] == '.')
	      ans = max(ans, d[i][j][k][l]);
  printf("\n%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
