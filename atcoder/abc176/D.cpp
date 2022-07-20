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

const int N = 1e3+23;

int h, w;
int ch, cw, dh, dw;
int s, e;
char m[N][N];
int bio[N][N];
int bio2[N*N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int dx2[] = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2, -1, -1, 1, 1};
int dy2[] = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2, -1, 1, -1, 1};
set<int> g[N*N];

bool check(int x, int y) {
  return x >= 0 && x < h && y >= 0 && y < w;
}

void dfs(int x, int y, int c) {
  bio[x][y] = c;
  if (x == ch && y == cw) s = c;
  if (x == dh && y == dw) e = c;
  for (int i = 0; i < 4; ++i) {
    if (!check(x+dx[i], y+dy[i]) || bio[x+dx[i]][y+dy[i]]) continue;
    if (m[x+dx[i]][y+dy[i]] == '#') continue;
    dfs(x+dx[i], y+dy[i], c);
  }
}

void solve() {
  scanf("%d%d%d%d%d%d", &h, &w, &ch, &cw, &dh, &dw);
  --ch, --cw, --dh, --dw;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", m[i]+j);
    }
  }
  int color = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j] == '#') continue;
      if (bio[i][j]) continue;
      dfs(i, j, color++);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j] == '#') continue;
      for (int k = 0; k < sizeof(dx2)/sizeof(int); ++k) {
	if (!check(i+dx2[k], j+dy2[k])) continue;
	if (m[i+dx2[k]][j+dy2[k]] == '#') continue;
	if (bio[i][j] == bio[i+dx2[k]][j+dy2[k]]) continue;
	g[bio[i][j]].insert(bio[i+dx2[k]][j+dy2[k]]);
	g[bio[i+dx2[k]][j+dy2[k]]].insert(bio[i][j]);
      }
    }
  }
  queue<pair<int, int>> q;
  bio2[s] = 1;
  q.emplace(s, 0);
  while (!q.empty()) {
    int u = q.front().first, d = q.front().second; q.pop();
    if (e == u) {
      printf("%d", d);
      return;
    }
    for (int v: g[u]) {
      if (bio2[v]) continue;
      q.emplace(v, d+1);
      bio2[v] = 1;
    }
  }
  printf("-1");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
