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
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

char a[N][N], bio[N][N];

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  int sx = -1, sy = -1;
  vector<pair<int, int>> g[30];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", a[i]+j);
      if (a[i][j] == 'S') sx = i, sy = j;
      if (a[i][j] >= 'a' && a[i][j] <= 'z') {
        g[a[i][j]-'a'].emplace_back(i, j);
      }
    }
  }
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  bio[sx][sy] = 1;
  pq.push({0, {sx, sy}});
  while (pq.size()) {
    const auto &e = pq.top();
    int d = e.first, x = e.second.first, y = e.second.second;
    if (a[x][y] == 'G') {
      printf("%d", d);
      return;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (bio[nx][ny]) continue;
      if (a[nx][ny] == '#') continue;
      pq.push({d+1, {nx, ny}});
      bio[nx][ny] = 1;
    }
    if (a[x][y] >= 'a' && a[x][y] <= 'z') {
      for (const auto &e: g[a[x][y]-'a']) {
        if (e.first == x && e.second == y) continue;
        if (bio[e.first][e.second]) continue;
        pq.push({d+1, e});
        bio[e.first][e.second] = 1;
      }
    }
    pq.pop();
  }
  printf("-1");
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
