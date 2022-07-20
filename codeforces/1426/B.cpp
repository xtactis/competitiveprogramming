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

const int N = 123;

int a[N][4];

bool solve() {
  int n, m; scanf(" %d %d", &n, &m);
  bool good = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j)
      scanf("%d", &a[i][j]);
    if (a[i][1] == a[i][2]) good = true;
  }
  if (m&1) return false;
  return good;
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    puts(solve()?"YES":"NO");
  }
  return 0;
}
