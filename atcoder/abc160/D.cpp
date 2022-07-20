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

const int N = 2e3+34;

int s[N];

void solve() {
  int n, x, y; scanf("%d%d%d", &n, &x, &y);
  --x; --y;
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      int d = j-i; // 3
      if (j >= y && i <= x) {
	d -= y-x-1;
      } else if (i <= x && j <= y && j > x) {
	d = min(d, x-i+y-j+1); // 3, 1-0+3-3+1
      } else if (i >= x && i < y && j >= y) {
	d = min(d, i-x+j-y+1); // 2, 2-1+4-3+1
      } else if (i >= x && j <= y) {
	d = min(d, i-x+y-j+1);
      }
      ++s[d];
      //printf("(%d, %d) -> %d\n", i+1, j+1, d);
    }
  }
  for (int i = 1; i < n; ++i) {
    printf("%d\n", s[i]);
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
