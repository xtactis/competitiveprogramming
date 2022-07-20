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
  int a[2][2] = {{}};
  for (int i = 1; i <= n; ++i) {
    char x; scanf(" %c", &x);
    ++a[i%2][(x-'0')%2];
  }
  if (n%2) {
    printf("%d\n", 2-!!a[1][1]);
  } else {
    printf("%d\n", 2-!a[0][0]);
  }
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
