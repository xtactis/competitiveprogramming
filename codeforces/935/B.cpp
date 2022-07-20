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

const int N = 1e5+23;

char a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", a+i);
  }
  int x = 0, y = 0, px = -1, py = -1, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (x && x == y) {
      if (a[i] == 'U' && py+1 == y) ++ans;
      else if (a[i] == 'R' && px+1 == x) ++ans;
    }
    px = x;
    py = y;
    if (a[i] == 'U') ++y;
    else ++x;
  }
  printf("%d", ans);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
