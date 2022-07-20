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

const int N = 1e2+23;

int x[N], y[N], h[N];

void solve() {
  int n; scanf("%d", &n);
  int remember = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", x+i, y+i, h+i);
    if (h[i]) remember = i;
  }
  for (int cx = 0; cx <= 100; ++cx) {
    for (int cy = 0; cy <= 100; ++cy) {
      int H = h[remember] + abs(x[remember]-cx) + abs(y[remember]-cy);
      bool good = true;
      for (int i = 0; i < n; ++i) {
	if (max(H - abs(x[i]-cx) - abs(y[i]-cy), 0) == h[i]) continue;
	good = false;
	break;
      }
      if (good) {
	printf("%d %d %d", cx, cy, H);
	return;
      }
    }
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
