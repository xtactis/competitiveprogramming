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

const int N = 432;

char s[N][N];
bool bio[N][N];

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", s[i]+j);
    }
  }
  long long ans = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (bio[i][j]) continue;
      q.emplace(i, j);
      bio[i][j] = true;
      long long black = 0, white = 0;
      while (!q.empty()) {
	const auto &p = q.front();
	if (s[p.first][p.second] == '#') ++black;
	else ++white;
	for (int i = 0; i < 4; ++i) {
	  int y = p.first+dy[i], x = p.second+dx[i];
	  if (x < 0 || x >= w || y < 0 || y >= h) continue;
	  if (bio[y][x]) continue;
	  if (s[p.first][p.second] == s[y][x]) continue;
	  q.emplace(y, x);
	  bio[y][x] = true;
	}
	q.pop();
      }
      ans += black*white;
    }
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
