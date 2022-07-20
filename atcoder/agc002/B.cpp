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

bool ans[N];
int c[N];

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  ans[0] = 1;
  for (int i = 0; i < n; ++i) c[i] = 1;
  for (int i = 0; i < m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    --x; --y;
    if (ans[x]) ans[y] = 1;
    --c[x]; ++c[y];
    if (c[x] == 0) ans[x] = 0;
  }
  int anscnt = 0;
  for (int i = 0; i < n; ++i) if (ans[i]) ++anscnt;
  printf("%d", anscnt);
}

int main() {
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
