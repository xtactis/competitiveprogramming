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

const int N = 10;
char c[N][N];

void solve() {
  int h, w, K; scanf("%d%d%d", &h, &w, &K);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", c[i]+j);
    }
  }
  int ans = 0;
  for (int i = 0; i < (1<<h); ++i) {
    for (int j = 0; j < (1<<w); ++j) {
      int cur = 0;
      for (int k = 0; k < h; ++k) {
	for (int l = 0; l < w; ++l) {
	  if ((i & (1<<k)) || (j & (1<<l))) continue;
	  if (c[k][l] == '#') ++cur;
	}
      }
      if (cur == K) ++ans;
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
