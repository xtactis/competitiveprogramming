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

const int N = 323;

char a[N][N];
int ans[N][N];

void solve() {
  int h, w, k; scanf("%d%d%d", &h, &w, &k);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", a[i]+j);
      a[i][j] = a[i][j] == '#';
    }
  }
  int piece = 1;
  for (int i = 0; i < h; ++i) {
    bool first = true, empty = true;
    for (int j = 0; j < w; ++j) {
      if (a[i][j]) {
	empty = false;
	break;
      }
    }
    if (empty) continue;
    for (int j = 0; j < w; ++j) {
      if (a[i][j]) {
	if (first) {
	  first = false;
	  ans[i][j] = piece;
	} else {
	  ans[i][j] = ++piece;
	}
      } else {
	ans[i][j] = piece;
      }
    }
    ++piece;
  }
  for (int i = 0; i < h-1; ++i)
    for (int j = 0; j < w; ++j)
      if (!ans[i+1][j])
	ans[i+1][j] = ans[i][j];
  for (int i = h-1; i > 0; --i)
    for (int j = 0; j < w; ++j)
      if (!ans[i-1][j])
	ans[i-1][j] = ans[i][j];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      printf("%d ", ans[i][j]);
    }
    puts("");
  }   
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
