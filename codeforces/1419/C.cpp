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
  int n, x; scanf("%d%d", &n, &x);
  int tot = 0, inf = 0;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a == x) ++inf;
    tot += x-a;
  }
  if (inf == n) {
    printf("0\n");
    return;
  }
  if (tot == 0) {
    printf("1\n");
    return;
  }
  if (inf > 0) printf("1\n");
  else printf("2\n");
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
