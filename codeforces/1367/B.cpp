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
  int n; scanf("%d", &n);
  int x[2] = {};
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a%2 != i%2) ++x[a%2];
  }
  if (x[0] != x[1]) {
    printf("-1\n");
    return;
  }
  printf("%d\n", x[0]);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
