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
char a[N][N];

const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

struct cell {
  int y, x, c;
};

queue<cell> q;

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", a[i]+j);
      if (a[i][j] == '#') q.push({i, j, 0});
    }
  }
  int ans = 0;
  while (!q.empty()) {
    const auto p = q.front(); q.pop();
    ans = max(ans, p.c);
    for (int i = 0; i < 4; ++i) {
      if (p.y+dy[i] < 0 || p.y+dy[i] >= h || p.x+dx[i] < 0 || p.x+dx[i] >= w) continue;
      //printf("%d %d\n", p.y+dy[i], p.x+dx[i]);
      if (a[p.y+dy[i]][p.x+dx[i]] == '#') continue;
      a[p.y+dy[i]][p.x+dx[i]] = '#';
      q.push({p.y+dy[i], p.x+dx[i], p.c+1});
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
