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

void solve() {
  int h, w, a, b; scanf("%d%d%d%d", &h, &w, &a, &b);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i < b && j < a) putchar('1');
      else if (i >= b && j >= a) putchar('1');
      else putchar('0');
    }
    putchar('\n');
  }
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
