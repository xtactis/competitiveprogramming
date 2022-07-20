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
  if (n <= 2) printf("1\n");
  else printf("%d\n", (n-2+x-1)/x+1);
}

int main() {
  int t = 1; scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
